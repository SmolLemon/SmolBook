# Disjoint Set Union

## Định nghĩa

Cấu trúc dữ liệu **Disjoint Sets Union (DSU)** hay với tên gọi khác là **Union-Find Disjoint Sets (UFDS)** là một cấu trúc dữ liệu quản lí các tập hợp không giao nhau, tức là các tập hợp không có phần tử chung. Cấu trúc dữ liệu này có thể trả lời *hiệu quả* nếu 2 phần tử có nằm trong cùng một tập hợp hay không, hoặc hợp 2 tập hợp lại với nhau.

Như tên gọi của mình, DSU bao gồm các thao tác chính:
- **MakeSet**: Tạo một tập hợp có 1 phần tử là a.
- **Union**: Hợp tập hợp chứa phần tử a và tập hợp chứa phần tử b thành một tập hợp, và
- **Find**: Tìm phần tử đại diện của tập hợp chứa phần tử a.

Mỗi tập hợp sẽ có một phần tử làm phần tử *đại diện*, dùng để xác định tập hợp mà nó nằm trong. Đây cũng là giá trị trả về của thao tác **Find**.

Để kiểm tra nếu 2 phần tử có nằm trong cùng một tập hợp không thì ta kiểm tra nếu `Find(a) = Find(b)` hay nếu tập hợp chứa a và tập hợp chứa b đều có cùng một phần tử đại diện.

## Cài đặt

Để cài đặt DSU, ta có mảng `p` có n phần tử dùng để lưu các phần tử đại diện của tập hợp - ví dụ: `p[i]` lưu phần tử đại diện của tập hợp chứa `i`.

Ta có cài đặt DSU bằng Quick-Find:

```C++
int MakeSet(int a){
	if(p[a] == -1){ // -1 biểu thị nếu tập hợp chưa được tạo
		p[a] = a;
	}
}
int Find(int a){
	return p[a];
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	for(int i = 1; i <= n; ++i){
		if(p[i] == a){
			p[i] = b;
		}
	}
}
```

`MakeSet(a)` và `Find(a)` có độ phức tạp \\(O(1)\\), còn `Union(a, b)` là \\(O(n)\\). 

Như ta có thể thấy, hàm `Union` có độ phức tạp thời gian quá lớn. Tuy nhiên, ta cũng có nhiều cách để tối ưu nó.

## Tối ưu DSU

### Quick-Union

Ta sẽ tối ưu hàm Union bằng cách mô tả các tập hợp bằng các đồ thị cây hay *rừng cây*. `p[i]` giờ đây sẽ chỉ cha của đỉnh `i` trong đồ thị cây. Khi thực hiện `Union(a, b)` ta chỉ cần thay đổi cha của gốc của cây chứa a thành gốc của cây chứa của b hay `p[Find(a)] = Find(b)`. Và khi thực hiện `Find(a)` ta tìm gốc của cây bằng cách xét dãy `a`, `p[a]`, `p[p[a]]`, ... cho tới khi tìm tìm được phần tử trong dãy có giá trị giống phần tử trước nó, tức là ta đã tìm được gốc của cây. 

|Thao tác|Minh họa|
|---|---|
|Ban đầu|<center><img src="../images/dsu1.svg" alt="Ban đầu"/></center>|
|`Union(1, 2)`|<center><img src="../images/dsu2.svg" alt="Union(1, 2)"/></center>|
|`Union(2, 3)`|<center><img src="../images/dsu3.svg" alt="Union(2, 3)"/></center>|
|`Union(1, 4)`|<center><img src="../images/dsu4.svg" alt="Union(1, 4)"/></center>|
```C++
int Find(int a){
	while(a != p[a]){
		a = p[a];
	}
	return a;
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	p[a] = b;
}
```

Lúc này độ phức tạp của `Find` là \\(O(n)\\) và `Union` là \\(O(n)\\). 

Vì sao `Find` lại là \\(O(n)\\)? Giả sử việc `Union` sẽ tạo thành một cây được nối thành một đường thẳng. Khi đó việc `Find` sẽ có độ phức tạp \\(O(n)\\). Và cũng vì trong `Union` có sử dụng `Find` nên độ phức tạp của `Union` cũng là \\(O(n)\\).

Tuy vậy, cách thực hiện `Union` của Quick-Union vẫn nhanh hơn `Union` của Quick-Find. `Union` của Quick-Find thì duyệt các phần tử trong `p`, còn `Union` của Quick-Union thì phụ thuộc vào chiều cao của cây. Trên trung bình, các cây được tạo bởi Quick-Union có độ cao khá bé nên nó nhanh hơn Quick-Find. 

### Tối ưu Union 

Như đã nói ở trên, trên trung bình, các cây có độ cao tương đối nhỏ. Dẫu vậy, làm cách nào để ta đảm bảo được chiều cao của các cây ấy đều nhỏ trong mọi trường hợp? Ta sẽ thay đổi cách thực hiện hàm Union.

#### Union theo thứ hạng

Ta có Union theo thứ hạng: Khi Union tập hợp chứa a và tâp hợp chứa b, cây nào có thứ hạng cao hơn sẽ là cha của cây có thứ hạng thấp hơn, nếu 2 cây có thứ hạng bằng nhau thì gốc của đỉnh nào làm cha cũng được, nhưng thứ hạng của cây có đỉnh được chọn phải tăng thêm 1.

