# Thuật toán sắp xếp Tô-pô

## Thứ tự Tô-pô

**Thứ tự tô-pô (Topological Ordering)** của một đồ thị có hướng \\(G = (V, E)\\) là thứ tự sắp xếp của các đỉnh trên một đoạn thẳng sao cho với mỗi cạnh \\(uv\\), đỉnh \\(u\\) đứng trước đỉnh \\(v\\) trong thứ tự sắp xếp.

Thứ tự Tô-pô có tính ứng dụng cao trong thực tế. Ví dụ trong việc sắp xếp lịch trình, xem các đỉnh là các sự kiện, và các cạnh thể hiện rằng một sự kiện phải xảy ra trước sự kiện khác, thứ tự tô-pô sẽ cho ta biết các sự kiện nào cần phải hoàn thành trước, và cho ta một lịch trình giúp ta không bỏ lỡ một sự kiện nào.

Không phải đồ thị có hướng nào cũng có thứ tự tô-pô. Nếu đồ thị xuất hiện chu trình, việc tìm thứ tự tô-pô là điều không thể, bởi vì các đỉnh trong chu trình không thể đứng trước một đỉnh khác cũng nằm trong chu trình ấy. Chỉ có [**DAG**](overview.md#directed-acyclic-graph-dag) là dạng đồ thị có một hoặc nhiều thứ tự tô-pô.

## Thuật toán

Có hai cách chính giúp ta thực hiện sắp xếp tô-pô của một đồ thị có hướng \\(G\\): DFS và thuật toán Kahn. Ta sẽ tìm hiểu vè hai thuật toán này. Ta giả sử \\(G\\) là một DAG.

### DFS 

Ta có thể thực hiện sắp xếp tô-pô bằng thuật toán [DFS](dfs.md). 

Với mỗi đỉnh chưa được ghé thăm, ta thực hiện DFS. Ở cuối hàm DFS, ta sẽ thêm đỉnh ấy vào một danh sách. Danh sách đấy sẽ chứa thứ tự tô-pô đảo. 

```C++
vector<int> topo;
void toposort(int u){
	vst[u] = 1;
	for(int v : adj[u]){
		if(vst[v]) continue;
		toposort(v);
	}	
	topo.push_back(u);
}
```

Độ phức tạp thuật toán: \\(O(|V| + |E|)\\).

### Thuật toán Kahn

Thuật toán Kahn là một thuật toán sắp xếp tô-pô.

Thuật toán có cách thức hoạt động khá đơn giản:
- Chọn một đỉnh \\(u\\) bất kì trong đồ thị có bán bậc vào bằng \\(0\\). Sau khi thêm đỉnh \\(u\\) vào danh sách thứ tự tô-pô, xóa đỉnh \\(u\\) khỏi đồ thị và các cạnh có đỉnh đầu mút bằng \\(u\\).
- Lặp lại quá trình trên cho tới khi không còn đỉnh trong đồ thị.

```C++
int indegree[N]; // bán bậc vào của đỉnh u
vector<int> topo;
void Kahn(){
	for(int i = 1; i <= n; ++i){
		for(int u : adj[i]) ++indegree[u];
	}
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0) q.push(i);
	}
	while(q.size()){
		int u = q.front(); q.pop();
		topo.push_back(u);
		for(int v : adj[u]){
			if(--indegree[v] == 0){
				q.push(v);
			}
		}
	}
}

```

Độ phức tạp thuật toán: \\(O(|V| + |E|)\\)

## Kiểm tra DAG

Để tìm thứ tự tô-pô của một đồ thị có hướng, ta cần xác định nếu đồ thị có xuất hiện chu trình hay không. Nếu có chu trình, ta không thể tìm được thứ tự tô-pô và nếu không thì ngược lại

Đối với DFS, ta cần phát hiện sự tồn tại của [chu trình](graph-traversal-applications.md#phát-hiện-chu-trình) trong đồ thị nếu muồn tìm thứ tự tô-pô.

Đối với thuật toán Kahn, để xác định đồ thị có phải là DAG hay không, ta chạy thuận toán và xét kích cỡ của danh sách `topo`: nếu kích thước của `topo` bằng \\(n\\), đồ thị là một DAG và tồn tại thứ tự tô-pô. Nếu điều này không xảy ra, đồ thị của ta có chu trình và không phải DAG.

