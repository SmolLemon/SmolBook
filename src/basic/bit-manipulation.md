# Thao tác xử lý bit

## Số nhị phân

Một số nhị phân là một số được biểu diễn trong hệ cơ số 2 - các được biểu diễn bằng 2 chữ số 0 và 1.

Trong lập trình, kiểu dữ liệu lưu các số nguyên có `n` bit được dùng để lưu một dãy số nhị phân chứa `n` chữ số. Trong C++, `int` là một kiểu dữ liệu lưu các số nguyên có 32 bit, còn `long long` là 64 bit. Ta lấy ví dụ số 193 lưu trên kiểu dữ liệu `int` sẽ có dãy nhị phân:

\\[00000000000000000000000011000001\\]

Để tìm giá trị của một dãy số nhị phân \\((b_k b_{k-1}... b_1 b_0)\\), ta có công thức:

\\[b_k \times 2^k + b_{k - 1} \times 2^{k - 1}  + ... + b_{1} \times 2^{1} + b_{0} \times 2^{0}\\]

Ví dụ, số nhị phân \\(1011_2\\) có giá trị bằng:

\\[1011_2 = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 11\\]

Để biểu diễn giá trị âm trên dãy số nguyên, ta sử dụng **Two's complement (phần bù của 2)**. Khi này, giá trị của một dãy số nhị phân \\((b_k b_{k-1}... b_1 b_0)\\) là:

\\[b_k \times {-2}^k + b_{k - 1} \times 2^{k - 1}  + ... + b_{1} \times 2^{1} + b_{0} \times 2^{0}\\]

Ví dụ, ta có số -209 khi biểu diễn dưới dãy nhị phân (16 chữ số):

\\[1111111100101111\\]

Khi không áp dụng phần bù của 2, một số nguyên `n` bit có thể lưu các giá trị từ 0 đến \\(2^n - 1\\), tức là ta lưu các số nguyên không âm. Để lưu dạng số này trong C++ ta khai báo `unsigned [int/long long/...] tên_biến;`.

```C++
unsigned int x = 37;
```

Khi áp dụng phần bù của 2, ta có thể lưu các giá trị trong khoảng từ \\({-2}^{n - 1}\\) đến \\(2^{n - 1} - 1\\). Khi này ta có thể lưu cả giá trị các số nguyên âm. Trong C++, ta khai báo `signed [int/long long/...] tên_biến`, ta có thể bỏ `signed`.

```C++
int x = 73;
```

Nếu số ta lưu giá trị lớn hơn giới hạn trên của kiểu dữ liệu, ta sẽ bị *tràn số*.

Đối với các kiểu dữ liệu `signed`, số tiếp theo của \\(2^{n - 1} - 1\\) sẽ là \\(-2^{n - 1}\\). Đối với `unsigned` thì số tiếp theo của \\(2^n - 1\\) sẽ là 0.

```C++
int x = 2147483647;
cout << x << '\n'; // 2147483647
++x;
cout << x << '\n'; // -2147483648
```

## Các toán tử thao tác bit

### Toán tử thao tác AND (\\(\land\\))

Toán tử thao tác **AND** `x & y`  trả về một số có giá trị bit ở mỗi vị trí là kết quả của việc thực hiện phép lý phép toán luận lý **AND** với bit của x và y tương ứng - nếu 2 bit đều bằng 1 thì bit có giá trị là 1, không thì bit có giá trị là 0.

Ví dụ:
```
x = 1110 (Thập phân: 14)
y = 1011 (Thập phân: 11)
    ---- AND
  = 1010 (Thập phân: 10)
```

Bản chân trị cho thao tác AND:

|\\(A\\)|\\(B\\)|\\(A \land B\\)|   
|---|---|---|
|1|1|1|
|1|0|0|
|0|1|0|
|0|0|0|

### Toán tử thao tác OR (\\(\lor\\))

Toán tử thao tác **OR** `x | y` trả về một số có giá trị bit ở mỗi vị trí là kết quả của việc thực hiện phép lý phép toán luận lý **OR** với bit của x và y tương ứng - nếu có ít nhất 1 bit trong 2 bit bằng 1 thì bit có giá trị là 1, không thì bit có giá trị là 0.

Ví dụ:

```
x = 1110 (Thập phân: 14)
y = 1011 (Thập phân: 11)
    ---- OR
  = 1111 (Thập phân: 15)
```

Bản chân trị cho thao tác OR:

