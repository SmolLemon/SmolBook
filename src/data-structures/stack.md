# Ngăn xếp (Stack)

**Stack (ngăn xếp)** là một CTDL lưu trữ các phần tử gồm \\(2\\) thao tác chính:
  - **Push**: Thêm một phần tử vào *cuối* danh sách, và
  - **Pop**: Loại bỏ phần tử ở *cuối* danh sách.

Ngoài ra, giá trị phần tử ở đỉnh stack có thể được biết bằng thao tác **Peek**. 

Ta có thể hình dung stack như một chồng đĩa: chiếc đĩa cuối cùng được cho vào và đĩa nằm trên các đĩa còn lại và sẽ là đĩa đầu tiên được lấy ra. Quá trình này được mô tả là **Last In**, **First Out - LIFO (Vào sau, ra trước)**.

## Stack trong thư viện chuẩn 

Để sử dụng stack trong thư viện chuẩn, ta khai báo thư viện `<stack>` trong C++.

Khai báo stack:

```C++
stack<kiểu_dữ_liệu> Tên_stack;
```

Các phương thức phổ biến của stack:

- `push(x)`: Thêm phần tử `x` vào stack
- `pop()`: Loại bỏ một phần tử ở đầu stack
- `top()`: Trả về giá trị của phần tử ở đỉnh stack
- `empty()`: Trả về giá trị đúng nếu stack không có phần tử và ngược lại
- `size()`: Trả về số phần tử trong stack

Các thao tác nói trên có độ phức tạp thời gian \\(O(1)\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> st;
	st.push(1);
	st.push(20);
	st.push(3);
	cout << st.top() << '\n'; // 3
	st.pop();
	cout << st.top() << '\n'; // 20
	cout << st.size() << '\n'; // 2
	cout << st.empty() << '\n'; // 0

	
	return 0;
}
```

Ta cũng có thể cài stack bằng cách sử dụng `vector`.

Ta có:
- `push_back(x)` = `push(x)`
- `pop_back()` = `pop()`
- `back()` = `top()`

## Ứng dụng

Dưới đây là một số ứng dụng của stack trong lập trình thi đấu.

### Dãy ngoặc đúng 

Ta ví dụ một bài toán: cho xâu S gồm các kí tự \\((\\) và \\()\\). Kiểm tra xem xâu S có phải là một dãy ngoặc đúng không?

Định nghĩa của một dãy ngoặc đúng:
- Xâu rỗng là một dãy ngoặc đúng.
- Nếu A là dãy ngoặc đúng thì (A) cũng là một dãy ngoặc đúng.
- Nếu A và B là dãy ngoặc đúng thì AB cũng là một dãy ngoặc đúng.

**Ý tưởng**: Duyệt qua từng dấu ngoặc trong dãy ngoặc. Nếu gặp dấu ngoặc mở thì thêm vào stack, nếu là dấu ngoặc đóng thì loại bỏ một dấu ngoặc mở trong stack. Dãy ngoặc sẽ không được gọi là dãy ngoặc đúng nếu trong lúc duyệt đến dấu ngoặc đóng thì stack rỗng hoặc sau khi duyệt xong thì stack không rỗng.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool f(string &s);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	if(f(s)) cout << "YES";
	else cout << "NO";
	return 0;
}

bool f(string &s){
	stack<bool> st;
	for(char c : s){
		if(c == '(') st.push(1);
		else{
			if(st.empty()) return 0;
			st.pop();
		}
	}
	return st.empty();
}
```

### Khử đệ quy bằng stack

Stack có thể được dùng để thực hiện các thuật toán đệ quy nhờ vào tính chất **LIFO**. Thực tế, khi chạy chương trình sẽ có một stack riêng biệt chịu trách nhiệm trong việc quản lí các hàm. Stack ấy được gọi là **call stack**. Khi một hàm được gọi call stack sẽ lưu các lần gọi hàm và các dữ liệu liên quan và chỉ bị xoá đi khi hàm đã thực hiện xong.

Ta ví dụ với hàm tính giai thừa:

