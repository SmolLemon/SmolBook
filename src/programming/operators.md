# Các toán tử

Ta sẽ tìm hiểu về các toán tử phổ biến trong C++.

## Toán tử gán (`=`)

Toán tử gán (`=`) gán giá trị cho một biến. 

```C++
int a = 5;
int b = a;
int c = a * b;
```

## Toán tử toán học (`+`, `-`, `*`, `/`, `%`)

Các toán tử toán học sẽ thực hiện các phép tính toán học:

```C++
int a = 2, b = 3;
// phép cộng
int c = a + b;
cout << c << '\n'; // 5;

// phép trừ
int d = a - b;
cout << d << '\n'; // -1

// phép nhân
int e = a * b;
cout << e << '\n'; // 6

// phép chia
int f = a / b;
cout << f << '\n'; // 0

// phép modulo
int g = a % b;
cout << g << '\n'; // 2
```

Đối với phép modulo, nếu thực hiện modulo cho một số âm thì nó sẽ cho ra một số âm thay vì số dương như trong toán học.

```C++
int a = -2, b = 3;

cout << (a % b) << '\n';           // -1 thay vì 2

// khắc phục
cout << ((a % b) + b) % b << '\n'; // 2
```

Đối với xâu kí tự, toán tử `+` được dùng để gán các xâu kí tự lại với nhau.

```C++
string a = string("Cam") + ' ' + "nang";    
cout << a << '\n'; // "Cam nang"
```

## Toán tử tăng giảm (`++`, `--`)

Đối với những trường hợp cần tăng hoặc giảm một đơn vị giá trị của một biến, thay vì viết `x = x + 1` hoặc dùng toán tử hỗn hợp `x += 1`, ta có thể viết `x++`.

Việc viết `x++` và `++x` sẽ khác nhau đôi chút - `x++` sẽ trả về cho ta giá trị `x` và tăng `x` lên một đơn vị, trong khi `++x` trả về cho ta giá trị `x + 1` và tăng `x` lên một đơn vị.

```C++
int x = 5;
cout << x++ << '\n'; // 5
// x = 6

cout << ++x << '\n'; // 7
// x = 7
```

## Toán tử so sánh (`==`, `!=`, `>`, `<`, `<=`, `>=`)

Các toán tử so sánh cho ta biết mối quan hệ giữa các giá trị của hai biến. Cụ thể, với hai biến cùng kiểu dữ liệu `a` và `b`:

|Toán tử|Công dụng|
|---|---|
|`a == b`|Hai biến có giá trị bằng nhau|
|`a != b`|Hai biến có giá trị khác nhau|
|`a > b`|Biến `a` có giá trị lớn hơn biến `b`|
|`a < b`|Biến `a` có giá trị bé hơn biến `b`|
|`a >= b`|Biến `a` có giá trị lớn hơn hoặc bằng biến `b`|
|`a <= b`|Biến `a` có giá trị bé hơn hoặc bằng biến `b`|

Các toán tử này sẽ trả về giá trị đúng hoặc sai. Nếu ta viết `4 < 5` thì nó sẽ trả về \\(1\\) nghĩa là đúng, `4 > 5` thì trả về \\(0\\) nghĩa là sai.

## Toán tử logic (`!`, `&&`, `||`)

Các toán từ logic (`!`, `&&`, `||`) sẽ thực hiện thao tác với các boolean giống với thao tác [NOT](../basic/bit-manipulation.md#toán-tử-thao-tác-not-neg), [AND](../basic/bit-manipulation.md#toán-tử-thao-tác-and-land) và [OR](../basic/bit-manipulation.md#toán-tử-thao-tác-or-lor). Để minh hoạ, ta có hai biến boolean `a` và `b`.

|`a`|`b`|`!a`|`!b`|`a && b`|`a \|\| b`|
|---|---|---|---|---|---|
|1|1|0|0|1|1|
|1|0|0|1|0|1|
|0|1|1|0|0|1|
|0|0|1|1|0|0|

Ví dụ:

```C++
( (4 < 5) && (5 > 0) )  // (1 && 1) => 1
( (4 == 5) || (5 < 0) ) // (1 || 1) => 1
```

Khi sử dụng các toán tử logic, C++ có thể chỉ cần xét các toán tử cần thiết để cho ra đáp án. Ví dụ với thao tác `((4 == 5) && (5 < 0))`. Vì C++ kiểm tra `(4 == 5)` trả về 0 trước nên nó sẽ trả về thao tác này là 0 mà không cần phải xét `(5 < 0)`.

## Toán tử thao tác bit (`&`, `|`, `^`, `~`, `>>`, `<<`)

Các toán tử thao tác bit (`&`, `|`, `^`, `~`, `>>`, `<<`) được sử dụng cho các số nguyên, thực hiện các thao tác bit. Cách các thao tác hoạt động được nói ở phần [Thao tác xử lí bit](../basic/bit-manipulation.md).

```C++
int a = 5, b = 7;
cout << (a & b) << '\n';  // 5
cout << (a ^ b) << '\n';  // 2
cout << (7 << 2) << '\n'; // 28
```

## Toán tử hỗn hợp (`+=`, `-=`, `*=`, `/=`, `%=`, `>>=`, `<<=`, `&=`, `^=`, `|=`)

Các toán tử hỗn hợp (`+=`, `-=`, `*=`, `/=`, `%=`, `>>=`, `<<=`, `&=`, `^=`, `|=`) cập nhật các biến bằng một giá trị. Nếu ta viết `a += 5`, thì nó sẽ tương đương với `a = a + 5`. Các toán tử khác cũng tương tự.

## Toán tử dấu phẩy (`,`)

Toán tử dấu phẩy (`,`) kết hợp nhiều phép tính vào một câu lệnh. Nếu ta lấy giá trị của câu lệnh thì giá trị cuối cùng sẽ là giá trị được lấy.

```C++
int x;
x = (x = 3, x *= 5, x + 2); // x = 17
```

Câu lệnh trên có 3 thao tác: gán `x = 3`, nhân `x` lên \\(5\\), vá tính `x + 2`. Vì `x + 2` là thao tác cuối cùng nên giá trị của `x` sẽ bằng \\(17\\). 