# Câu lệnh rẽ nhánh

Câu lệnh rẽ nhánh sẽ thực hiện một đoạn code nếu thỏa mãn điều kiện.

```C++
int a = 4;
if (a < 5){
	cout << a << " < 5";
}
```

Ở đây, ta có \\(a = 4 < 5\\) nên ta sẽ in `4 < 5`.

Nếu ta muốn xét cả trường hợp \\(a \ge 5\\), chương trình sẽ "rẽ nhánh" câu lệnh thực hiện đoạn code khác khi điều kiện \\(a < 5\\) không thỏa mãn. 

```C++
int a = 5;
if (a < 5){
	cout << a << " < 5";
} else {
	cout << a << " >= 5";
}
```

Ta cũng có thể thêm một câu lệnh rẽ nhánh khác vào `else`.


```C++
int a = 5;
if (a < 5){
	cout << a << " < 5";
} else if (a > 5) {
	cout << a << " > 5";
} else {
	cout << a << " == 5";
}
```

Việc viết `else if` tương tự với:

```C++
else {
	if([...]){

	}
}
```

## Toán tử ba ngôi

**Toán tử ba ngôi (ternary operator)** giúp rút gọn code khi sử dụng `if-else` để gán giá trị.

Thay vì viết:

```C++
if ([điều kiện]){
	var = x;
} else {
	var = y;
}
```

Ta có thể viết:

```C++
var = [điều kiện] ? x : y;
```

Ví dụ, thay vì viết:

```C++
int x = 7;
if (x < 8) {
	cout << "Hi";
} else{
	cout << "Hello";
}
```

Ta có thể viết:

```C++
int x = 7;
cout << (x < 8 ? "Hi" : "Hello");
```

## switch-case

Ta sử dụng lệnh `switch` cho một biến để xét một danh sách các trường hợp (case) mà nếu biến có giá trị bằng trường hợp ấy.

```C++
switch ([biến]){
	case [trường hợp 1]:
		// code
		break;
	case [trường hợp 2]:
		// code
		break;
	// ...
	case [trường hợp n]:
		// code
		break;
	default:
		// code
}
```

Chương trình của ta sẽ thực hiện các bước sau:
- `switch` xét một biến nào đó.
- Với mỗi `case`, chương trình sẽ kiểm tra nếu biến có giá trị bằng `case` không. Nếu bằng, chương trình sẽ thực hiện đoạn code trong `case`.
- `break;` để thoát khỏi `switch` nếu `case` thỏa mãn. Có thể không viết `break`.
- Nếu không có case nào thỏa mãn, chương trình sẽ chạy đoạn code trong `default`. Có thể không viết `default` 

```C++
int score = 10;

switch (score){
	case 1: cout << "1"; break;
	case 2: cout << "2"; break;
	case 3: cout << "3"; break;
	case 4: cout << "4"; break;
	case 5: cout << "5"; break;
	case 6: cout << "6"; break;
	case 7: cout << "7"; break;
	case 8: cout << "8"; break;
	case 9: cout << "9"; break;
	case 10: cout << "10"; break;
	default: cout << "No"; break;
}
```