Ta sẽ tạo một mảng `r` lưu thứ hạng của tập hợp chứa đỉnh i. Ban đầu, các giá trị trong `r` sẽ bằng 0.

Hàm `Find` sẽ tương tự với Find trong Quick-Union.

```C++
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	if(r[a] < r[b]) swap(a, b);
	p[b] = a;
	if(r[a] == r[b]) ++r[a];
}
```

Ta có giả thiết: Một cây có thứ hạng \\(k\\) sẽ có ít nhất \\(2^{k}\\) đỉnh. 

> Chứng minh: Nếu \\(k\\) bằng 0, thì điều này là chính xác vì khi cây có thứ hạng bằng 0 thì chỉ có 1 đỉnh. Ta cũng nhận thấy rằng để có cây có thứ hạng \\(k\\) thì nó phải được Union theo thứ hạng từ 2 cây có thứ hạng \\(k - 1\\), khi đó số đỉnh trong cây có thứ hạng \\(k\\) sẽ lớn hơn hoặc bằng \\(2^{k - 1} + 2^{k - 1} = 2^k\\).

Từ đây ta có thể nhận định rằng thứ hạng cao nhất có thể khi liên tiếp thực hiện Union theo thứ hạng n phần tử là \\(\log{n}\\).

#### Union theo kích thước

Ta có Union theo kích thước: Khi Union tập hợp chứa a và tâp hợp chứa b, cây có nhiều đỉnh hơn sẽ là cha của gốc của cây có ít đỉnh hơn, nếu 2 cây có số lượng đỉnh bằng nhau thì lấy cây nào làm cha cũng được.

Ta sẽ tạo một mảng `sz` lưu kích thước của tập hợp chứa đỉnh `i`. Ban đầu, các giá trị trong `sz` sẽ bằng 1.

Hàm `Find` sẽ tương tự với Find trong Quick-Union.

```C++
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
}
```

Tương tự với Union theo thứ hạng, ta có giả thiết: Một đỉnh \\(x\\) bất kì sẽ không có chiều cao quá \\(\log{n}\\).

> Chứng minh: Chiều cao của đỉnh \\(x\\) nằm trong cây \\(T_1\\) sẽ không thay đổi trừ khi được hợp lại với cây \\(T_2\\) có kích thước lớn hơn \\(T_1\\).
>
> Khi này:
>	- Chiều cao của \\(x\\) tăng lên 1
>	- Kích thước của cây mới \\(T_3\\) chứa đỉnh \\(x\\) sẽ gấp đôi cây cũ hoặc hơn: 
> \\[size(T_3) = size(T_1) + size(T_2) \ge 2 \times size(T_1)\\]

Giống với Union theo thứ hạng, ta có thể nhận định rằng chiều cao lớn nhất có thể khi liên tiếp Union theo thứ hạng n phần tử là \\(\log{n}\\).

<br>

Bằng việc áp dụng Quick-Union với Union theo kích thước/thứ hạng, ta có thể đảm bảo rằng chiều cao của cây sẽ không vượt quá \\(\log{n}\\) và độ phức tạp cho `Find` và `Union` sẽ giảm xuống còn \\(O(\log{n})\\).

### Tối ưu Find

Việc áp dụng cách cài đặt Quick-Union đã làm gia tăng độ phức tạp của hàm `Find`, nhưng không vì thế mà ta không có cách tối ưu nó.

#### Kĩ thuật nén đường đi

Kĩ thuật nén đường đi rất đơn giản: Khi đã tìm được gốc của cây bằng dãy `a`, `p[a]`, `p[p[a]]`,... như ở phần Quick-Union, gán cha của tất cả các phần tử trong dãy đó thành gốc đã tìm được. 

```C++
int Find(int a){
	if(a != p[a]) p[a] = Find(p[a]);
	return p[a];
}
```

Hàm `Find` này chạy rất nhanh, với độ phức tạp \\(O(\log^* n)\\) trên trung bình nếu kết hợp với Union theo thứ hạng/kích thước hoặc \\(O(\log{n})\\) nếu sử dụng đơn lẻ. 

\\(\log^* n\\) hay logarit lặp là số lần áp dụng hàm \\(\log_2\\) với chính nó cho tới khi giá trị đạt được không lớn hơn 1.

VD: \\(65536 = 2^{16} \rightarrow 16 = 2^4 \rightarrow 4 = 2^2 \rightarrow 2 \rightarrow 1 \implies log^* 65536 = 4\\)

Vì trong hầu hết các trường hợp, \\(\log^* n\\) rất nhỏ nên ta coi nó như \\(O(1)\\).

### Tổng hợp các cách cài đặt DSU

Bảng dưới đây so sánh độ phức tạp thời gian của 2 hàm `Find` và `Union` của các cách cài đặt DSU được nói ở trên:

|Tên gọi|`Find`|`Union`|
|---|---|---|
|Quick-Find|\\(O(1)\\)|\\(O(n)\\)|
|Quick-Union|\\(O(n)\\)|\\(O(n)\\)|
|Quick-Union theo kích thước/thứ hạng|\\(O(\log{n})\\)|\\(O(\log{n})\\)|
|Quick-Union + nén đường đi|\\(O(\log{n})\\)|\\(O(\log{n})\\)|
|Quick-Union theo kích thước/thứ hạng + nén đường đi|\\(O(log^* n)\\)|\\(O(log^* n)\\)|