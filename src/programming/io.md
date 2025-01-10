# Nhập xuất dữ liệu

Trong các bài toán lập trình, bài sẽ yêu cầu ta nhập vào dữ liệu, và in ra kết quả tương ứng.

Ta sẽ ví dụ về cách nhập xuất dữ liệu trong C++ thông qua các bài ví dụ sau: 

> Nhập hai số `a` và `b`, yêu cầu in ra tổng hai số.
> 
> Input:
> 
> ```
> 1 2
> ```
> 
> Output:
> 
> ```
> 3
> ```

Một cách để nhập dữ liệu phổ biến trong C++ chính là sử dụng `std::cin`.

```C++
	int a, b;
	cin >> a >> b;
```

Với một đoạn thông tin nó sẽ nhập vào và kết thúc khi xuất hiện dấu cách hoặc dấu xuống dòng. Vậy nên khi dữ liệu nhập có dạng như dưới đây thì đoạn code vẫn sẽ nhập vào hai số như bình thường:

```
1             2
```

```
1
2
```

Đối với việc xuất dữ liệu, ta sử dụng `std::cout`.

```C++
	cout << a + b << '\n';
```

Việc nhập xuất dữ liệu liên tục sẽ giảm hiệu suất của chương trình, dẫn đến TLE. Ta áp dụng [Fast I/O](cpp-tips-and-tricks.md#fast-io) để tối ưu quá trình này.

Ta cũng có thể sử dụng `scanf/printf` của C để nhập dữ liệu. Phương pháp này tuy nhanh hơn so với C++ (lúc chưa có Fast I/O), nhưng lại khó dùng hơn một chút.

Dưới đây là đoạn code sử dụng `scanf/printf`:

```C
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a + b);
```

Ta có thể sử dụng lẫn lộn cả hai cách nhập trong chương trình. Lưu ý rằng khi sử dụng Fast I/O thì không nên làm điều này. 

Đối với những bài yêu cầu đọc/ghi dữ liệu vào file, ta có thể làm điều này một cách đơn giản bằng cách sử dụng `freopen`:

```C++
	freopen("[tên file nhập]", "r", stdin); // Lấy dữ liệu từ file
	freopen("[tên file xuất]", "w", stdout); // Xuất dữ liệu ra file
```

Trong hầu hết các bài toán yêu cầu nhập xuất dữ liệu qua file, ta thường viết tên các file như sau:

```C++
	freopen("[tên chương trình].INP", "r", stdin);
	freopen("[tên chương trình].OUT", "w", stdout); 
```

## Một số yêu cầu đặc biệt cho mỗi bài

### Nhập nhiều số với số lượng không xác định

Đối với các bài có số lượng dữ liệu nhập không xác định, ta có thể viết code như sau:

```C++
int n;
while(cin >> n){ // Kết thúc vòng lặp nếu không còn nhập số
	/* code */
}
```

### Nhập xâu trên một dòng

Giả sử đề yêu cầu ta nhập một xâu có trên một hàng, ví dụ như:

```
abc def
```

Và ta viết dòng lệnh:

```C++
string s; cin >> s;
```

Xâu `s` của ta sẽ chỉ lưu `abc` thay vì `abc def` như ta mong muốn. Đấy là bởi vì `cin` sẽ chỉ nhập các kí tự liên tiếp cho tới khi có dấu cách, xuống dòng hoặc đến cuối file.

Để có thể nhập toàn bộ kí tự có trên một dòng, ta dùng lệnh `getline`:

```C++
string s; getline(cin, s);
```

### Nhập nhiều số với số lượng không xác định trên nhiều dòng

Đây là kết hợp giữa hai dạng trên. 

Ta có bài toán yêu cầu ta tính tổng các số trên mỗi hàng với số lượng không xác định.

```
1 2 3 4
989 2435 146
23 56 19 86 29 10
```

Các dòng \\(1\\), \\(2\\), \\(3\\) lần lượt có tổng là \\(10\\), \\(3570\\) và \\(223\\).

Để giải quyết bài toán này, ta sử dụng `stringstream`:

```C++
string s;
while (getline(cin, s)) {
	stringstream line(s);
	int sum = 0;
	int x;
	while(line >> x) sum += x;
	cout << sum << endl;
}
```