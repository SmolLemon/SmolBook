# Hello world!

Trên Code::Blocks, ta tạo một dự án C++ bằng cách chọn `Create a new project -> Console application -> C++`. Sau khi đặt tên dự án, ta đã khởi tạo thành công một dự án C++.

Sau khi khởi tạo dự án, ta sẽ được chào đón bằng những dòng lệnh mặc định ở file `main.cpp`.

```C++
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
```

Ấn `F9` và chương trình sẽ hiện lên một console có in chữ `Hello world!` ở trên đó.

Ta sẽ phân tích từng dòng lệnh của chương trình trên.

```C++
#include <iostream>
```

Trình biên dịch sẽ thêm header `iostream` chứa các phương pháp nhập xuất từ *thư viện chuẩn* của C++. **Standard Template Library (STL)** hay thư viện chuẩn của C++ bao gồm template (khuôn mẫu) của các thuật toán, cấu trúc dữ liệu mà ta có thể sử dụng trong chương trình của ta. Với STL, ta không cần phải tự viết các khái niệm này. Ví dụ, thư viện `stack` có sẵn CTDL [stack](../data-structures/stack.md) để ta sử dụng thay vì phải tự viết.

> Để thuận tiện hơn khi lập trình, ở đầu chương trình C++, ta thêm header đặc biệt
> 
> ```C++
> #include <bits/stdc++.h>
> ```
>
> Header này thêm rất nhiều header khác trong C++, giúp ta không cần phải lăn tăn nên thêm thư viện nào cho chương trình.

Dòng thứ ba,

```C++
using namespace std;
```

nói với trình biên dịch rằng ta sử dụng những đoạn code từ thư viện chuẩn (**st**an**d**ard library - **std**). Nếu không có câu lệnh này, ta cần phải viết rõ rằng ta muốn sử dụng những đoạn code từ thư viện chuẩn bằng `std::` (`std::cout`, `std::endl`, ...).

Dòng thứ năm định nghĩa hàm **main**. Trình biên dịch sẽ tìm và chạy hàm main của ta khi biên dịch chương trình. 

Dưới hàm main, ta có câu lệnh

```C++
    cout << "Hello world!" << endl;
```

in `Hello world!` ra console và xuống dòng với `endl`.

Ở cuối hàm main, ta có 

```C++
	return 0;
```

kết thúc hàm bằng cách trả về giá trị \\(0\\). Đối với hàm main, việc trả về \\(0\\) giúp nói với trình biên dịch rằng: Chương trình của ta chạy trơn tru. Ở các phiên bản mới hơn của C++ (có cả phiên bản C++14   ), ta có thể bỏ qua câu lệnh này.

Ta để ý rằng các câu lệnh trong chương trình C++ luôn kết thúc bằng dấu chấm phẩy (;).

Ta có thể thêm chú thích vào chương trình mà không làm ảnh hưởng đến việc biên dịch.

```C++
#include <iostream>

using namespace std;

int main()
{
    // Các kí tự sau "//" sẽ không làm ảnh hưởng đến chương trình
    cout << "Hello world!" << endl;
    return 0;
}
/*
    Đây là một chú thích
*/
```