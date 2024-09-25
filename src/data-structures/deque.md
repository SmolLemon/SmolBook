# Hàng đợi hai đầu (Deque)

## Định nghĩa

**Hàng đợi hai đầu (Double-ended queue - deque, dequeue)** là một cấu trúc dữ liệu cho phép việc thêm và loại bỏ phần tử ở đầu và cuối phần tử. 

Deque cũng giống như một hàng đợi bình thường nhưng khác ở chỗ các phần tử ở cuối queue có thể được loại bỏ. Giống như khi bạn đi siêu thị và đứng xếp hàng tại quầy. Nếu có quá nhiều người xếp hàng chờ thanh toán thì bạn có thể rời từ cuối hàng và sang quầy khác.

## Deque trong thư viện chuẩn

Ta khai báo thư viện `<deque>` trong C++ để sử dụng deque.

Khai báo deque:

```C++
deque<kiểu_dữ_liệu> Tên_deque;
```

Các phương thức phổ biến của deque:

- Các thao tác chính:
	- `push_back(x)`: Thêm phần tử `x` vào cuối deque
	- `push_front(x)`: Thêm phần tử `x` vào đầu deque
	- `pop_back()`: Loại bỏ một phần tử ở cuối deque
	- `pop_front()`: Loại bỏ một phần tử ở đầu deque
	- `back()`: Trả về giá trị của phần tử ở cuối queue
	- `front()`: Trả về giá trị của phần tử ở đầu queue
- Các thao tác khác:
	- `at(x)`, thao tác `[]`: Trả về giá trị của phần tử trong deque tại một chỉ số
	- `empty()`: Trả về giá trị đúng nếu deque không có phần tử và ngược lại
	- `size()`: Trả về số phần tử trong deque
	- `clear()`: Xóa toàn bộ các phần tử trong deque

Các phương thức trên đều có độ phức tạp \\(O(1)\\), ngoại trừ `clear()` có độ phức tạp \\(O(n)\\).

## Ứng dụng

### Thay thế stack, queue

Với nhiều thao tác như thế, deque hoàn toàn có thể thực hiện các thao tác của stack và queue.

Thực thế, nếu bạn đọc thông tin về [stack](https://en.cppreference.com/w/cpp/container/stack) và [queue](https://en.cppreference.com/w/cpp/container/queue) trên [cppreference.com](https://cppreference.com) thì ẩn trong 2 CDTL chính là deque.  

### BFS 0 - 1

Deque được dùng để giải quyết bài toàn tìm đường đi ngắn nhất bằng BFS: [BFS 0 - 1](../graph-theory/bfs-01).

### Deque trên đoạn tịnh tiến

Ta có bài toán:

> Cho mảng `a` có n phần tử bắt đầu từ chỉ số 1. Với mỗi đoạn con có độ dài `k`, tìm phần tử nhỏ nhất với mỗi đoạn con này.

Ví dụ với `n = 9` và `k = 3` và mảng `a`:

\\[[1, 5, 6, 2, 8, 3, 4, 9]\\]

Ta có giá trị nhỏ nhất của các đoạn \\([1, 3], [2, 4], ..., [7, 9]\\) lần lượt là: 
- \\([1, 3]\\): 1
- \\([2, 4]\\): 2
- \\([3, 5]\\): 2
- \\([4, 6]\\): 2
- \\([5, 7]\\): 2
- \\([6, 8]\\): 3
- \\([7, 9]\\): 3

Có một cách giải quyết tối ưu bài toán này, áp dụng tư tưởng của [stack đơn điệu](stack.md#stack-đơn-điệu).

Với mỗi `i`, ta thêm phần tử có chỉ số `i` vào cuối deque. Trước khi thêm vào, loại bỏ các phần tử ở cuối deque có giá trị lớn hơn phần tử sẽ được thêm vào. Khi này phần tử ở đầu deque là phần tử nhỏ nhất trong khoảng tử đầu mảng đến phần tử chỉ số `i`.

Để giải quyết bài toán gốc, ta thực hiện việc xóa phần tử như sau: Xóa các phần tử ở đầu deque nếu chỉ số của phần tử ấy nhỏ hơn `i - k + 1`. Sau khi xóa xong, phần tử ở đầu deque sẽ là phần tử ở đầu hàng đợi hai đầu này.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	deque<int> dq;
	for(int i = 1; i <= n; ++i){
		while(dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push(i);
		if(i >= k) cout << a[dq.front()] << ' ';
		if(dq.front() + k <= i) dq.pop_front();
	}
	return 0;
}
``` 

Độ phức tạp của thuật toán là \\(O(n)\\).