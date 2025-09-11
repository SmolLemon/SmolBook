# Thao tác xử lí bit

## Số nhị phân

Trong cuộc sống thường ngày, ta sử dụng số thập phân với các chữ số từ \\(0\\) đến \\(9\\) trong để biểu diễn số. Khác với chúng ta, máy tính sử dụng số nhị phân, với hai chữ số \\(0\\) và \\(1\\), để biểu diễn số.

Nếu như trong các số thập phân, chữ số đứng trước lớn gấp \\(10\\) lần chữ số đứng sau thì đối với các số nhị phân, con số này là \\(2\\) lần. Từ đây, giá trị của một dãy số nhị phân \\((b_k b_{k-1}... b_1 b_0)\\) sẽ bằng:

\\[b_k \times 2^k + b_{k - 1} \times 2^{k - 1}  + ... + b_{1} \times 2^{1} + b_{0} \times 2^{0}\\]

Ví dụ, số nhị phân \\(1011_2\\) có giá trị bằng:

\\[1011_2 = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 1 \times 2^0 = 11\\]

Trong lập trình, kiểu dữ liệu lưu các số nguyên có \\(n\\) bit được dùng để lưu một dãy số nhị phân chứa \\(n\\) chữ số. Trong C++, `int` là một kiểu dữ liệu lưu các số nguyên có \\(32\\) bit, còn `long long` là \\(64\\) bit. Ta lấy ví dụ số \\(193\\) lưu trên kiểu dữ liệu `int` sẽ có dãy nhị phân:

\\[00000000000000000000000011000001\\]

Để biểu diễn giá trị âm trên dãy số nguyên, ta sử dụng **Two's complement (phần bù của \\(2\\))**. Khi này, giá trị của một dãy số nhị phân \\((b_k b_{k-1}... b_1 b_0)\\) là:

\\[b_k \times {-2}^k + b_{k - 1} \times 2^{k - 1}  + ... + b_{1} \times 2^{1} + b_{0} \times 2^{0}\\]

Ví dụ, ta có số \\(-209\\) khi biểu diễn dưới dãy nhị phân (\\(16\\) chữ số):

\\[1111111100101111\\]

Khi không áp dụng phần bù của \\(2\\), một số nguyên \\(n\\) bit có thể lưu các giá trị từ \\(0\\) đến \\(2^n - 1\\), tức là ta lưu các số nguyên không âm. Để lưu dạng số này trong C++ ta chỉ cần thêm `unsigned` trước các kiểu dữ liệu.

Nếu số ta lưu giá trị lớn hơn giới hạn trên của kiểu dữ liệu, ta sẽ bị *tràn số*.

```C++
int x = 2147483647;
cout << x << '\n'; // 2147483647
++x;
cout << x << '\n'; // -2147483648
```

## Các toán tử thao tác bit

Ta có thể sử dụng các toán tử thao tác bit khi thực hiện các phép tính với bit. Có \\(6\\) thao tác bit cơ bản: AND, OR, XOR, NOT, dịch trái, dịch phải.

## AND, OR, XOR, NOT

Các toán tử thao tác AND (\\(\land\\)), OR (\\(\lor\\)), XOR (\\(\oplus\\)) và NOT (\\(\lnot\\)) thực hiện các phép tính trên các bit. 

Với hai bit \\(A\\) và \\(B\\):
- \\(A \land B\\) bằng \\(1\\) nếu cả \\(A\\) và \\(B\\) có giá trị \\(1\\), nếu không thì bằng \\(0\\)
- \\(A \lor B\\) bằng \\(1\\) nếu \\(A\\) hoặc \\(B\\) có giá trị \\(1\\), nếu không thì bằng \\(0\\)
- \\(A \oplus B\\) bằng \\(1\\) nếu \\(A\\) và \\(B\\) có giá trị khác nhau, nếu không thì bằng \\(0\\)
- \\(\lnot A\\) bằng \\(1\\) nếu \\(A\\) bằng \\(0\\), nếu không thì bằng \\(0\\) 

Bảng chân trị:

|\\(A\\)|\\(B\\)|\\(A \land B\\)|\\(A \lor B\\)|\\(A \oplus B\\)|\\(\lnot A\\)|\\(\lnot B\\)|
|---|---|---|---|---|---|---|
|\\(1\\)|\\(1\\)|\\(1\\)|\\(1\\)|\\(0\\)|\\(0\\)|\\(0\\)|
|\\(1\\)|\\(0\\)|\\(0\\)|\\(1\\)|\\(1\\)|\\(0\\)|\\(1\\)|
|\\(0\\)|\\(1\\)|\\(0\\)|\\(1\\)|\\(1\\)|\\(1\\)|\\(0\\)|
|\\(0\\)|\\(0\\)|\\(0\\)|\\(0\\)|\\(0\\)|\\(1\\)|\\(1\\)|

