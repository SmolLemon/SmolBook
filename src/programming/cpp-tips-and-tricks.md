# Mẹo lập trình thi đấu C++

Dưới đây là một số mẹo cho C++ trong lập trình thi đấu.

## Fast I/O

Trong hầu hết các bài nộp C++, ta thường bắt gặp 2 dòng lệnh phổ biến ở đầu hàm `main`:

```C++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

2 câu lệnh này giúp tăng tốc chương trình bằng cách thay đổi cách nhập xuất của nó.

- `ios_base::sync_with_stdio(false)` tắt đồng bộ giữa cách nhập xuất của C và C++. Tính năng này giúp ta có thể sử dụng linh hoạt giữa hai cách nhập xuất khác nhau. Khi tắt tính năng này, chương trình của ta sẽ chạy nhanh hơn nếu bài toán yêu cầu nhập xuất dữ liệu nhiều lần. Lưu ý rằng nếu tắt đồng bộ thì không nên sử dụng lẫn lộn 2 cách nhập xuất.
- `cin.tie(NULL)` tắt  đồng bộ giữa `cin` và `cout`. `tie()` được dùng để đảm bảo tất cả các dữ liệu của `cout` sẽ được xuất ra màn hình trước khi thực hiện `cin` nhập dữ liệu. Điều này sẽ giúp ích cho các chương trình cần tương tác nhiều, nhưng cũng vì thế mà chương trình của ta sẽ chạy chậm đi. Ta tắt tính năng này để gia tăng tốc độ chương trình.

## Sử dụng `'\n'` thay thế cho `endl`

Trong lập trình thi đấu, sẽ tốt hơn nếu ta sử dụng `'\n'` để xuống dòng thay vì sử dụng `endl`.

Ta có thể hiểu `endl` giống như khi ta viết `'\n' << flush`.

`flush` là thao tác đẩy dữ liệu từ bộ đệm đầu ra (output buffer) ra thiết bị đầu ra. Nói cách khác, nó đảm bảo rằng tất cả dữ liệu đang chờ trong bộ đệm được ghi ngay lập tức.

Khi `flush` thường xuyên sẽ giảm hiệu suất của ta, việc dùng`'\n'` để xuống dòng trong các chương trình sẽ cho ta tốc độ chạy code nhanh hơn so với việc sử dụng `endl`.

## Rút gọn code

### Type name

Ta có thể dùng `typedef` để rút gọn chương trình của ta.

VD:

```c++
typedef long long ll;
```
Sẽ giúp làm ngắn code:
```c++
long long a = 123456;
long long b = 246802;
cout << a + b << "\n";
```
thành:

```c++
ll a = 123456;
ll b = 246802;
cout << a + b << "\n";
```

### Macros

Macro thay đổi kí tự hoặc xâu kí tự trong mã (code) khi biên dịch chương trình.

Trong C++ macro được định nghĩa bằng `#define {Tên_macro} {macro}`

VD: 

```c++
#define ll long long // macro cho kiểu dữ liệu
#define PI 3.14159 // macro cho một số
#define REP(i, a, b) for (int i = a; i <= b; ++i) //Macro cho một câu lệnh lặp
```

### Xuống dòng

Dưới đây là một đoạn của một chương trình in ra các giá trị của một mảng 2 chiều kích thước `n * m`:

```C++
for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
		cout << a[i][j] << ' ';
	}
	cout << '\n';
}
```

Thay vì phải in thêm một câu lệnh cout sau mỗi lần in xong một hàng, ta có cách viết khác:

```C++
for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= m; ++j) {
		cout << a[i][j] << "\n "[j < m];
	}
}
```

Dòng lệnh này có ý nghĩa: `"\n "` là một xâu kí tự, trong khi ta chưa duyệt đến phần tử cuối cùng, điều kiện `j < m` thỏa mãn, chương trình in ra kí tự vị trí 1 của xâu: `' '` - dấu cách. Khi đã duyệt đến phần tử cuối cùng, điều kiện `j < m` không thỏa mãn, chương trình in ra kí tự vị trí 0 của xâu: `'\n'` - xuống dòng.

## Viết số lớn

Sẽ có nhiều bài yêu cầu ta phải tạo một mảng lớn (như \\(10^6\\) chẳng hạn), nhiều người có thể sẽ viết một mảng `a` và số \\(10^6\\) cộng thêm một số nhỏ: `a[1000010]`. Kiểu viết này tuy không sai nhưng rất dễ xảy ra lỗi, nhất là khi viết đi viết lại số `1000010`.

Ta tạo một hằng số `N` tượng trưng cho kích thước của mảng. Ta cho `N = 1e6 + 10` với giá trị bằng `1000000`, vừa dễ nhìn vừa khó mắc lỗi.

```C++
const int N = 1e6 + 10;
int a[N];
```

Chữ `e` (hoặc `E`) trong đoạn code là [E notation](https://en.wikipedia.org/wiki/Scientific_notation#E_notation). Khi viết \\(mEn\\) sẽ có giá trị: \\(m \times n^E\\).

VD: 
- `1e6 = 10^6 = 1000000`
- `2e5 = 2 * 10^5 = 200000`

## Câu lệnh rẽ nhánh trong một dòng

Có những lần bạn phải gán giá trị theo từng trường hợp:

```C++
\\ tìm số lớn nhất trong hai số
int a, b;
int ans;
if(a < b) ans = b;
else ans = a;
```

Ta có thể rút gọn lại thành:

```C++
int a, b;
int ans = a < b ? b : a;
```
