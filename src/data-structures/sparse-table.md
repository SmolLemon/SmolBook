# Bảng thưa (Sparse Table)

Ta có bài toán sau:

> Cho một mảng `a` có \\(n\\) phần tử và \\(q\\) truy vấn có dạng `(l, r)`. Với mỗi truy vấn, tìm và in ra giá trị nhỏ nhất (GTNN) của các phần tử trong khoảng `[l, r]`.

Bài toán này có tên là **Range Minimum Query (RMQ)**, dịch tạm: Truy vấn tìm GTNN trên đoạn. Ta có thể giải bài toán này bằng cách duyệt các phần tử từ `l` tới `r` và in ra GTNN trong khoảng đó. Độ phức tạp của thuật toán này là \\(O(nq)\\). Tuy nhiên, ta có thể sử dụng một kĩ thuật giúp giải quyết bài toán này và các bài toán trên đoạn khác một cách tối ưu. Kĩ thuật này có tên gọi là kĩ thuật **bảng thưa**.

## Ý tưởng

Trước khi bàn về bảng thưa, ta cùng xét trường hợp nếu \\(n\\) nhỏ và \\(q\\) lớn, ví dụ: \\(n \le 1000, q \le 10^5\\). 

Ta có `f(i, j)` là một hàm trả về GTNN trong đoạn `[i, j]`, ta lưu tất cả các giá trị của `f(i, j)` vào một mảng hai chiều `F`, với `F[i][j] = f(i, j)`. Giờ đây, các truy vấn có thể được thực hiện trong \\(O(1)\\) bằng cách in ra `F[l][r]`. 

Thuật toán của ta giờ đây cần \\(O(n^2)\\) để tính các giá trị `f(i, j)`, và mỗi truy vấn có thể trả lời trong \\(O(1)\\).

Gọi bảng `F` này là **bảng dày**. Để **bảng dày** này trở thành **bảng thưa**, ta cần phải tự hỏi xem: liệu có lần phải lưu hết tất cả các giá trị trong bảng dày này hay không?

## Bảng thưa

### Trực quan

Giống như một số nguyên có thể được biểu diễn bằng tổng của các lũy thừa của 2:

\\[21 = 10101_2 = 2^4 + 2^2 + 2^0\\]

Các đoạn `[l, r]` có thể được biểu diễn bằng hợp của các đoạn có độ dài là lũy thừa của 2:

\\[[7, 21] = [7, 7 + 2^3) \cup [15, 15 + 2^2) \cup [19, 19 + 2^1) \cup [21, 21 + 2^0)\\]

Tương đương:

\\[[7, 21] = [7, 15) \cup [15, 19) \cup [19, 21) \cup [21, 22)\\]

Với các đoạn `[7, 15)`, `[15, 19)`, `[19, 21)`, `[21, 22)` có kích thước lần lượt là 8, 4, 2, 1.

Từ đây, ta có ý tưởng xây dựng bảng thưa: Thay vì lưu trữ toàn bộ các GTNN của các đoạn, ta chỉ cần lưu giá trị của các đoạn có độ dài bằng các lũy thừa của 2.

### Xây dựng bảng thưa

Để xây dựng bảng thưa, ta có mảng 2 chiều `sp`. `sp[k][i]` sẽ bằng GTNN của các phần tử trong khoảng \\([i, i + 2^k)\\). 

Ví dụ: 
- `sp[0][3] = min(a[3]) = a[3]`.
- `sp[1][3] = min(a[3], a[4])`.
- `sp[2][3] = min(a[3], a[4], a[5], a[6])`.
- ...
- `sp[k][3] = min(a[3], a[4], ..., a[3 + 2^k - 2], a[3 + 2^k - 1])`.

Nhận xét: số phần tử của `sp` sẽ không quá \\(O(n\log{n})\\). Nếu các phần tử được tính trong \\(O(1)\\) thì việc tạo mảng `sp` sẽ có độ phức tạp \\(O(n\log{n})\\).