Trong C++, các kí hiệu của AND, OR, XOR và NOT lần lượt là `&`, `|`, `^` và `!`.

Khi sử dụng các thao tác bit AND, OR, XOR trên các số nguyên, kết quả sẽ là một số với các bit có giá trị bằng giá trị các bit tương ứng khi thực hiện các thao tác. Ví dụ:

```
a     = 11010 (Thập phân: 26)
b     = 10100 (Thập phân: 20)
a & b = 10000 (Thập phân: 16)
```

Khi sử dụng thao tác bit NOT trên số nguyên, kết quả sẽ bằng \\(1\\) nếu giá trị số nguyên bằng \\(0\\), và bằng \\(0\\) nếu giá trị khác \\(0\\).

### Dịch trái, dịch phải

Toán tử thao tác dịch trái \\(a << n\\), thêm \\(n\\) bit \\(0\\) vào \\(a\\). Tương tự, toán tử thao tác dịch phải \\(a >> n\\), xoá \\(n\\) bit bên phải \\(a\\).

Ví dụ:

```
a       =   101 (Thập phân: 5)
a << 2  = 10100 (Thập phân: 20)
a >> 2  =     1 (Thập phân: 1)
```

## Ứng dụng của các thao tác xử lí bit

### Nhân/Chia với \\(2^x\\)

Nếu chỉ nhân hoặc chia một số với một luỹ thừa của \\(2\\), ta có thể dịch bit của số nguyên ấy. Mỗi lần dịch 1 bit sang trái sẽ tương đương với nhân số ấy với \\(2\\), mỗi lần dịch \\(1\\) bit sang phải sẽ tương đương với chia lấy phần nguyên cho \\(2\\).

```
S                  =  0011100 (Thập phân: 28)
S = S * 2 = S << 1 =   111000 (Thập phân: 56)
S = S * 8 = S << 3 = 11100000 (Thập phân: 224)
S = S / 4 = S >> 2 =      111 (Thập phân: 7)
```

### Bitmask (Mảng bit)

Bitmask là một một mảng lưu các giá trị bit. Bitmask còn có thể được dùng để làm một tập hợp lưu các giá trị. Ta có thể tạo một bitmask bằng `int` hoặc `long long` tương ứng với \\(32\\) bit và \\(64\\) bit.

VD: 

```
chỉ số  3|2|1|0
S     = 1|0|1|1 (Thập phân: 11)
```

Như ta có thể thấy, khi \\(S = 11\\) thì có thể biểu thị một tập hợp có các phần tử \\(0\\), \\(1\\), \\(3\\).

Dưới đây là một số thao tác của bitmask:

#### Bật bit thứ \\(i\\)

Để bật bit thứ \\(i\\) của \\(S\\), ta sử dụng thao tác bit OR: `S = S | (1 << i)`.

```
S             = 0011001 (Thập phân: 25)
i = 2, 1 << i = 0000100 (Thập phân: 4) 
                ------- OR
              = 0011101 (Thập phân: 29)
```

#### Tắt bit thứ \\(i\\)

Để tắt bit thứ \\(i\\) của \\(S\\), ta sử dụng thao tác bit AND: `S = S & ~(1 << i)`.

```
S                = 0011001 (Thập phân: 25)
i = 2, ~(1 << i) = 1111011 (Thập phân: 4)
                   ------- AND
                 = 0011001 (Thập phân: 25)
```

#### Đảo bit thứ \\(i\\)

Để đảo bit thứ \\(i\\) của \\(S\\), ta sử dụng thao tác bit XOR: `S = S ^ (1 << i)`:

```
S             = 0011101 (Thập phân: 29) 
i = 2, 1 << i = 0000100 (Thập phân: 4) 
                ------- XOR
              = 0011001 (Thập phân: 25)
```

#### Lấy giá trị, kiểm tra bit thứ \\(i\\)

Để lấy giá trị bit thứ \\(i\\) của \\(S\\), ta sử dụng thao tác bit AND: `T = S & (1 << i)`.
- Nếu \\(T\\) bằng \\(0\\), bit thứ \\(i\\) có giá trị là \\(0\\)
- Nếu \\(T\\) khác \\(0\\), hay \\(T\\) bằng `1 << i`, bit thứ \\(i\\) có giá trị là \\(1\\)

```
S             = 0011101 (Thập phân: 29)
i = 2, 1 << i = 0000100 (Thập phân: 4) 
                ------- AND
              = 0000100 (Thập phân: 4) 
                -> Bit thứ i có giá trị 1
```

Ngoài ra còn có các kiểm tra khác cũng sử dụng thao tác bit AND: bit thứ \\(i\\) có giá trị `(S >> i) & 1`.

#### Bật \\(n\\) bit đầu tiên

Để bật \\(n\\) bit đầu tiên, ta có: `S = (1 << n) - 1`.