|\\(A\\)|\\(B\\)|\\(A \lor B\\)|   
|---|---|---|
|1|1|1|
|1|0|1|
|0|1|1|
|0|0|0|

### Toán tử thao tác XOR (\\(\oplus\\))

Toán tử thao tác **XOR** `x ^ y`  trả về một số có giá trị bit ở mỗi vị trí là kết quả của việc thực hiện phép lý phép toán luận lý **XOR** với bit của x và y tương ứng - nếu hai bit của hai số có giá trị khác nhau, bit tương ứng có giá trị là 1, không thì bit có giá trị là 0.

Ví dụ:

```
x = 1110 (Thập phân: 14)
y = 1011 (Thập phân: 11)
    ---- XOR
  = 0101 (Thập phân: 5)
```

Bản chân trị cho thao tác XOR:

|\\(A\\)|\\(B\\)|\\(A \oplus B\\)|   
|---|---|---|
|1|1|0|
|1|0|1|
|0|1|1|
|0|0|0|

### Toán tử thao tác NOT (\\(\neg\\))

Toán tử thao tác **NOT** `~x` về một số có giá trị bit ở mỗi vị trí là kết quả của việc thực hiện phép lý phép toán luận lý **NOT** với bit của x tương ứng - nếu bit có giá trị là 1 thì sẽ có giá trị 0 và ngược lại.

Ví dụ:

```
x = 1110 (Thập phân: 14)
    ---- NOT
  = 0001 (Thập phân: 1)
```

Bản chân trị cho thao tác NOT:

|\\(A\\)|\\(\neg A\\)|   
|---|---|
|1|0|
|0|1|

Khi thực hiện thao tác NOT với `bool`, ta có để sử dụng thao tác `!x` để trả giá trị ngược lại của biến `bool`. Khi dùng `!` với số nguyên như `int` hay `long long`, nó sẽ trả về 1 nếu số nguyên có giá trị 0, và trả về 0 nếu số nguyên có giá trị khác 0.

### Toán tử thao tác dịch trái (\\(\ll\\))

Toán tử thao tác dịch trái `a << n` xóa thêm n bit số 0 vào đầu dãy bit.

Ví dụ:

```
a =   101 (Thập phân: 5) -> Dịch sang trái 2 bit
  = 10100 (Thập phân: 20)
```

### Toán tử thao tác dịch phải (\\(\gg\\))

Toán tử thao tác dịch phải `a >> n` xóa n bit vào đầu dãy bit.

Ví dụ:

```
a = 10101 (Thập phân: 21) -> Dịch sang phải 2 bit
  =   101 (Thập phân: 5)
```

## Ứng dụng của các thao tác xử lý bit

Ta sẽ mặc định chỉ số đầu tiên có giá trị là 0 (0-based indexing).

### Nhân/Chia với \\(2^x\\)

Nếu chỉ nhân hoặc chia một số với một lũy thừa của 2, ta có thể dịch bit của số nguyên ấy. Mỗi lần dịch 1 bit sang trái sẽ tương đương với nhân số ấy với 2, mỗi lần dịch 1 bit sang phải sẽ tương đương với chia lấy phần nguyên cho 2.

```
S                  =  28 (Thập phân) =  0011100 (Nhị phân)
S = S * 2 = S << 1 =  56 (Thập phân) =   111000 (Nhị phân)
S = S * 8 = S << 3 = 224 (Thập phân) = 11100000 (Nhị phân)
S = S / 4 = S >> 2 =   7 (Thập phân) =      111 (Nhị phân)
```

### Bitmask (Mảng bit)

Bitmask là một một mảng lưu các giá trị bit. Bitmask còn có thể được dùng để làm một tập hợp lưu các giá trị. Ta có thể tạo một bitmask bằng `int` hoặc `long long` tương ứng với 32 bit và 64 bit.

VD: 

```
                     3|2|1|0
S = 11 (Thập phân) = 1|0|1|1 (Nhị phân)
```

Như ta có thể thấy, khi S = 14 thì có thể biểu thị một tập hợp có các phần tử 0, 1, 3.

Dưới đây là một số thao tác của bitmask:

#### Bật bit thứ i

Để bật bit thứ `i` của S, ta sử dụng thao tác bit OR: `S = S | (1 << i)`.

```
S             = 0011001 (Nhị phân) = 25 (Thập phân)
i = 2, 1 << i = 0000100 (Nhị phân) =  4 (Thập phân) 
                ------- OR
              = 0011101 (Nhị phân) = 29 (Thập phân)
```

#### Tắt bit thứ i

