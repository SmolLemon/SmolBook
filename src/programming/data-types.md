# Các kiểu dữ liệu

Ở C++ và nhiều ngôn ngữ lập trình ta sẽ bắt gặp các kiểu dữ liệu được biểu diễn ở dạng nhị phân như sau:

|Tên dữ liệu|Loại dữ liệu|Kích cỡ (bytes)|Dãy giá trị|
|---|---|---|---|
|`int`|Số nguyên 32 bit|4|\\(-2^{31}\\) đến \\(2^{31} - 1 \\)|
|`short int`|Số nguyên 16 bit|2|\\(-2^{15}\\) đến \\(2^{15} - 1 \\)|
|`long long`|Số nguyên 64 bit|8|\\(-2^{63}\\) đến \\(2^{63} - 1 \\)|
|`float`|Số thực độ chính xác đơn|4|\\(\approx -3.4 \times 10^{38}\\) đến \\(\approx 3.4 \times 10^{38}\\)|
|`double`|Số thực độ chính xác kép|8|\\(\approx -1.7 \times 10^{308}\\) đến \\(\approx 1.7 \times 10^{308}\\)||`bool`|Giá trị đúng/sai|1|`true` hoặc `false` (0 hoặc 1)|
|`char`|Kí tự|1|\\(-2^{7}\\) đến  \\(2^{7} - 1 \\)|


### Số nguyên

`int`, `short int`, `long long` dùng để lưu số nguyên. Các kiểu dữ liệu này có thể lưu các số nguyên *không dấu* (lưu các số nguyên không âm), hoặc *có dấu* (có thể lưu các số nguyên âm). 

Để lưu các số nguyên không dấu, ta viết thêm `unsigned` ở đầu kiểu dữ liệu.

VD:

```c++
unsigned int ui;
unsigned long long lli;
unsigned short int si;
```

Khi lưu các số nguyên có dấu ta không cần viết `signed` ở đầu kiểu dữ liệu.

> **Lưu ý**: Trong C++, phép `%` dùng để lấy phần dư của một số. Khi dùng phép `%` với số âm thì kết quả sẽ là 0 hoặc là một số âm. Nếu tìm modulo của một số âm bằng phép `%` thì ta thực hiện: `((a % b) + b) % b`

### Số thực

`float`, `double` dùng để lưu các số thực. 2 cách lưu trữ số này chỉ lưu các số thập phân chính xác một phần: `float` có thể lưu chính xác đến khoảng 7 số sau dấu chấm phẩy, `double` gấp đôi: 14 đến 15 số

Ta không nên so sánh 2 số thực bằng kí tự `==`. Nếu ta chạy:

```c++
if(0.1 + 0.2 == 0.3){
	cout << "True";
}else cout << "False";
```

Thì nó sẽ in `False` chứ không phải `True`.

Các bài tập yêu cầu in số thực sẽ chấp nhận kết quả chương trình của bạn nếu chệnh lệnh của đáp án của bạn và đáp án của bài nằm trong khoảng yêu cầu ví dụ như \\(10^{-9}\\).

- Nếu output là \\(x\\) và đáp án của test là \\(y\\) thì chênh lênh sẽ là \\(|x - y|\\)

### Boolean

`bool` dùng để lưu 2 giá trị \\(true/false \ (0/1)\\).

Bool lại dùng đến 8 bit để lưu \\(true/false\\) trong khi có thể dùng 1 bit để làm điều tương tự. Ta có thể dùng `bitset` để có thể tối ưu bộ nhớ.

### Kí tự

`char` lưu kí tự theo bộ mã [ASCII](https://vi.wikipedia.org/wiki/ASCII)

Ta có thể chuyển từ kí tự sang số bằng cách dùng câu lệnh `int([kí_tự])`, hoặc chuyển một số sang một kí tự bằng `char([mã số])`.

Mã số của các kí tự quen thuộc trong ASCII:

- Mã số của các kí tự từ `1` đến `10` là từ \\(48\\) đến \\(57\\).
- Mã số của các kí tự từ `a` đến `z` là từ \\(97\\) đến \\(122\\).
- Mã số của các kí tự từ `A` đến `Z` là từ \\(65\\) đến \\(90\\).
- Ta có thể chuyển từ kí tự in thường sang in hoa và ngược lại bằng cách trừ hoặc cộng \\(32\\).


### Xâu kí tự

`string` là một chuối kí tự chứa các giá trị `char`. 