```
n = 5, 1 << 5 = 100000 (Thập phân: 32) 
              =      1 (Thập phân: 1)
              ------ Trừ
              =  11111 (Thập phân: 31) 
```

Từ ví dụ trên, ta còn rút thêm được một ứng dụng nữa: Xác định \\(N\\) có phải là một luỹ thừa của \\(2\\).

Để làm được điều này, ta sử dụng thao tác AND: `N & (N - 1)`:
- Nếu `N & (N - 1)` bằng \\(0\\) và \\(N\\) khác \\(0\\), \\(N\\) là một luỹ thừa của \\(2\\)
- Nếu `N & (N - 1)` khác \\(0\\), \\(N\\) không là một luỹ thừa của \\(2\\) 

```
N     = 100000 (Thập phân: 32)
N - 1 =  11111 (Thập phân: 31)
        ------ AND
      =      0 (Thập phân: 0) 
        -> N là một luỹ thừa của 2: 2^5

N     = 100001 (Thập phân: 33)
N - 1 = 100000 (Thập phân: 32)
        ------ AND
      = 100000 (Thập phân: 32) 
        -> N không là một luỹ thừa của 2
```

#### Tìm bit có giá trị nhỏ nhất

**Least significant bit (LSB)** hay bit có giá trị nhỏ nhất là bit có giá trị \\(1\\) đầu tiên trong dãy nhị phân xét từ phải sang trái. Để tìm được biểu diễn giá trị của bit này, ta sử dụng thao tác AND: `x & -x`. Nếu giá trị trả về là \\(0\\) thì không có bit nào có giá trị \\(1\\).

```
N  = 00100100 = (Thập phân: 36)
-N = 11011100 = (Thập phân: -36)
     -------- AND
   =      100 = (Thập phân: 4) 
    -> Bit được bật bên phải nhất của N có giá trị biểu diễn là 4.
```

Để tắt LSB, ta có \\(2\\) cách: `x = x - (x & -x)` hoặc `x = x & (x - 1)`

```
N            = 00100100 = (Thập phân: 36)

-N           = 11011100 = (Thập phân: -36)
N & -N       =      100 = (Thập phân: 4)
N - (N & -N) = 00100000 = (Thập phân: 32)
             -> Bit được bật bên phải nhất đã được tắt 

N - 1        = 11011011 = (Thập phân: 35)
N & (N - 1)  = 00100000 = (Thập phân: 32)
             -> Bit được bật bên phải nhất đã được tắt 
```

#### Duyệt các tập con của bitmask

Ta có một bitmask \\(mask\\) và giờ đây ta muốn duyệt các tập con của nó. Ta có cách thức vô cùng đơn giản:

```C++
for(int s = mask; s; s = (s - 1) & mask){
    // Xét tập con
}
```

Nếu muốn xét cả tập hợp rỗng, ta có thể chỉnh sửa lại:

```C++
for(int s = mask; ; s = (s - 1) & mask){
    // Xét tập con
    if(s == 0) break;
}
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
- `__builtin_clz(x)`: số lượng bit \\(0\\) ở đầu số \\(x\\).
- `__builtin_ctz(x)`: số lượng bit \\(0\\) ở cuối số \\(x\\).
- `__builtin_popcount(x)`: số lượng bit \\(1\\) có trong số \\(x\\).
- `__builtin_parity(x)`: tính chẵn lẻ của số lượng bit \\(1\\) trong số \\(x\\). 

```C++
int x = 12308; // 00000000000000000011000000010100
cout << __builtin_clz(x) << '\n'; // 18
cout << __builtin_ctz(x) << '\n'; // 2
cout << __builtin_popcount(x) << '\n'; // 4
cout << __builtin_parity(x) << '\n'; // 0
```

## `<bitset>` trong C++

`int` lưu được \\(32\\) bit, `long long` là \\(64\\). Nếu ta muốn lưu trữ nhiều bit hơn hoặc lưu số lương bit tùy ý thì ta sử dụng bitset trong thư viện `<bitset>`.

Khai báo:

```C++
bitset<kích_thước> tên_bitset([giá_trị]);
```

Kích thước của bitset phải cố định.

Ta có thể gán các giá trị bit ban đầu cho bitset theo nhiều cách khác nhau:

**1. Không gán trá trị:** khi này các bit sẽ có giá trị là \\(0\\).

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

Ta còn có thể thực hiện các thao tác bit trên bitset giống như với số nguyên. Ngoài ra để truy cập bit ta có thể sử dụng thao tác `[]`.

Ví dụ:

```C++
bitset<12> a(50);         // 000000110010
bitset<12> b("111011");   // 000000111011
cout << (a ^ b) << '\n';  // 000000001001
cout << (a | b) << '\n';  // 000000111011
cout << (a & b) << '\n';  // 000000110010
cout << ~a << '\n';       // 111111001101
cout << (a >> 5) << '\n'; // 000000000001
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
