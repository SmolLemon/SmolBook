# Câu lệnh lặp

Câu lệnh lặp được sử dụng khi ta muốn thực hiện một đoạn code nào đó nhiều lần. 

Có hai cách để thực hiện câu lệnh lặp trong C++: vòng lặp `for` và vòng lặp `while`.

## Vòng lặp `for`

Vòng lặp `for` trong C++ hoạt động như sau:

```C++
for ([1]; [2]; [3]){
	// code
}
``` 

Trong đó:
- \\([1]\\): Câu lệnh được thực thi một lần trước khi vào vòng lặp.
- \\([2]\\): Điều kiện để thực hiện vòng lặp. Những đoạn code trong vòng lặp chỉ được thực thi chỉ khi điều kiện đúng.
- \\([3]\\): Câu lệnh được thực thi sau mỗi lần thực hiện một vòng lặp.

Ba yếu tố này giúp ta có được một vòng lặp `for`.

Ví dụ:

```C++
for (int i = 1; i <= 5; ++i){
	cout << i << '\n';
}
```

Vòng lặp này khởi tạo một biến `i` có giá trị \\(1\\), in `i` ra màn hình, tăng giá trị của `i` lên \\(1\\). Quá trình này lặp lại cho tới khi giá trị của `i` vượt của \\(5\\).

### Vòng lặp "for-each"

Vòng lặp for-each duyệt các phần tử có trong mảng.

```C++
for ([phần tử] : [mảng]){
	// code
}
```

Ví dụ:

```C++
vector<int> a = {1, 2, 3, 4, 5};
for (int x : a){
	cout << x << ' ';
}
```

Thì vòng lặp sẽ duyệt và in các phần tử trong `a` ra màn hình: `1 2 3 4 5 `. 

> [!IMPORTANT]
> Từ C++17 trở đi, ta có thể dùng mẹo sau để chương trình của ta dễ đọc hơn.
> 
> Giả sử ta cần in cặp giá trị của `pair` trong một mảng, thay vì viết:
> 
> ```C++
> vector<pair<int, int>> arr;
> 
> for(auto it : arr){
> 	cout << it.first << ' ' << it.second << '\n';
> }
> ```
> 
> Ta có thể viết như sau:
> 
> ```C++
> vector<pair<int, int>> arr;
> 
> for(auto [x, y] : arr){
> 	cout << x << ' ' << y << '\n';
> }
> ```

## Vòng lặp `while`

Vòng lặp `while` thực hiện các đoạn code nếu điều kiện thoả mãn:

```C++
while ([điều kiện]){
	// code
}
```

Ví dụ với đoạn code sau:

```C++
int i = 1;
while (i <= 5){
	cout << i << ' ';
	++i;
}
```

Sẽ thực hiện các thao tác y hệt với ví dụ ở vòng lặp `for`.

### Vòng lặp `do-while`

Vòng lặp `do-while` cũng tương tự vòng lặp `while`, tuy nhiên điểm khác biệt nằm ở việc những đoạn code sẽ được thực thi rồi mới xét điều kiện.

```C++
do {
	// code
} while([điều kiện]);
```

Ví dụ:

```C++
int i = 7;
do{
	cout << i << ' ';
	++i;
} while(i <= 5);
```

Đoạn code trên sẽ in ra `7` và kết thúc vòng lặp khi xét điều kiện `i <= 5`. 
