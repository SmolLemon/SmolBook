# Hàng đợi (Queue)

## Định nghĩa

**Queue (hàng đợi)** là một cấu trúc dữ liệu lưu trữ các phần tử gồm 2 thao tác chính:

- **Push**: Thêm một phần tử vào *cuối* danh sách, và
- **Pop**: Loại bỏ phần tử ở *đầu* danh sách

Ta hiểu về queue giống như một queue (hàng đợi) ở ngoài đời vậy: Người đầu tiên xếp vào hàng sẽ là người đầu tiên ra khỏi hàng đợi, người thứ hai vào hàng sẽ là người thứ hai ra khỏi đó, v.v. Vì tích chất này, queue còn được gọi là danh sách **First In**, **First out - FIFO (Vào trước, ra trước)**. 

## Queue trong thư viện chuẩn

Ta có thể sử dụng queue trong C++ bằng cách khai báo thư viện `<queue>`.

Khai báo queue:

```C++
queue<kiểu_dữ_liệu> Tên_queue;
```

Các phương thức phổ biến của queue:

- `push(x)`: Thêm phần tử `x` vào queue
- `pop()`: Loại bỏ một phần tử ở đầu queue
- `front()`: Trả về giá trị của phần tử ở đầu queue
- `back()`: Trả về giá trị của phần tử ở cuối queue
- `empty()`: Trả về giá trị đúng nếu queue không có phần tử và ngược lại
- `size()`: Trả về số phần tử trong queue

Các thao tác đều có độ phức tạp \\(O(1)\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    st.push(1);
    st.push(10);
    st.push(5);
    st.push(3);
    cout << st.front() << '\n'; // 1
    cout << st.back() << '\n'; // 3
    st.pop();
    cout << st.front() << '\n'; // 10
    cout << st.size() << '\n'; // 3
    cout << st.empty() << '\n'; // 0
    return 0;
}
```

## Ứng dụng

Một trong những thuật toán sử dụng hàng đợi là [thuật toán BFS](../graph-theory/bfs.md).