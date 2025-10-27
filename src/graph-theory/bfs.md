# Thuật toán tìm kiếm theo chiều rộng (BFS)

**Thuật toán tìm kiếm theo chiều rộng (Breadth-First Search - BFS)** là một thuật toán tìm kiếm trên đồ thị.

## Thuật toán

Xuất phát từ đỉnh gốc \\(s\\), thuật toán BFS sẽ thực hiện việc duyệt đồ thị *theo chiều rộng (breadth-first)*. Thuật toán bắt đầu bằng việc duyệt tất cả các đỉnh hàng xóm của đỉnh \\(s\\) (lớp thứ nhất), các đỉnh kề với các đỉnh hàng xóm của đỉnh \\(s\\) (lớp thứ hai), cứ tiếp tục như thế, từng lớp một, cho tới khi ta xét hết tất cả các đỉnh có thể duyệt được từ đỉnh \\(s\\). Chính vì tính chất duyệt theo từng lớp như thế nên thuật toán còn có tên gọi khác là *thuật toán loang*.

Ta có một đồ thị vô hướng:

<center>
<img src="../images/simple_graph.svg" alt="Đơn đồ thị"/>
</center>

Giả sử ta bắt đầu thực hiện BFS từ đỉnh \\(1\\), thuật toán BFS sẽ duyệt đỉnh \\(1\\), sau đó, duyệt qua các đỉnh \\(2\\), \\(3\\) và \\(4\\), và cuối cùng là các đỉnh \\(3\\), \\(5\\) và \\(6\\).

Độ phức tạp thời gian của thuật toán BFS cũng tương tự với độ phức tạp của thuật toán DFS.

## Cài đặt

Việc cài đặt thuật toán BFS là một việc đơn giản nếu ta sử dụng [CTDL queue](../data-structures/queue.md). Ban đầu, đỉnh gốc \\(s\\) sẽ được thêm vào queue của ta. Sau đó, thuật toán sẽ thực hiện 2 bước chính:
- Lấy giá trị và loại bỏ đỉnh \\(u\\) ở đầu queue.
- Với mỗi đỉnh \\(v\\) kề với đỉnh \\(u\\) và chưa được ghé thăm: thêm đỉnh \\(v\\) vào cuối queue.

Thuật toán sẽ thực hiện việc duyệt cho tới khi tất cả các đỉnh tồn tại đường đi từ đỉnh gốc đã được ghé thăm.

```C++
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(q.size() > 0) {
		int u = q.front(); q.pop();
		if(vst[u]) continue;
		vst[u] = 1;

		// xử lí đỉnh u
		
		for(int v : adj[u]){
			q.push(v);
		}
	}
}
```
