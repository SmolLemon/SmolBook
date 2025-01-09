# Kĩ thuật hai con trỏ

Kĩ thuật hai con trỏ là kĩ thuật sử dụng hai con trỏ để thực hiện việc duyệt các phần tử trong mảng.

Nghe thì đơn giản nhưng đây lại là một kĩ thuật rất hữu ích với nhiều ứng dụng khác nhau. Hãy cùng tim hiểu một số ứng dụng của kĩ thuật hai con trỏ qua một số bài toán.

## Gộp mảng

> Cho \\(2\\) mảng `a` và `b` được sắp xếp tăng dần. In ra một mảng `c` gồm các phần tử của \\(2\\) mảng kia được sắp xếp theo thứ tự tăng dần.

Cách dễ nhất để thực hiện bài toán này là một thuật toán gồm các bước như sau:
- Gộp tất cả các phần tử trong \\(2\\) mảng vào một mảng mới
- Sắp xếp mảng mới này 

Thuật toán này đơn giản và có độ phức tạp là \\(O(n \log{n})\\).

Tuy nhiên, xét đến việc các phần tử trong \\(2\\) mảng đã được sắp xếp tăng dần, ta có thể sử dụng kĩ thuật \\(2\\) con trỏ để tạo mảng `c` với độ phức tạp nhỏ hơn.

Chương trình của ta có các bước như sau: 
- Khi hai phần tử đều không rỗng, tìm phần tử nhỏ nhất của \\(2\\) mảng `a` và `b`. Nếu phần tử nhỏ nhất của `a` nhỏ hơn của `b` thì thêm phần tử đấy vào mảng `c` là loại bỏ phần tử ấy khỏi a, nếu không thì ngược lại. 
- Tiếp tục thực hiện bước trên cho tới khi một trong hai mảng rỗng. Khi đấy ta thêm các phần tử còn lại của mảng còn lại vào mảng `c`. 

Ta có ví dụ sau:

\\[a = [1, 3, 4]\\]
\\[b = [2, 5, 6]\\]

Vì mảng `a` đã được sắp xếp tăng dần nên phần tử đầu tiên của mảng `a` là phần tử nhỏ nhất, mảng `b` cũng tương tự. \\(1\\) và \\(2\\) là phần tử nhỏ nhất của \\(2\\) mảng. Vì \\(1\\) là phần tử nhỏ hơn nên ta thêm \\(1\\) vào mảng `c` và loại bỏ \\(1\\) khỏi mảng `a`.

\\[a = [\color{red}{\not{1}}, 3, 4]\\]
\\[b = [2, 5, 6]\\]
\\[c = [1]\\]

Vì \\(1\\) đã được xóa bỏ nên ta xét phần tử nhỏ nhất tiếp theo của mảng a là \\(3\\).

Vì \\(2\\) là phần tử nhỏ hơn nên ta tiếp tục thuật toán:

\\[a = [\color{red}{\not{1}}, 3, 4]\\]
\\[b = [\color{red}{\not{2}}, 5, 6]\\]
\\[c = [1, 2]\\]

Và ta tiếp tục thuật toán cho tới khi cả \\(2\\) mảng đều rỗng.

Để thực hiện thuật toán này, ta sử dụng kĩ thuật hai con trỏ. Ta tạo \\(2\\) con trỏ \\(i\\) và \\(j\\) cho \\(2\\) mảng `a` và `b`. \\(2\\) con trỏ này sẽ trỏ vào vị trí phần tử đầu tiên của \\(2\\) mảng. 

Mỗi lần một con trỏ trỏ đến phần tử được chọn, con trỏ đấy sẽ di chuyển đến vị trí tiếp theo trong mảng.

\\[a = [\color{red}{\not{1}}, \overset{\underset{\downarrow}{i}}{3}, 4]\\]
\\[b = [\underset{\overset{\uparrow}{j}}{2}, 5, 6]\\]

Ta có \\(n\\), \\(m\\) lần lượt là kích thước của mảng `a` và `b`, phần tử đầu tiên của \\(2\\) mảng có chỉ số \\(1\\). Mảng nào có con trỏ trỏ ra ngoài mảng thì ta sẽ thêm các phần tử còn lại của mảng kia vào mảng `c`.

```C++
while(i <= n || j <= m){
	if(j > m || (i <= n && a[i] < b[j])){
		c[i + j] = a[i];
		++i;
	}else{
		c[i + j] = b[j];
		++j;
	}
}
```

Độ phức tạp thuật toán sẽ là \\(O(n + m)\\).

## Bài toán 2SUM

Bài toán 2SUM được phát biểu như sau:

> Cho một mảng \\(n\\) phần tử và một số \\(x\\). Tìm cặp số có tổng giá trị bằng \\(x\\) hoặc thông báo rằng cặp số ấy không tồn tại.

Để giải bài toán này, ta sẽ sắp xếp các phần tử trong mảng và đặt \\(2\\) con trỏ ở hai vị trí đầu và cuối mảng. Nếu tổng của các phần tử được \\(2\\) con trỏ trỏ tới có tổng lớn hơn \\(x\\), ta dịch con trỏ ở cuối mảng sang trái, nếu nhỏ hơn thì dịch con trỏ ở đầu mảng sang phải. Tiếp tục thực hiện cho tới khi tìm được cặp số thỏa mãn, hoặc khi không thể duyệt được nữa. 