Để tắt bit thứ `i` của S, ta sử dụng thao tác bit AND: `S = S & ~(1 << i)`.

```
S                = 0011001 (Nhị phân) = 25 (Thập phân)
i = 2, ~(1 << i) = 1111011 (Nhị phân) =  4 (Thập phân) 
                   ------- AND
                 = 0011001 (Nhị phân) = 25 (Thập phân)
```

#### Đảo bit thứ i

Để đảo bit thứ `i` của S, ta sử dụng thao tác bit XOR: `S = S ^ (1 << i)`:

```
S             = 0011101 (Nhị phân) = 29 (Thập phân) 
i = 2, 1 << i = 0000100 (Nhị phân) =  4 (Thập phân) 
                ------- XOR
              = 0011001 (Nhị phân) = 25 (Thập phân)
```

#### Lấy giá trị, kiểm tra bit thứ i

Để lấy giá trị bit thứ `i` của S, ta sử dụng thao tác bit AND: `T = S & (1 << i)`.
- Nếu T bằng 0, bit thứ i có giá trị là 0
- Nếu T khác 0, hay T bằng `1 << i`, bit thứ i có giá trị là 1

```
S             = 0011101 (Nhị phân) = 29 (Thập phân)
i = 2, 1 << i = 0000100 (Nhị phân) =  4 (Thập phân) 
                ------- AND
              = 0000100 (Nhị phân) =  4 (Thập phân) 
                -> Bit thứ i có giá trị 1
```

Ngoài ra còn có các kiểm tra khác cũng sử dụng thao tác bit AND: bit thứ `i` có giá trị `(S >> i) & 1`.

#### Bật n bit đầu tiên

Để bật n bit đầu tiên, ta sử dụng dịch bit: `S = (1 << n) - 1`.

```
n = 5, 1 << 5 = 100000 (Nhị phân) = 32 (Thập phân) 
              =      1 (Nhị phân) =  1 (Thập phân)
              ------ Trừ
              =  11111 (Nhị phân) = 31 (Thập phân) 
```

Từ ví dụ trên, ta còn rút thêm được một ứng dụng nữa: Xác định N có phải là một lũy thừa của 2.

Để làm được điều này, ta sử dụng thao tác AND: `N & (N - 1)`:
- Nếu `N & (N - 1)` bằng 0 và N khác 0, N là một lũy thừa của 2 
- Nếu `N & (N - 1)` khác 0, N không là một lũy thừa của 2 

```
N     = 100000 (Nhị phân) = 32 (Thập phân)
N - 1 =  11111 (Nhị phân) = 31 (Thập phân)
        ------ AND
      =      0 (Nhị phân) =  0 (Thập phân) 
        -> N là một lũy thừa của 2: 2^5

N     = 100001 (Nhị phân) = 33 (Thập phân)
N - 1 = 100000 (Nhị phân) = 32 (Thập phân)
        ------ AND
      = 100000 (Nhị phân) = 32 (Thập phân) 
        -> N không là một lũy thừa của 2
```

#### Tìm biểu diễn giá trị của bit có giá trị nhỏ nhất

**Least significant bit (LSB)** hay bit có giá trị nhỏ nhất là bit có giá trị 1 đầu tiên trong dãy nhị phân xét từ phải sang trái. Để tìm được biểu diễn giá trị của bit này, ta sử dụng thao tác AND: `x & -x`. Nếu giá trị trả về là 0 thì không có bit nào có giá trị 1.

```
N  = 00100100 (Nhị phân) =  36 (Thập phân)
-N = 11011100 (Nhị phân) = -36 (Thập phân)
     -------- AND
   =      100 (Nhị phân) =   4 (Thập phân) 
    -> Bit được bật bên phải nhất của N có giá trị biểu diễn là 4.
```

Để tắt LSB, ta có 2 cách: `x = x - (x & -x)` hoặc `x = x & (x - 1)`

```
N            = 00100100 (Nhị phân) =  36 (Thập phân)

-N           = 11011100 (Nhị phân) = -36 (Thập phân)
N & -N       =      100 (Nhị phân) =   4 (Thập phân)
N - (N & -N) = 00100000 (Nhị phân) =  32 (Thập phân)
             -> Bit được bật bên phải nhất đã được tắt 

N - 1        = 11011011 (Nhị phân) =  35 (Thập phân)
N & (N - 1)  = 00100000 (Nhị phân) =  32 (Thập phân)
             -> Bit được bật bên phải nhất đã được tắt 
```

#### Các thao tác trong tập hợp

