# Ngăn xếp (Stack)

## Định nghĩa

**Stack (ngăn xếp)** là một CTDL lưu trữ các phần tử gồm 2 thao tác chính:
  - **Push**: Thêm một phần tử vào *cuối* danh sách, và
  - **Pop**: Loại bỏ phần tử ở *cuối* danh sách.

Ngoài ra, giá trị phần tử ở đỉnh stack có thể được biết bằng thao tác **Peek**. 

Ta có thể hình dung stack như một chồng đĩa: Chiếc đĩa cuối cùng được cho vào và đĩa nằm trên các đĩa còn lại và sẽ là đĩa đầu tiên được lấy ra. Quá trình này được mô tả là **Last In**, **First Out - LIFO (Vào sau, ra trước)**.

## Cài đặt 

Ta cài đặt stack bằng mảng:

- Cho một mảng `st` và chỉ số `top`.
- Để thêm một phần tử, gán `st[top]` với một giá trị và tăng chỉ số `top` lên 1. 
- Để loại bỏ một phần tử, giảm chỉ số của `top` xuống 1.
- Giá trị ở cuối mảng sẽ là giá trị ở đỉnh stack: `st[top]`
- Stack rỗng khi trong mảng không có phần tử: `top = 0`
- Kích thước của stack là số phần tử là số phần tử trong stack: `top`

```C++
const int N = 1e5 + 10; 
struct Stack{
	int st[N];
	int top = 0;
	// Các thao tác chính: push, pop
	void push(int x){
		st[++top] = x;
	}

	// Tiện thể kiểm tra có thể pop phần tử ra khỏi stack được không  
	bool pop(){ 
		if(top == 0) return 0;
		--top;
		return 1;
	}

	// Các thao tác khác: peek, isEmpty, size.
	int peek(){
		return st[top];
	}

	bool isEmpty(){
		return top == 0;
	}

	int size(){
		return top;
	}
}
```

Dễ thấy, các thao tác của stack đều có độ phức tạp thời gian là \\(O(1)\\).

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

Giống như khi ta cài đặt thủ công, các thao tác nói trên có độ phức tạp thời gian \\(O(1)\\).

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

Dưới đây là một số ứng dụng của stack.

### Xử lí các sự kiện theo trình tự LIFO

Bài ví dụ: [Backspace](https://open.kattis.com/problems/backspace).

Lời giải:

Ta dùng `string` để biểu diễn stack. Với mỗi kí tự được xét từ trái sang phải, nếu gặp dấu `<` thì xóa kí tự cuối trong xâu, nếu không thì thêm kí tự vào cuối xâu.

Bài giải:

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	string ans = "";	
	for(char c : s){
		if(c == '<') ans.pop_back();
		else ans += c;
	}
	cout << ans;

	
	return 0;
}
```

### Ký pháp nghịch đảo Ba Lan 

**Ký pháp nghịch đảo Ba Lan (Reverse Polish notation - RPN)** hay **kí pháp hậu tố (postfix notation)**, là một phương pháp viết các biểu thức toán học, với các toán tử (ta sẽ giới hạn với các toán tử cộng, trừ, nhân, chia) được viết sau các toán hạng. Từ **Ba lan** trong tên gọi dùng để chỉ quốc tịch của người phát minh ra kí pháp là [Jan Łukasiewicz](https://en.wikipedia.org/wiki/Jan_%C5%81ukasiewicz).

Giả sử ta có biểu thức được viết ở dạng **kí pháp trung tố (infix notation)** - toán tử được viết ở giữa các toán hạng:

\\[4 \times (1 + 2 \times (9 / 3) - 5)\\] 

thì khi viết theo RPN sẽ được biểu diễn thành:

\\[4\ 1\ 2\ 9\ 3\ / \times +\ 5 - \times \\]

Cái lợi của RPN chính là ta có thể tính toán một biểu thức mội cách dễ dàng trong thời gian tuyến tính. 

Ta sử dụng một stack. Khi duyệt biểu thức từ trái sang phải, nếu phần tử được xét đến là một toán hạng, ta thêm phần tử ấy vào stack. Nếu là một toán tử thì ta sẽ thực hiện việc tính 2 toán hạng ở đỉnh stack với toán tử tương ứng. Sau đó, thêm kết quả tương ứng vào stack của ta. Sau khi duyệt xong, phần tử ở đỉnh stack (đồng thời cũng là phần tử duy nhất còn trong stack) sẽ là giá trị của biểu thức.

```C++
stack<int> st;
// Giả sử xâu s là một RPN lưu các toán hạng là các số từ 
// 0 đến 9 và các toán tử và toán hạng được viết liền nhau
string s;

