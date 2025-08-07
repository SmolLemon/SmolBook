# Thuật toán tìm kiếm theo chiều sâu

**Thuật toán tìm kiếm theo chiều sâu (Depth-First Search - DFS)** là một thuật toán tìm kiếm trên đồ thị.

## Thuật toán

Xuất phát từ một đỉnh \\(u\\), thuật toán DFS sẽ thực hiện việc duyệt đồ thị *theo chiều sâu (depth-first)*. Ở mỗi bước, thuật toán sẽ chọn một đỉnh bất kì kề với đỉnh \\(u\\) mà chưa được duyệt. Sau đó, thuật toán sẽ thực hiện việc duyệt DFS một cách đệ quy đối với đỉnh ấy. Quá trình sẽ lặp lại cho đến khi tất cả hàng xóm của \\(u\\) đã được duyệt. Khi này, thuật toán "quay lui" và tiếp tục với các đỉnh hàng xóm chưa được duyệt khác, nếu có.

Ta có một đồ thị vô hướng:

<center>
<img src="../images/simple_graph.svg" alt="Đơn đồ thị"/>
</center>

Giả sử ta bắt đầu thực hiện DFS từ đỉnh \\(1\\), quá trình của thuật toán sẽ diễn ra như sau: \\(1 \rightarrow 2 \rightarrow 5 \rightarrow\\) (quay lui về \\(2\\)) \\(\rightarrow 6 \rightarrow\\) (quay lui về \\(2\\)) \\(\rightarrow 3 \rightarrow 4 \rightarrow\\) (quay lui về \\(3\\)) \\(\rightarrow\\) (quay lui về \\(2\\)) \\(\rightarrow\\) (quay lui về \\(1\\)).

Khi thực hiện thuật toán DFS, ta nhận thấy mỗi đỉnh của đồ thị sẽ được duyệt nhiều nhất \\(1\\) lần, và mỗi cạnh sẽ được duyệt nhiều nhất \\(2\\) lần đối với đồ thị vô hướng, hoặc \\(1\\) lần đối với đồ thị có hướng. 

Tùy vào cách tổ chức đồ thị mà nó sẽ anh hưởng đến độ phức tạp của thuật toán DFS, với các độ phức tạp thời gian \\(O(|V|^2)\\), \\(O(|V| + |E|)\\), \\(O(|V|\times |E|)\\) nếu ta sử dụng ma trận kề, danh sách kề hoặc danh sách cạnh theo thứ tự tương ứng.

Nếu đồ thị liên thông, độ phức tạp thời gian của DFS và BFS có thể viết gọn thành \\(O(|E|)\\).

## Cài đặt

Việc cài đặt DFS là một việc vô cùng đơn giản. Một chương trình thực hiện DFS điển hình sẽ sử dụng một mảng giá trị `vst` chứa \\(n\\) phần tử (\\(n\\) là số lượng đỉnh trong đồ thị) biểu thị nếu đỉnh \\(u\\) đã được duyệt hay chưa, và một danh sách kề `adj` lưu thông tin về đồ thị:

```C++
void dfs(int u){
	if(vst[u]) return;
	vst[u] = 1;

	// xử lí đỉnh u
	
	for(int v : adj[u]){
        dfs(v);
    } 
}
```

### Cài đặt bằng stack

Như đã được nói ở phần [stack](../data-structures/stack.md#khử-đệ-quy-bằng-stack), ta có thể cài đặt DFS bằng cách sử dụng stack, mặc dù cách cài đặt này không phổ biến bằng cách cài đặt ở trên.

```C++
void dfs(int s){
    stack<int> st;
    st.push(s);
    while(st.size()){
        int u = st.top(); st.pop();
        if(vst[u]) continue;
        vst[u] = 1;

        // Xử lí đỉnh u

        for(int v : adj[u]){
            st.push(v);
        }
    }
}
```