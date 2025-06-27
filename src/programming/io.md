# Nhập - xuất dữ liệu

Ở các ví dụ trước ta đã biết được rằng `cout` có thể in các giá trị ra màn hình. Bây giờ, ta sẽ làm điều ngược lại: lấy dữ liệu bằng `cin`.

Giả sử ta muốn lấy dữ liệu hai số nguyên được nhập từ bàn phím, ta viết:

```C++
int a, b;
cin >> a >> b;
```

Khi ta nhập từ bàn phím hai số:

```
2 3
```

Thì chương trình sẽ lấy dữ liệu được nhập và gán \\(a = 2\\) và \\(b = 3\\).

## Lấy dữ liệu từ một dòng

Nếu như bài toán yêu cầu nhập vào một xâu kí tự thì `cin` sẽ lấy giá trị cho tới khi nó gặp dấu dấu cách hoặc xuống dòng. Để đọc dữ liệu của cả một dòng, ta sử dụng `getline`:

```C++
string s;
getline(s, cin);
```

Nếu trước đó có sử dụng `cin` để đọc dữ liệu, việc sử dụng getline ở câu lệnh nhập tiếp theo sẽ thực thi trái với mong đợi của ta.

Giả sử ta có hai xâu ở hai dòng:

```C++
hello
hello world!
``` 

Và ta nhập dữ liệu bằng cách sau:

```C++
string a; cin >> a;
string b; getline(cin, b);
```

Thì `getline` sẽ đọc các kí tự xuống dòng sau `hello` ở dòng \\(1\\) mà không phải `hello world!` ở dòng \\(2\\) như ta mong muốn. Để khắc phục vấn đề này, ta sử dụng `cin.ignore()`.

```C++
string a; cin >> a;
cin.ignore();
string b; getline(cin, b);
```

## Dữ liệu nhập không xác định

Một yêu cầu khác của việc nhập dữ liệu là nhập cho tới khi không còn dữ liệu. Đây là các bài toán mà ta không được biết trước kích thước của dữ liệu nhập. Khi đấy, ta sử dụng `while(cin)`:

```C++
int x;
while(cin >> x){
	// code
}
```

## Nhập vào từng từ trên dòng

Một số bài toán có thể yêu cầu ta xét một số lượng từ không xác định trên một dòng. 

```C++
smol book cam nang lap trinh thi dau
```

Để xử lí trường hợp này, ta sử dụng `getline` để lấy dữ liệu của dòng, và dùng `stringstream` để tách từng từ có trên dòng ấy:

```C++
string s;
getline(cin, s);
stringstream ss(s);
string word;
while(ss >> word){
	// code
}
```

## Fast I/O

Trong hầu hết các bài nộp C++, ta thường bắt gặp \\(2\\) dòng lệnh phổ biến ở đầu hàm `main`:

```C++
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

\\(2\\) câu lệnh này được thêm là có lý do của nó. Nó giúp tăng tốc chương trình bằng cách thay đổi cách nhập xuất của C++.

`ios_base::sync_with_stdio(false)` tắt đồng bộ giữa cách nhập xuất của C và C++. Tính năng này giúp ta có thể sử dụng linh hoạt giữa hai cách nhập xuất khác nhau. Khi tắt tính năng này, chương trình của ta sẽ chạy nhanh hơn nếu bài toán yêu cầu nhập xuất dữ liệu nhiều lần. Lưu ý rằng nếu tắt đồng bộ thì không nên sử dụng đồng thời \\(2\\) cách nhập xuất.

`cin.tie(NULL)` tắt  đồng bộ giữa `cin` và `cout`. `tie()` được dùng để đảm bảo tất cả các dữ liệu của `cout` sẽ được xuất ra màn hình trước khi thực hiện `cin` nhập dữ liệu. Điều này sẽ giúp ích cho các chương trình cần sự tương tác giữa người và chương trình, hoặc chương trình và chương trình - thứ mà ngoài dạng bài toán tương tác ra thì không cần thiết trong lập trình thi đấu. Việc tương tác này sẽ chương trình của ta sẽ chạy chậm đi. Ta tắt tính năng này để gia tăng tốc độ chương trình.

Một số chương trình còn có cả `cout.tie(0)` nhưng điều này là không cần thiết.

## `endl` vs `'\n'`

Nếu như ta muốn xuống dòng khi xuất dữ liệu, ta nên sử dụng kí tự xuống dòng `'\n'` thay vì sử dụng `endl`. `endl` là một câu lệnh trong C++ thực hiện hai nhiệm vụ: xuống dòng và xuất dữ liệu ra màn hình. Chính cái nhiệm vụ thứ hai là lí do ta không nên sử dụng `endl` trong hầu hết trường hợp bởi nếu bài toán yêu cầu dữ liệu ra phải xuống dòng liên tục thì việc in dữ liệu ra màn hình sẽ làm chậm chương trình đi.

## In các chữ số thập phân

Nếu bài toán yêu cầu in số thực với \\(x\\) chữ số sau dấu chấm, ta sử dụng `setprecision`:

```C++
cout << setprecision(6);
```

`setprecision` sẽ in ra \\(x\\) số thập phân sau dấu chấm với mỗi lần ta in các số thập phân. Nếu ta muốn in chính xác \\(x\\) chữ số sau dấu phẩy, ta thêm `fixed`:

```C++
cout << setprecision(6) << fixed;
```

Câu lệnh này chỉ cần được viết \\(1\\) lần.

## `scanf/printf`

Ngoài cách sử dụng `cin/cout` là phương thức nhập xuất cho các chương trình C++, ta có thể sử dụng phương thức nhập xuất `scanf/printf` của C. Đoạn code dưới đây lấy giá trị hai số từ dữ liệu nhập, in ra tổng hai số:

```C++
int a, b;
scanf("%d%d", &a, &b);
printf("%d", a + b);
```

## Nhập - xuất dữ liệu trên file

Để nhập - xuất dữ liệu trên file, ta chỉ cần thêm hai câu lệnh:

```C++
froepen("[tên_file_nhập]", "r", stdin); // file nhập
froepen("[tên_file_xuất]", "w", stdout); // file xuất
```

và thực hiện nhập xuất bằng `cin/cout` như trước khi có hai dòng lệnh trên.