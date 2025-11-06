# Quy hoạch động trên cây

**Quy hoạch động trên cây** là một kĩ thuật QHĐ giải quyết các bài toán QHĐ liên quan đến cây.

## Lí thuyết

Xét đến tính các định nghĩa, tính chất của [cây](../graph-theory/graph.md#cây-1), ta có thể dễ dàng liên hệ nó với QHĐ:
- Một cây con của cây tương đương với các bài toán con của QHĐ.
- Các cây con có gốc là một đỉnh có thể thuộc các cây con có gốc là các đỉnh tổ tiên của đỉnh đó. Điều này giống với tính chất *các bài toán con gối nhau* của QHĐ.
- Giá trị của đỉnh lá tương đương với các trường hợp cơ sở.

Vì vậy, ta có cách giải quyết các bài toán QHĐ trên cây một cách tổng quát như sau:
- Tính kết quả ở các đỉnh lá.
- Với mỗi đỉnh trên cây, ta tính kết quả của đỉnh này dựa trên  thông tin về chính đỉnh đó và kết quả của các đỉnh con của nó.
- Kết quả của đỉnh gốc là kết quả của bài toán.

Để tìm phương pháp giải quyết các bài toán QHĐ trên cây, trươc hết ta thử xét trường hợp cây của ta là [cây tre](../graph-theory/tree.md#cây-suy-biến). Bài toán giờ đây chuyển thành giải quyết bài toán QHĐ trên một mảng một chiều. Sau đó, ta có thể suy ra dạng tổng quát của bài toán.

### Kĩ thuật chuyển gốc

**Kĩ thuật chuyển gốc** là kĩ thuật được sử dụng khi ta cần tính kết quả cho từng trường hợp riêng biệt, khi một đỉnh bất kì trong cây được chọn làm đỉnh gốc. Thay vì thực hiện việc tính kết quả với *từng* đỉnh được chọn là gốc, ta chỉ cần thực hiện việc tính toán cho cây một lần và thực hiện chuyển đỉnh gốc của cây.

Việc chuyển gốc từ đỉnh \\(u\\) sang một đỉnh con \\(v\\) diễn ra như sau:
- **Tách**: tách đỉnh \\(v\\) khỏi các đỉnh con của đinh \\(u\\). Khi này, ta có hai cây riêng biệt, một cây gốc \\(u\\) và một cây gốc \\(v\\). Tính lại kết quả của đỉnh \\(u\\) sau khi tách.
- **Cập nhật**: Gán đỉnh \\(u\\) là đỉnh con của \\(v\\). Việc chuyển gốc đã thành công, và cây con gốc \\(u\\) bây giờ là một phần của cây con gốc \\(v\\). Ta tính lại kết quả của cây con gốc \\(v\\) sau khi thêm đỉnh \\(u\\) là đỉnh con.
- **Khôi phục**: Sau khi chuyển gốc thành công, ta khôi phục cây về lại trạng thái trước đó.

Với kiến thức trên, ta có thể xử lí các bài toán yêu cầu kĩ thuật chuyển gốc như sau: trước hết ta cho đỉnh \\(u\\) ta đang xét là đỉnh gốc. Sau đó ta chuyển gốc sang từng đỉnh con \\(v\\) của nó và duyệt các cây con. Sau khi duyệt xong, ta khôi phục lại cây sao cho đỉnh gốc là đỉnh \\(u\\) và duyệt các đỉnh con tiếp theo.

## Vận dụng

### Bài 1: Nhánh có tổng lớn nhất

Bài toán tìm nhánh có tổng lớn nhất cho ta một cây có đỉnh gốc là \\(1\\), với giá trị \\(a_u\\) được gán trên mỗi đỉnh \\(u\\). Bài toán yêu cầu ta tìm con đường từ đỉnh gốc tới một đỉnh trên cây sao cho giá trị các đỉnh trên đường đi là lớn nhất.

Nếu nhìn ở dạng cây tre, ta thấy bài toán này tương tự với bài toán [dãy con có tổng lớn nhất](../paradigms/dp.md#dãy-con-có-tổng-lớn-nhất). Từ đây, với \\(f(u)\\) là trị lớn nhất trong các đường đi từ đỉnh \\(u\\) đến các đỉnh con thuộc cây con gốc \\(u\\), ta có công thức:

\\[f(u) = \max_{v \in child(u)}(a_u, f(v) + a_u)\\]

Với \\(child(u)\\) là tập hợp chứa các đỉnh con của \\(u\\) trên cây.

Trường hợp cơ sở của \\(f(u)\\) là \\(f(u) = a_u\\) với \\(u\\) là đỉnh lá.

Kết quả của bài toán sẽ là \\(f(1)\\).

```C++
vector<int> child[N]; // tập hợp chứa các đỉnh con 
int dp[N];
int a[N];

void dfs(int u) {
	dp[u] = a[u];
	for(int v : child[u]) {
		dfs(v);
		dp[u] = max(dp[u], dp[v] + a[u]);
	}
}

int solve() {
	dfs(1);
	return dp[1];
}
```

Độ phức tạp thuật toán là \\(O(n)\\) với \\(n = |V|\\).

### Bài 2: Tập hợp có tổng lớn nhất

Bài toán tìm tập hợp có tổng lớn nhất cho ta một cây có đỉnh gốc là \\(1\\), với giá trị \\(a_u\\) được gán trên mỗi đỉnh \\(u\\). Bài toán yêu cầu ta tìm tập hợp các đỉnh thuộc cây sao cho không có cặp đỉnh nào trong tập hợp có cạnh nối hai đỉnh và tổng giá trị của nó là lớn nhất.

Ta có \\(f(t, u)\\) chỉ kết quả khi thêm (\\(t = 1\\)) hoặc không thêm (\\(t = 0\\)) đỉnh \\(u\\) vào tập hợp của ta. Nếu ta thêm đỉnh \\(u\\) vào tập hợp, ta *không thể* thêm bất kì đỉnh con nào của \\(u\\) vào tập hợp. Ngược lại, nếu ta không thêm đỉnh \\(u\\), ta có thể tuỳ ý thêm hoặc không thêm các đỉnh con của nó, miễn sao kết quả cuối cùng là lớn nhất.

Từ nhận xét trên, ta có công thức cho hàm \\(f(t, u)\\): 

\\[
\begin{align*}
f(0, u) &= \sum_{v \in child(u)} max(f(0, v), f(1, v)) \\\\ 
f(1, u) &= a_u + \sum_{v \in child(u)} f(0, v)
\end{align*}
\\]


Trường hợp cơ sở: \\(f(0, u) = 0\\), \\(f(1, u) = a_u\\).

Kết quả của bài toán là \\(max(f(0, 1), f(1, 1))\\).

```C++
vector<int> child[N];
int dp[2][N];
int a[N];

void dfs(int u) {
	dp[1][u] = a[u];
	dp[0][u] = 0;
	for(int v : child[u]) {
		dfs(v);
		dp[1][u] += dp[0][v];
		dp[0][u] += max(dp[0][v], dp[1][v]);
	}
}

int solve() {
	dfs(1);
	return max(dp[0][1], dp[1][1]);
}
```

Độ phức tạp thuật toán là \\(O(n)\\).

### Bài 3: Knapsack trên cây