Như đã nói ở trên, bitmask có thể dùng để biểu diễn tập hợp.

Bảng sau sẽ cho ta thấy các thao tác của tập hợp và cách áp dụng tương ứng với bitmask sử dụng các toán tử thao tác:

|Thao tác|Ký hiệu cho tập hợp|Ký hiệu cho bit|
|---|---|---|
|Giao|\\(A \cap B\\)|\\(A \land B\\)|
|Hợp|\\(A \cup B\\)|\\(A \lor B\\)|
|Hiệu|\\(A \backslash B\\)|\\(A \land (\neg B)\\)|
|Phần bù|\\(\bar{A}\\)|\\(\neg A\\)|

## Một số hàm liên quan đến bit trong C++

Trình biên dịch g++ cung cấp cho ta một số hàm `builtin` cho các thao tác bit:
- `__builtin_clz(x)`: số lượng bit `0` ở đầu số `x`.
- `__builtin_ctz(x)`: số lượng bit `0` ở cuối số `x`.
- `__builtin_popcount(x)`: số lượng bit `1` có trong số `x`.
- `__builtin_parity(x)`: tính chẵn lẻ của số lượng bit `1` trong số `x`. 

```C++
int x = 12308; // 00000000000000000011000000010100
cout << __builtin_clz(x) << '\n'; // 18
cout << __builtin_ctz(x) << '\n'; // 2
cout << __builtin_popcount(x) << '\n'; // 4
cout << __builtin_parity(x) << '\n'; // 0
```

## `<bitset>` trong C++

`int` lưu được 32 bit, `long long` thì là 64. Nếu ta muốn lưu trữ nhiều bit hơn hoặc lưu số lương bit tùy ý thì ta sử dụng bitset trong thư viện `<bitset>`.

Khai báo:

```C++
bitset<kích_thước> tên_bitset([giá_trị]);
```

Kích thước của bitset phải cố định.

Ta có thể gán các giá trị bit ban đầu cho bitset theo nhiều cách khác nhau:

**1. Không gán trá trị:** khi này các bit sẽ có giá trị là 0.

```C++
bitset<kích_thước> tên_bitset;
```

**2. Gán trá trị bằng số:** khi này các bit sẽ có giá trị tương ứng với các bit của số tương ứng khi biểu diễn thành số nhị phân.

```C++
bitset<kích_thước> tên_bitset(số_thập_phân);
```

**3. Gán trá trị bằng xâu nhị phân:** khi này các bit sẽ có giá trị tương ứng với các kí tự trong xâu nhị phân.

```C++
bitset<kích_thước> tên_bitset(xâu_nhị_phân);
```

Ta còn có thể thực hiện các thao tác bit trên bitset giống như với số nguyên. Ngoài ra để truy cập bit ta có thể dùng dấu ngoặc vuông `[]`.

Ví dụ:

```C++
bitset<30> a(50);         // 000000000000000000000000110010
bitset<30> b("111011");   // 000000000000000000000000111011
cout << (a ^ b) << '\n';  // 000000000000000000000000001001
cout << (a | b) << '\n';  // 000000000000000000000000111011
cout << (a & b) << '\n';  // 000000000000000000000000110010
cout << ~a << '\n';       // 111111111111111111111111001101
cout << (a >> 5) << '\n'; // 000000000000000000000000000001
cout << a[5] << '\n';     // 1
```

Một số câu lệnh của bitset:
|Câu lệnh|Mô tả|
|---|---|
|`test(pos)`|Trả về giá trị của bit ở vị trí pos|
|`all()`|Trả về giá trị `true` nếu tất cả các bit được bật|
|`any()`|Trả về giá trị `true` nếu có ít nhất 1 bit được bật|
|`none()`|Trả về giá trị `true` nếu không có bit nào được bật|
|`count()`|Trả về số lượng bit được bật|
|`size()`|Trả về kích thước của bitset|
|`set(pos)`|Đổi giá trị bit ở tất cả các vị trí hoặc một vị trí `pos` thành 1|
|`reset(pos)`|Đổi giá trị bit ở tất cả các vị trí hoặc một vị trí `pos` thành 0|
|`flip(pos)`|Đảo giá trị bit ở tất cả các vị trí hoặc một vị trí `pos`|
|`to_string()`|Trả về biểu diễn xâu kí tự của bitset|
|`to_ulong()`|Trả về biểu diễn `unsigned long` của bitset|
|`to_ullong()`|Trả về biểu diễn `unsigned long long` của bitset|
