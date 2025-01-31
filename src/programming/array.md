# Mảng

Một mảng là một kiểu dữ liệu lưu trữ một dãy một tập hợp các phần tử có cùng kiểu dữ liệu.

Ví dụ, ta có một mảng \\(a\\) với \\(8\\) phần tử:

\\[a = \\{7, 2, 6, 8, 1, 5, 3, 4\\}\\]

Khi khai báo một mảng trong C++, ta cần có thông tin về kiểu dữ liệu các phần tử, tên mảng và kich thước của một mảng.

```C++
kiểu_dữ_liệu tên_mảng[kích_thước];
```

Ví dụ, ta có môt mảng số nguyên `a` chứa \\(4\\) phần tử:

```C++
int a[4];
```

Giờ đây ta đã có \\(4\\) "biến" số nguyên để sử dụng trong chương trình. Ta có thể truy cập các phần tử của `a` bằng cú pháp `a[chỉ_số]`. Các chỉ số của mảng được bắt đầu từ chí số \\(0\\), gọi là *zero-indexed*, nên \\(4\\) phần tử trong `a` có thể được truy cập bằng cách viết `a[0]`, `a[1]`, `a[2]`, `a[3]`. Nếu ta viết các chỉ số nhỏ hơn \\(0\\) hoặc các chỉ số lớn hơn hoặc bằng kích thước mảng \\((-1, 5, \dots)\\), chương trình có thể có những hành vi kì lạ.

Ta có thể gán các giá trị cho các phần tử trong mảng khi khai báo:

```C++
int a[4] = {1, 4, 3};
```

Đoạn code trên sẽ gán \\(3\\) phần tử đầu tiên của mảng `a` với giá trị tương ứng.

Một điều nữa cần lưu ý rằng nếu ta khai báo một *mảng toàn cục (global array)* thì các phần tử trong mảng sẽ có giá trị mặc định. Nếu là mảng số nguyên thì sẽ có giá trị \\(0\\), mảng boolean thì sẽ là `false`. Mặc khác, nếu ta khai báo một mảng trong một hàm (như hàm main) thì giá trị của các phần tử trong mảng có thể có giá trị ngẫu nhiên.

## `vector`

Ngoài kiểu mảng như ở trên, được gọi là *mảng tĩnh*, C++ còn có *mảng động* `vector` có thể tùy ý thay đổi kích thước của mảng.

Ta có một mảng số nguyên động `arr`.

```C++
vector<int> arr;
```

Ta thêm phần tử cho mảng `arr` bằng `push_back` hoặc `emplace_back`

```C++
arr.push_back(1);
arr.push_back(2);
arr.emplace_back(3);
```

Ta có thể truy cập phần tử giống như mảng tĩnh. Ví dụ, `arr[2]` truy cập phần tử thứ \\(3\\) trong mảng `arr`.

`vector` còn có những câu lệnh khác như `size()` - trả về kích thước của mảng, `empty()` - trả về \\(true/false\\) nếu mảng rỗng hoặc không rỗng, `clear()` - xóa hết các phần tử trong mảng,...

`string` là một kiểu dữ liệu lưu trữ các xâu. Ta có thể xem `string` là một mảng động dành riêng cho các kí tự.