Ta ví dụ bằng mảng sau và một số \\(x = 11\\):

\\[[1, 2, 3, 5, 8, 9, 12, 15]\\]

Ta để hai con trỏ ở vị trí ban đầu.

\\[[\overset{\underset{\downarrow}{i}}{\color{red}{1}}, 2, 3, 5, 8, 9, 12, \overset{\underset{\downarrow}{j}}{\color{red}{15}}]\\]

Dễ thấy, \\(1 + 15 = 16 \gt 11\\). Vì vậy, ta dịch con trỏ \\(j\\) sang trái.

\\[[\overset{\underset{\downarrow}{i}}{\color{red}{1}}, 2, 3, 5, 8, 9, \overset{\underset{\downarrow}{j}}{\color{red}{12}}, 15]\\]

\\(1 + 12 = 13 \gt 11\\), tiếp tục dịch con trỏ \\(j\\) sang trái.

\\[[\overset{\underset{\downarrow}{i}}{\color{red}{1}}, 2, 3, 5, 8, \overset{\underset{\downarrow}{j}}{\color{red}{9}}, 12, 15]\\]

\\(1 + 9 = 10 \lt 11\\), khi này dịch con trỏ \\(i\\) sang phải.

\\[[1, \overset{\underset{\downarrow}{i}}{\color{red}{2}}, 3, 5, 8, \overset{\underset{\downarrow}{j}}{\color{red}{9}}, 12, 15]\\]

Khi này, \\(2 + 9 = 11 \\), mảng tồn tại cặp số có tổng bằng \\(x\\).

Độ phức tạp của thuật toán là \\(O(n \log{n})\\)

## Tổng mảng con

Bài toán được phát biểu như sau:

> Cho một mảng \\(n\\) phần tử nguyên dương và một số \\(x\\). Tìm mảng con có tổng giá trị bằng \\(x\\) hoặc thông báo rằng mảng con ấy không tồn tại.

Cách giải bài toán này gần giống với bài toán 2SUM ở trên: 

Ta có \\(SUM(l, r)\\) là tổng giá trị các phần tử \\(a_l, a_{l + 1},..., a_{r - 1}, a_{r}\\).

Hai con trỏ \\(i\\) và \\(j\\) của ta sẽ được đặt tại vị trí đầu mảng.

Nếu \\(SUM(i, j) < x\\), dịch \\(j\\) sang phải. Nếu \\(SUM(i, j) > x\\), dịch \\(i\\) sang phải. Nếu \\(SUM(i, j) = x\\), đã tìm được mảng con có tổng bằng \\(x\\).

Ta ví dụ bằng mảng sau và một số \\(x = 11\\):

\\[[1, 4, 2, 6, 3, 7, 5]\\]

| Nhận xét | Thao tác | Sau thao tác |
|---|---|---|
|| Đặt \\(i\\), \\(j\\) ở vị trí 1. |\\([\overset{\underset{\downarrow}{i, j}}{\color{red}{1}}, 4, 2, 6, 3, 7, 5]\\)|
|\\(SUM(1, 1) = 1 < 11\\) | Dịch \\(j\\) sang phải.|\\([\overset{\underset{\downarrow}{i}}{\color{red}{1}}, \overset{\underset{\downarrow}{j}}{\color{red}{4}}, 2, 6, 3, 7, 5]\\)|
|\\(SUM(1, 2) = 5 < 11\\) | Dịch \\(j\\) sang phải.|\\([\overset{\underset{\downarrow}{i}}{\color{red}{1}}, \color{red}{4}, \overset{\underset{\downarrow}{j}}{\color{red}{2}}, 6, 3, 7, 5]\\)|
|\\(SUM(1, 3) = 7 < 11\\) | Dịch \\(j\\) sang phải.|\\([\overset{\underset{\downarrow}{i}}{\color{red}{1}}, \color{red}{4}, \color{red}{2}, \overset{\underset{\downarrow}{j}}{\color{red}{6}}, 3, 7, 5]\\)|
|\\(SUM(1, 4) = 13 > 11\\) | Dịch \\(i\\) sang phải.|\\([1, \overset{\underset{\downarrow}{i}}{\color{red}{4}}, \color{red}{2}, \overset{\underset{\downarrow}{j}}{\color{red}{6}}, 3, 7, 5]\\)|
|\\(SUM(2, 4) = 12 > 11\\) | Dịch \\(i\\) sang phải.|\\([1, 4, \overset{\underset{\downarrow}{i}}{\color{red}{2}}, \overset{\underset{\downarrow}{j}}{\color{red}{6}}, 3, 7, 5]\\)|
|\\(SUM(3, 4) = 8 < 11\\) | Dịch \\(j\\) sang phải.|\\([1, 4, \overset{\underset{\downarrow}{i}}{\color{red}{2}}, \color{red}{6}, \overset{\underset{\downarrow}{j}}{\color{red}{3}}, 7, 5]\\)|
|\\(SUM(3, 5) = 11\\)| Tồn tại mảng con có tổng bằng \\(x\\), kết thúc thuật toán.||