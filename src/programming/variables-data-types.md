# Biến và kiểu dữ liệu

## Biến

Các biến có thể được sử dụng để thực hiện các thao tác trong lập trình hoặc giải quyết các công thức giống như trong toán học. Tuy nhiên, khác với toán, ta không thể viết các biến một cách tuỳ ý.

Để khai báo một biến trong C++, ta xác định và gán các biến vào các kiểu dữ liệu phù hợp.

Giả sử ta muốn khai báo một biến số nguyên \\(x = 5\\), ta có thể viết:

```C++
int x = 5;
```   

Sau khi khai báo \\(x\\), ta có thể gán cho \\(x\\) các giá trị khác:

```C++
int x = 5;
int y = 6; // một biến khác
x = y;
x = 2025;
x = 20 * 3 + 4 - 1;
```

Nếu ta muốn \\(x\\) không thay đổi khi chạy chương trình, ta có thể khai báo \\(x\\) là một hằng số.

```C++
const int x = 5;
```

Ta có thể khai báo \\(x\\) theo cách khác:

```C++
int x(5); // cách 1
int x{5}; // cách 2
```

Ta cũng có thể khai báo \\(x\\) mà không gán giá trị cho nó.

```C++
int x;
```

Nếu như ta khai báo các biến ở ngoài hàm main, các *biến toàn cục (global variable)* nếu không gán giá trị sẽ có giá trị bằng \\(0\\), còn nếu ta khai báo trong các hàm, các *biến cục bộ (local variable)* sẽ có giá trị ngẫu nhiên.

## Kiểu dữ liệu

Ở C++ và các ngôn ngữ lập trình khác, ta có các kiểu dữ liệu cơ bản sau:

|Kiểu dữ liệu|Loại dữ liệu|Kích cỡ (bytes)|Khoảng giá trị|
|---|---|---|---|
|`int`|Số nguyên \\(32\\) bit|\\(4\\)|\\(-2^{31}\\) đến \\(2^{31} - 1 \\)|
|`short int`|Số nguyên \\(16\\) bit|\\(2\\)|\\(-2^{15}\\) đến \\(2^{15} - 1 \\)|
|`long long`|Số nguyên \\(64\\) bit|\\(8\\)|\\(-2^{63}\\) đến \\(2^{63} - 1 \\)|
|`float`|Số thực độ chính xác đơn|\\(4\\)|\\(\approx -3.4 \times 10^{38}\\) đến \\(\approx 3.4 \times 10^{38}\\)|
|`double`|Số thực độ chính xác kép|\\(8\\)|\\(\approx -1.7 \times 10^{308}\\) đến \\(\approx 1.7 \times 10^{308}\\)||`bool`|Giá trị đúng/sai|1|`true` hoặc `false` (0 hoặc 1)|
|`char`|Kí tự|\\(1\\)|\\(-2^{7}\\) đến  \\(2^{7} - 1\\)|
|`bool`|Boolean|\\(1\\)|\\(0\\) hoặc \\(1\\)|

### Kiểu dữ liệu lưu trữ số nguyên

`short int`, `int`, `long long` hoặc `long int` là các kiểu dữ liệu lưu trữ các số nguyên. Các kiểu dữ liệu này có thể lưu trữ các số nguyên trong khoảng được nói ở bảng trên.

```C++
int a = 5;
short int b = -12;
long long c = 1000000000000000ll;
```

### Kiểu dữ liệu lưu trữ số thực

`float`, `double` hoặc `long double` là các kiểu dữ liệu lưu trữ các số thực. Các kiểu dữ liệu này có thể lưu trữ các số thực trong khoảng được nói ở bảng trên.

```C++
float c = 12;
double d = 3.1415926;
```

Ta cần cẩn thận khi so sánh hai số thực. Ví dụ: \\(0.1 + 0.2\\) sẽ không bằng \\(0.3\\).

```C++
if(0.1 + 0.2 == 0.3){
	cout << "True";
}else cout << "False"; // in "False"
```

Để khắc phục vấn đề này, ta có thể cho phép chênh lệnh giữa hai số không vượt quá một giới hạn nào đó, ví dụ như \\(10^{-6}\\).

```C++
if(abs((0.1 + 0.2) - 0.3) <= 1e-6){
	cout << "True"; // in "True"
}else cout << "False"; 
```

Nếu các biến lưu trữ số thực lưu các số nguyên thì nó sẽ cho kết quả chính xác, ví dụ: \\(1 + 2 = 3\\).

### Kiểu dữ liệu lưu trữ kí tự

`char` lưu trữ kí tự theo bộ mã [ASCII](https://vi.wikipedia.org/wiki/ASCII).

```C++
char a = 'a';
char b = char(98); // 98 trong ASCII là 'b'
char c = char(int('c')); // int() biến đổi kí tự thành chữ số tương ứng trong ASCII 
```

### Kiểu dữ liệu lưu trữ boolean

`bool` lưu trữ hai giá trị *đúng* hoặc *sai* \\((0/1)\\).

```C++
bool a = 0;
bool b = 1;
bool c = (5 < 7); // 5 < 7 đúng -> 1
bool d = !b; // d = 0
```

## `auto`

Ta có thể sử dụng `auto` khi khai báo và gán giá trị cho các biến.

```C++
auto a = 5; // int
auto b = 3.14; // float
```

Khi sử dụng `auto`, ta phải gán giá trị cho biến khi khai báo.

## `pair` và `tuple`

`pair` và `tuple` được sử dụng để lưu một số dữ liệu vào một biến.

Với `pair`, ta có thể lưu \\(2\\) loại giá trị.

```C++
pair<int, double> x(3, 3.14); // một pair lưu một `int` và một `double`
cout << x.first << '\n'; // giá trị thứ nhất
cout << x.second << '\n'; // giá trị thứ hai 

pair<int, double> y = make_pair(2, 2.718);
pair<int, int> z;
```

Với `tuple`, ta có thể lưu với số lượng tùy ý.

```C++
tuple<int, int, int> a(2, 3, 4); // tuple lưu 3 `int`
cout << get<0>(a); // 2
cout << get<1>(a); // 3
cout << get<2>(a); // 4
tuple<int, int, int> b = make_tuple(5, 6, 7);
tuple<bool, bool, bool, bool, bool, bool, bool> notGoodBitset;
```

## `tie`

Sẽ có lúc ta muốn gán nhiều biến với các giá trị khác nhau.

```C++
int a;
double b;
bool c;
// ...
a = 5;
b = 1.414;
c = 0;
```

Ta có thể sử dụng `tie` để gán các giá trị này trong một dòng.

```C++
int a; 
double b;
bool c;
tie(a, b, c) = make_tuple(5, 1.414, 0);
```

Từ C++17 trở đi, ta còn có thể khai báo luôn các biến trong một dòng.

```C++
auto [a, b, c] = make_tuple(5, 1.414, 0);
```

## Cấu trúc

Nếu không có kiểu dữ liệu nào có thể lưu thông tin mà ta mong muốn, ta có thể tự viết [cấu trúc](struct.md) cụ thể giúp lưu những thông tin ấy.