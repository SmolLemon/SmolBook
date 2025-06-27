# Hàm

Một hàm trong C++ là một tập hợp các đoạn code trong chương trình để thực hiện một yêu cầu. Khi ta có một đoạn code thực hiện một yêu cầu cụ thể, ta có thể tái sử dụng một đoạn code ấy cho nhiều mục đich khác nhau.

Giả sử ta muốn in ra màn hình nói rằng: `Toi la A. Nam nay toi 17 tuoi`, ta viết một dòng lệnh để in dòng ấy. 

```C++
cout << "Toi la A. Nam nay toi 17 tuoi" << '\n';
```

Bây giờ, ta muốn in ra màn hình một dòng khác nói rằng: `Toi la B. Nam nay toi 30 tuoi`, ta lại viết một dòng lệnh khác:

```C++
cout << "Toi la A. Nam nay toi 17 tuoi" << '\n';
cout << "Toi la B. Nam nay toi 30 tuoi" << '\n';
```

Và cứ tiếp tục như thế: `Toi la [tên]. Nam nay toi [tuổi] tuoi`.

Thay vì viết một cách thủ công như thế, ta có thể viết một hàm có thể thực hiện điều này.

```C++
void print(string name, int age){
	cout << "Toi la "<< name << ". Nam nay toi " << age << " tuoi" << '\n';
	return;
}
```

Bây giờ, ta chỉ cần viết `print(name, age)` và chỉ điền tên và tuổi và hàm `print` sẽ lo những việc còn lại.

```C++
// trong hàm main
	print("A", 17); // In ra "Toi la A. Nam nay toi 17 tuoi"
	print("B", 30); // In ra "Toi la B. Nam nay toi 30 tuoi"
```

## Cấu trúc

Một hàm trong C++ sẽ có cấu trúc như sau:

```C++
kiểu_trả_về tên_hàm(tham_số_1, tham_số_2, ..., tham_số_n){
	// code
}
```

Trong đó:
- **Kiểu trả về** là kiểu dữ liệu mà hàm sẽ trả về cho ta nếu ta gọi hàm đó. Để trả về giá trị trong một hàm, ta viết `return` và sau đó và một giá trị nào đó. Ta đã được thấy hàm `main` trả về \\(0\\) để báo hiệu trình biên dịch rằng chương trình đã biên dịch thành công. Có thể có những hàm không trả về giá trị gì như hàm `print` ở trên, nên kiểu trả về của nó sẽ là `void`. Ta vẫn có thể viết `return` trong một hàm `void` để kết thúc sớm một hàm, nhưng ta không thêm giá trị trả về ở sau nó giống như hàm `print`. 
- **Tên hàm** là tên của hàm.
- **Tham số** là những thông tin mà ta cho hàm để hàm thực thi. Ở hàm `print`, ta có hai tham số là `name` và `age`. Các hàm có thể không có tham số.

Ta ví dụ với một hàm `min` so sánh và trả về số nhỏ hơn trong hai số.

```C++
int min(int a, int b){
	if (a < b) return a;
	return b;
}
```

Thông thường, các hàm sẽ được khai báo ở trước hàm `main` để các đoạn code có thể "nhìn thấy" được các hàm ấy mà thực thi.

```C++
int min(int a, int b){
	if (a < b) return a;
	return b;
}

int main(){
	cout << min(3, 5);
}
```

Nếu như ta muốn khai báo một hàm ở dưới hàm `main`, ta cần phải viết một *mẩu hàm (function stub)* để các đoạn code trong hàm `main` biết đến sự tồn tại của hàm ấy.

```C++
int min(int a, int b); // mẩu hàm

int main(){
	cout << min(3, 5);
}

int min(int a, int b){
	if (a < b) return a;
	return b;
}
```

## Tham chiếu

Khi ta nạp các tham số vào một hàm, thứ ta nạp vào thực chất là một bản sao của giá trị gốc.

Giả sử ta có một hàm chuyển đổi giá trị tham số nó được nhận thành \\(10\\).

```C++
void change(int val){
	val = 10;
}

int main(){
	int v = 5;
	cout << "Truoc: " << v << '\n';
	change(v);
	cout << "Sau: " << v << '\n';
}
```

Nếu ta biên dịch chương trình trên, cả hai dòng `Truoc` và `Sau` đều sẽ in giá trị của biến `v` là \\(5\\).

Để có thể thay đổi giá trị của `v`, ta chuyền vào hàm `change` *tham chiếu (reference)* của biến `v`. Khi này, ta có thể thay đổi giá trị của biến.

```C++
void change(int &val){
	val = 10;
}

int main(){
	int v = 5;
	cout << "Truoc: " << v << '\n';
	change(v);
	cout << "Sau: " << v << '\n';
}
```

Giờ đây, khi giá trị của `v` đã được thay đổi, dòng `Sau` sẽ in ra \\(10\\) thay vì là \\(5\\) như đoạn code cũ. 