Ta có công thức tính `sp[i][k]` như sau: 
- \\(sp[0][i] = a[i]\\)
- \\(sp[k][i] = min(sp[k - 1][i], sp[k - 1][i + 2 ^ {k - 1}])\\)

Ta ví dụ với mảng `a` có 12 phần tử: `a = [1, 4, 2, 3, 7, 2, 6, 3, 5, 8, 9, 0]`

|`k \ i`|1|2|3|4|5|6|7|8|9|10|11|12|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**0**|1|4|2|3|7|2|6|3|5|8|9|0|
|**1**|1|2|2|3|2|2|3|3|5|8|0|**X**|
|**2**|1|2|2|2|2|2|3|3|0|**X**|**X**|**X**|
|**3**|1|2|2|2|0|**X**|**X**|**X**|**X**|**X**|**X**|**X**|

Vì sao lại có một số phần tử lại không được tính? Ví dụ với phần tử `(10, 2)` lưu GTNN trong khoảng `[10, 13]`, nhưng khoảng này lại tràn ra ngoài bảng thưa (mảng nằm trong khoảng `[1, 12]` nhưng lại tính GTNN của khoảng `[10, 13]`) nên ta không cần (nói đúng hơn là *không thể*) tính được, vì thế ta bỏ qua việc tính GTNN tại vị trí này trong bảng.

```C++
void BuildSparseTable(){
	for(int i = 1; i <= n; ++i){
		sp[0][i] = a[i];
	}
	for(int k = 1; (1 << k) <= n; ++k){
		for(int i = 1; i + (1 << k) - 1 <= n; ++i){
			sp[k][i] = min(sp[k - 1][i], sp[k - 1][i + (1 << (k - 1))]);
		}
	}
}
```

### Xử lý truy vấn

Đối với các hàm có tính chất [kết hợp](https://vi.wikipedia.org/wiki/T%C3%ADnh_k%E1%BA%BFt_h%E1%BB%A3p), hay các hàm có tính chất \\(f(f(x, y), z) = f(x, f(y, z))\\), các truy vấn có thể được xử lý trong \\(O(\log{n})\\).

Ta sẽ chia đoạn `[l, r]` thành các phân đoạn có độ dài bằng các lũy thừa của 2 và tìm GTNN của các phân đoạn:

VD: Truy vấn `[8, 17]` có GTNN bằng `min(sp[3][8], sp[1][16])`.

Ta có thể tìm nhanh vị trí của giá trị bit lớn nhất của một số x trong C++ bằng cách sử dụng hàm `__lg(x)`.

```C++
int RMQ(int l, int r){
	int mn = INT_MAX;
	while(l <= r){
		int lg = __lg(r - l + 1);
		mn = min(mn, sp[lg][l]);
		l = l + (1 << lg);
	}
	return mn;
}
```

Đối với các hàm cho phép *trùng lặp* các phần tử, hay các hàm thỏa mãn \\(f(a, a) = a\\), ta có thể thực hiện việc tính kết quả trong \\(O(1)\\)..

Ta thực hiện việc tìm GTNN như sau:
- Gọi `k` là số nguyên lớn nhất sao cho \\(2^k \le r - l + 1\\), GTNN của đoạn `(l, r)` bằng:

\\[min(l, r) = min(sp[k][l], sp[k][r - 2 ^ {k} + 1])\\]

```C++
int RMQ(int l, int r){
	int lg = __lg(r - l + 1);
	return min(sp[lg][l], sp[lg][r - (1 << lg) + 1]);
}
```

## Ứng dụng

Bảng thưa thường được dùng để tìm các giá trị trong một khoảng một cách nhanh chóng. Các giá trị như tổng, tích, giá trị nhỏ/lớn nhất, gcd, lcm,... Những giá trị còn được dùng để giải quyết các bài toán lớn hơn, ví dụ như: [tìm LCA trong \\(O(1)\\)](../graph-theory/lca-rmq.md), [nâng nhị phân](../graph-theory/binary-lifting.md),...

Một lưu ý nhỏ là bảng thưa chỉ có thể được sử dụng trên mảng tĩnh, tức các giá trị trên mảng không thay đổi. 