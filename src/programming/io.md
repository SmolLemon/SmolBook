# Nhập xuất dữ liệu

Trong các bài toán lập trình, bài sẽ yêu cầu ta nhập vào dữ liệu, và in ra kết quả tương ứng.

Ta sẽ ví dụ 2 cách nhập xuất dữ liệu trong C++ thông qua bài ví dụ sau: 

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