for(char c : s){
	if(isdigit(c)){
		st.push(c - '0');
	}else{
		int a = st.top(); st.pop();
		int b = st.top(); st.pop();
		switch (c){
			case '+': {st.push(a + b); break; }
			case '-': {st.push(a - b); break; }
			case '*': {st.push(a * b); break; }
			case '/': {st.push(a / b); break; }
		}
	}
}
cout << st.top();
```

#### Chuyển từ trung tố sang hậu tố

Để chuyển một biểu thức từ hạng trung tố sang hậu tố, ta sử dụng **thuật toán shunting yard** của Dijkstra. 

Ta có code được viết như sau:

```C++
int priority(char c){
	if (c == '*' || c == '/') return 2;
	if (c == '+' || c == '-') return 1;
	return 0; // c == '('
}

string s;
stack<char> st;
for(char c : s){
	if(isdigit(c)) {
		cout << c << ' ';
	} else if(c == '(') {
		st.push(c);
	} else if(c == ')'){
		while(st.size() && st.top() != '(') {
			cout << st.top() << ' ';
			st.pop();
		}
		st.pop();
	}
	else {
		while(st.size() && st.top() != '(' && priority(st.top()) >= priority(c)) {
			cout << st.top() << ' ';
			st.pop();
		}
		st.push(c);
	} 
}
while(st.size()) {
	cout << st.top() << ' ';
	st.pop();
}
```

Qua đoạn code trên, ta thấy thuật toán hoạt động vô cùng đơn giản trong thời gian tuyến tính. 
- Nếu phần tử đang xét là một toán hạng, ta in thẳng các toán hạng. 
- Nếu là dấu mở ngoặc, ta thêm dấu ấy vào stack. 
- Nếu là toán tử thì trước khi thêm toán hạng ấy vào stack, ta sẽ thực hiện việc in và loại bỏ các toán tử có thứ tự ưu tiên lớn hơn hoặc bằng toán tử đang xét (thứ tự ưu tiên của các toán tử cộng trừ nhân chia giống với quy tắc thực hiện tính biểu thức: nhân chia trước, cộng trừ sau, thực hiện các phép tính từ trái sang phải) cho tới khi ta không còn có thể loại bỏ toán tử khỏi stack hoặc phần tử ở đỉnh stack là dấu mở ngoặc. 
- Nếu là dấu đóng ngoặc, loại bỏ và in ra các phần tử có trong stack cho tới khi phần tử ở đỉnh là dấu mở ngoặc, và loại bỏ dấu mở ngoặc này khỏi stack. 
- Sau khi kết thúc duyệt, nếu stack không rỗng thì in nốt các toán hạng còn lại trong stack cho tới khi stack rỗng.

Ta cũng ví dụ bằng biểu thức ở đầu:

|Phần tử |Thao tác|Stack|Dữ liệu ra|Ghi chú|
|---|---|---|---|---|
|4|In số 4||4||
|\\(\times\\)|Thêm vào stack|\\(\times\\)|4||
|\\((\\)|Thêm vào stack|\\(\times\\) (|4||
|1|In số 1|\\(\times\\) (|4 1||
|+|Thêm vào stack|\\(\times\\) ( + |4 1||
|2|In số 2|\\(\times\\) ( + |4 1 2||
|\\(\times\\)|Thêm vào stack|\\(\times\\) ( + \\(\times\\)|4 1 2|Thứ hạng ưu tiên của \\(\times\\) lớn hơn +|
|\\((\\)|Thêm vào stack|\\(\times\\) ( + \\(\times\\) (|4 1 2||
|9|In số 9|\\(\times\\) ( + \\(\times\\) (|4 1 2 9||
|/|Thêm vào stack|\\(\times\\) ( + \\(\times\\) ( /|4 1 2 9||
|3|In số 3|\\(\times\\) ( + \\(\times\\) ( /|4 1 2 9 3||
|\\()\\)|In, loại bỏ các toán tử|\\(\times\\) ( + \\(\times\\)|4 1 2 9 3 / |Loại bỏ cho tới khi gặp "(", đồng thời xóa luôn "("|
|-|Thêm vào stack|\\(\times\\) ( -|4 1 2 9 3 / \\(\times\\) + |Loại bỏ các toán tử có thứ tự ưu tiên lớn hơn hoặc bằng|
|5|In ra 5|\\(\times\\) ( -|4 1 2 9 3 / \\(\times\\) + 5 ||
|\\()\\)|In, loại bỏ các toán tử |\\(\times\\)|4 1 2 9 3 / \\(\times\\) + 5 - ||
|Kết thúc|In các toán tử còn lại||4 1 2 9 3 / \\(\times\\) + 5 - \\(\times\\)||

Sau khi kết thúc thuật toán shunting yard, ta thành công chuyển đổi biểu thức từ dạng kí pháp trung tố thành kí pháp hậu tố.

### Dãy ngoặc đúng 

Ta ví dụ một bài toán: 

> Cho xâu S gồm các kí tự \\((\\) và \\()\\). Kiểm tra xem xâu S có phải là một dãy ngoặc đúng không?
>
> Định nghĩa:
> 	- Xâu rỗng là một dãy ngoặc đúng.
> 	- Nếu A là dãy ngoặc đúng thì (A) cũng là một dãy ngoặc đúng.
> 	- Nếu A và B là dãy ngoặc đúng thì AB cũng là một dãy ngoặc đúng.

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
	if(f(s)) cout << "YES\n";
	else cout << "NO\n";
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

Stack có thể được dùng để thực hiện các thuật toán đệ quy nhờ vào tính chất **LIFO**. Thực tế, khi chạy chương trình sẽ có một stack riêng biệt chịu trách nhiệm trong việc quản lí các hàm. Stack ấy được gọi là **call stack**. Khi một hàm được gọi call stack sẽ lưu các lần gọi hàm và các dữ liệu liên quan và chỉ bị xóa đi khi hàm đã thực hiện xong.

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

Trước tiên `main()` sẽ được thêm vào call stack, tiếp theo là `f(5)`, `f(4)` cho tới `f(1)`. Khi này ta có hình minh họa:

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

Sau khi hàm `f(1)` thực hiện xong, nó sẽ trả về giá trị và được xóa khỏi call stack. Tiếp đến là `f(2)`,`f(3)` tới `f(5)` và chương trình của ta đã chạy xong!

Nếu ta gọi các hàm quá nhiều, call stack sẽ tràn bộ nhớ và ta nhận về lỗi [**Stack Overflow**](https://en.wikipedia.org/wiki/Stack_overflow).

Để giải quyết việc này, ta thực hiện việc khử đệ quy. Thay vì để máy tính tự tạo một call stack, ta sẽ tự tạo call stack trong bộ nhớ chương trình của ta.

Ta có cài đặt [thuật toán DFS](../graph-theory/dfs.md) sử dụng stack:

```C++
// Giả sử ta lưu đồ thị bằng danh sách kề

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

