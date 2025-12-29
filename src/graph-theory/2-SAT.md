# 2-SAT

Ta nói một công thức ở **dạng chuẩn hội (conjunctive normal form - CNF)** nếu nó là phép hội (AND, \\(\land\\)) của một hoặc nhiều mệnh đề, mỗi mệnh đề là phép giao (OR, \\(\lor\\)) của các giá trị đúng/sai.

Ví dụ, ta có một công thức dạng chuẩn hội sau: \\[C = (a \lor b) \land (c) \land (\lnot d \lor e \lor f)\\]

Bài toán 2-SAT là bài toán cho ta các biến \\((x_1, x_2, \cdots, x_n)\\), và nhiệm vụ của ta là gán các giá trị đúng/sai sao cho công thức dạng chuẩn hội của ta hợp lệ, tức là \\(C = true\\). Điều đặc biệt ở công thức dạng chuẩn hội trong bài tác 2-SAT là mỗi mệnh đề phải có đúng \\(2\\) giá trị.

Ví dụ, với công thức \\[C_1 = (x_1 \lor \lnot x_2) \land (\lnot x_1 \lor x_2) \land (\lnot x_1 \lor \lnot x_2) \land (x_1 \lor \lnot x_3)\\]

Ta có thể điền \\((x_1, x_2, x_3) = (0, 0, 0)\\) và công thức của ta sẽ hợp lệ.

Còn với công thức \\[C_2 = (x_1 \lor x_2) \land (x_1 \lor \lnot x_2) \land (\lnot x_1 \lor x_3) \land (\lnot x_1 \lor \lnot x_3)\\]

Thì dù có điền \\((x_1, x_2, x_3)\\) là giá trị gì thì công thức vẫn sẽ không hợp lệ.

## Thuật toán

Bằng việc phân tách mệnh đề \\((a \\lor b)\\) thành \\(2\\) mệnh đề kéo theo \\(\lnot a \Rightarrow b\\) và \\(\lnot b \Rightarrow a\\), ta có thể biểu diễn công thức dạng chuẩn hội thành một đồ thị có hướng.

Ta có đồ thị \\(G = (V, E)\\) với \\(V\\) bao gồm các đỉnh \\(x_i\\), \\(\lnot x_i\\) với mỗi biến \\(x_i\\), và các cung \\(\\{\lnot a, b\\}\\) và \\(\\{\lnot b, a\\}\\) với mỗi mệnh đề \\((a \\lor b)\\).

Từ đồ thị này ta có thể xác định nếu công thức trên có hợp lệ hay không: nếu như \\(x_i\\) và \\(\lnot x_i\\) thuộc cùng một [TPLT mạnh](graph.md#tính-liên-thông-khớp-cầu) thì công thức sẽ không hợp lệ. Nếu như vậy thì trong TPLT mạnh đó, sẽ tồn tại một đường đi từ \\(x_i\\) đến \\(\lnot x_i\\) và ngược lại, suy ra cả hai giá trị \\(x_i\\) và \\(\lnot x_i\\) sẽ là giá trị đúng. Điều này là không hợp lệ.

Để tìm giá trị của các \\(x_i\\), ta dựa vào vị trí của các nhóm TPLT mạnh trong thứ tự tô-pô của các TPLT mạnh: TPLT mạnh nào xếp sau thì các phần tử trong TPLT mạnh đó sẽ được ưu tiên gán giá trị đúng. 

Đơn giản hơn, gọi \\(id(u)\\) là vị trí của nhóm TPLT mạnh chứa đỉnh \\(u\\). Nếu \\(id(u) \lt id(\lnot u)\\), ta gán \\(u = false\\) còn \\(\lnot u = true\\). Ngược lại, Nếu \\(id(u) \gt id(\lnot u)\\), ta gán \\(u = true\\) còn \\(\lnot u = false\\).

```C++
struct TwoSat{
	vector<vector<int>> adj;
	vector<int> num, low, cc;
	vector<bool> val;
	vector<int> st;
	int n, tdfs, scc;
	bool solvable; 
	TwoSat(int sz = 0) : solvable(0), tdfs(0), scc(0), n(sz), 
	adj(sz << 1), num(sz << 1, 0), low(sz << 1, 0), cc(sz << 1, 0), val(sz, 0) {
		st.clear();
	}
	int Not(int u) {
		return u + (u < n ? n : -n);
	}
	void addClause(int u, bool notu, int v, int notv) {
		if(notu) u = Not(u);
		if(notv) v = Not(v);
		adj[Not(u)].emplace_back(v);
		adj[Not(v)].emplace_back(u);
	}
	void dfs(int u){
		// Thuật toán tìm TPLTM của Tarjan
		num[u] = low[u] = ++tdfs;
		st.emplace_back(u);
		for(int v : adj[u]) {
			if(num[v] == 0) dfs(v);
			if(cc[v] == 0) low[u] = min(low[u], low[v]);
		}
		if(num[u] == low[u]) {
			++scc; // Thứ tự tô-pô ngược của TPLTM
			for(int v; true; ) {
				v = st.back(); st.pop_back();
				cc[v] = scc;
				if(v == u) break;
			}
		}
	}
	bool solve(){
		solvable = 1;
		for(int i = 0; i < n * 2; ++i) {
			if(num[i] == 0) dfs(i); 
		}
		for(int i = 0; i < n; ++i) {
			// Nếu x_i và not(x_i) cùng một TPLTM thì công thức không hợp lệ
			if(cc[i] == cc[Not(i)]) {
				solvable = 0;
			}
		}
		for(int i = 0; i < n; ++i) val[i] = (cc[i] < cc[Not(i)]);

		return solvable;
	}
};
```

Độ phức tạp của thuật toán là \\(O(n + m)\\) với \\(n\\) là số biến, \\(m\\) là số mệnh đề trong công thức.