```C++
#include <bits/stdc++.h>
using namespace std;
int f(int n){
	if(n <= 1) return 1;
	return f(n - 1) * n;
}
int main () {
	cout << f(5) << endl;
	return 0;
}
```

Trước tiên `main()` sẽ được thêm vào call stack, tiếp theo là `f(5)`, `f(4)` cho tới `f(1)`. Khi này ta có hình minh hoạ:

```
|         |
|         |
|_________| <- f(1)
|_________| <- f(2)
|_________| <- f(3)
|_________| <- f(4)
|_________| <- f(5)
|_________| <- main()
```

Sau khi hàm `f(1)` thực hiện xong, nó sẽ trả về giá trị và được xoá khỏi call stack. Tiếp đến là `f(2)`,`f(3)` tới `f(5)` và chương trình của ta đã chạy xong!

Nếu ta gọi các hàm quá nhiều, call stack sẽ tràn bộ nhớ và ta nhận về lỗi [**Stack Overflow**](https://en.wikipedia.org/wiki/Stack_overflow).

Để giải quyết việc này, ta thực hiện việc khử đệ quy. Thay vì để máy tính tự tạo một call stack, ta sẽ tự tạo call stack trong bộ nhớ chương trình của ta.

Ta có cài đặt [thuật toán DFS](../graph-theory/dfs.md) sử dụng stack:

```C++
void dfs(int u){
	stack<int> st;
	st.push(u);
	while(st.size()){
		int u = st.top(); st.pop();
		visited[u] = 1;

		// Xử lí đỉnh u

		for(int v : adj[u]){
			if(visited[v]) continue;
			st.push(v);
		}
	}
}
```

Ta áp dụng việc khử đệ quy khi hàm đệ quy quá sâu và có thể xảy ra lỗi Stack Overflow.

### Stack đơn điệu

Stack đơn điệu là kiểu stack mà các phần tử từ đáy đến đỉnh có giá trị tăng dần hoặc giảm dần.

Ta có bài toán ví dụ: cho một mảng \\(a\\) có \\(n\\) phần tử bắt đầu từ chỉ số \\(1\\). Với mỗi phần tử trong mảng, tìm phần tử gần nhất bên trái có giá trị lớn hơn phần tử đang xét. Nếu phần tử ấy không tồn tại thì in ra \\(-1\\).

Với cách giải thông thường, ta sẽ sử dụng \\(2\\) vòng lặp lồng nhau để giải bài toán.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;	
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		int id = -1;
		for(int j = 1; j < i; ++j){
			if(a[j] > a[i]) id = j;
		}
		cout << id << ' ';
	}
	return 0;
}
```

Độ phức tạp thuật toán là \\(O(n^2)\\).

Để tối ưu thuật toán, ta thực hiện các bước sau với mọi \\(i\\) từ \\(1\\) đến \\(n\\):

- Trước khi thêm vào \\(a_i\\), thực hiện loại bỏ các phần tử ở đỉnh stack cho đến khi đỉnh stack có giá trị lớn hơn \\(a_i\\) hoặc stack rỗng.
- Nếu stack rỗng, ta in giá trị thông báo không có phần tử thoả mãn, nếu không rỗng thì in ra phần tử ở đỉnh stack.
- Thêm \\(a_i\\) vào stack.

Dễ thấy các giá trị trong stack sẽ tạo thành dãy đơn điệu tăng dần từ đáy đến đỉnh stack.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;	
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	stack<int> st;
	for(int i = 1; i <= n; ++i){
		while(st.size() && a[i] >= a[st.size()]) st.pop();
		if(st.empty()) cout << "-1 ";
		else cout << a[st.top()] << ' ';
		st.push(i);
	}
	return 0;
}
```

Độ phức tạp thuật toán là \\(O(n)\\).

Mặc dù thuật toán của ta có \\(2\\) vòng lặp lồng nhau, nhưng nếu để ý kĩ thì mỗi phần tử trong mảng sẽ được `push` một lần và `pop` nhiều nhất \\(1\\) lần. Vậy nên độ phức tạp sẽ là \\(O(n)\\).