Ta ví dụ một bài toán: 

> Cho mảng `a` có n phần tử bắt đầu từ chỉ số 1. Với mỗi phần tử trong mảng, tìm phần tử gần nhất bên trái có giá trị lớn hơn phần tử đang xét. Nếu phần tử ấy không tồn tại thì in ra `-1`.

Với cách giải thông thường, ta sẽ sử dụng 2 vòng lặp lồng nhau để giải bài toán.

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
		int id = -1; // Nếu không có phần tử thỏa mãn thì in ra -1
		for(int j = 1; j < i; ++j){
			if(a[j] > a[i]) id = j;
		}
		cout << id << ' ';
	}
	return 0;
}
```

Độ phức tạp thuật toán là \\(O(n^2)\\).

Để tối ưu thuật toán, ta thực hiện các bước sau với mọi `i` từ 1 đến n:

- Trước khi thêm vào \\(a_i\\), thực hiện loại bỏ các phần tử ở đỉnh stack cho đến khi đỉnh stack có giá trị lớn hơn \\(a_i\\) hoặc stack rỗng.
- Nếu stack rỗng, ta in giá trị thông báo không có phần tử thỏa mãn, nếu không rỗng thì in ra phần tử ở đỉnh stack.
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

Mặc dù thuật toán của ta có 2 vòng lặp lồng nhau, nhưng nếu để ý kĩ thì mỗi phần tử trong mảng sẽ được `push` một lần và `pop` nhiều nhất 1 lần. Vậy nên độ phức tạp sẽ là \\(O(n)\\).