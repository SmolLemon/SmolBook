# Chia căn

Một thuật toán chia căn là một thuật toán có phép căn (\\(\sqrt{n}\\)) trong độ phức tạp của nó.

Các thuật toán chia căn là các thuật toán "vừa đủ tốt", giúp ta giải quyết các bài toán phức tạp dựa trên những nhận xét rất đơn giản có liên quan đến phép căn.

## Chia nhóm 

Ta có bài toán sau: cho một mảng \\(a\\) có \\(n \le 10^5\\) phần tử có chỉ số bắt đầu từ \\(0\\) và \\(q\\) truy vấn. Mỗi truy vấn là một trong hai thao tác:
- \\(add(u, x)\\): gán \\(a_u = x\\).
- \\(sum(l, r)\\): tính tổng các phần tử có chỉ số từ \\(l\\) đến \\(r\\).

Các CTDL như [cây phân đoạn](../data-structures/segment-tree.md) và [cây Fenwick](../data-structures/fenwick.md) có thể xử lí hai thao tác trên trong \\(O(\log{n})\\). Sử dụng chia căn, ta có thể xử lí thao tác \\(add\\) trong \\(O(1)\\) và \\(sum\\) trong \\(O(\sqrt{n})\\).

Ta thực hiện chia mảng của ta làm \\(S = \sqrt{n}\\) nhóm, phần tử thứ \\(i\\) nằm trong nhóm \\(\left\lfloor \frac{i}{S} \right\rfloor\\). Với mỗi nhóm \\(i\\), ta có các thông tin sau:
- Nhóm \\(i\\) chứa các phần tử của mảng \\(a\\) trong khoảng \\(range(i) = [i \times S, min(n, (i + 1) \times S))\\). 
- Giá trị của nhóm \\(i\\) bằng giá trị các phần tử trong nhóm \\(i\\): \\(sum(i) = \sum_{j \in range(i)} a_j\\).

Với các thông tin này, ta có thể giải quyết bài toán trên như sau: Đối với thao tác \\(add\\), ta thay đổi giá trị \\(a_u\\) và cập nhật tổng của nhóm \\(\left\lfloor \frac{u}{S} \right\rfloor\\).

Đối với thao tác \\(sum\\), gọi \\(U\\) và \\(V\\) là nhóm của phần tử \\(l\\) và \\(r\\). Ta có giá trị của \\(sum\\) được tính là tổng của các giá trị sau:
- Tổng của các nhóm từ \\(U + 1\\) đến \\(V - 1\\).
- Tổng các phần tử trong khoảng \\([l, (U + 1) \times S)\\).
- Tổng các phần tử trong khoảng \\([V \times S, r]\\).

Nếu \\(U = V\\), ta có thể duyệt các phần tử từ \\(l\\) đến \\(r\\) để tính tổng. 

Độ phức tạp của thuật toán trên được phân tích như sau:
- Đối với thao tác \\(add\\), vì ta chỉ thay đổi giá trị của hai biến (giá trị của \\(a_u\\) và giá trị của nhóm mà nó nằm trong) nên ta có độ phức tạp \\(O(1)\\).
- Đối với thao tác \\(sum\\), ta thấy:
	- Số lượng nhóm không quá \\(\frac{n}{S} = \sqrt{n}\\).
	- Số lượng phần tử trong nhóm không quá \\(S = \sqrt{n}\\).

	Do đó, khi thực hiện thao tác tính tổng cho hàm \\(sum\\), số thao tác sẽ không vượt quá \\(O(\sqrt{n})\\).

## Chia "nặng", "nhẹ"

Ta có bài toán sau: cho một cây \\(G = (V, E)\\) có \\(n = |V| \le 10^5\\) đỉnh cạnh và \\(q\\) truy vấn. Mỗi truy vấn là một trong hai thao tác:
- \\(add(u, x)\\): thêm các đỉnh kề với \\(u\\) một giá trị \\(x\\).
- \\(find(u)\\): trả về giá trị của đinh \\(u\\). 

Theo [bổ đề bắt tay](../graph-theory/graph.md#Đỉnh-kề-cạnh-liền-thuộc-đỉnh), ta có: \\[\sum_{u \in V} deg(u) = 2(n-1)\\]

Từ đây, với \\(S = \sqrt{2n}\\), ta chia các đỉnh ra làm **hai** nhóm:
- Nhóm đỉnh **nhẹ**: \\(deg(u) \le S\\). Với số lượng đỉnh kề nhỏ, ta có thể thực hiện thao tác truy vấn \\(add\\) trong \\(O(S)\\).  
- Nhóm đỉnh **nặng**: \\(deg(u) \gt S\\). Ta có thể xác định được số lượng đỉnh trong nhóm này không quá \\(O(\sqrt{n})\\). Khi này, thay vì thực hiện truy vấn giống như nhóm đỉnh nhẹ, ta cho các đỉnh trong nhóm đỉnh nặng một biến `heavy` và cộng \\(x\\) vào biến `heavy` này.

Để trả lời truy vấn thao tác \\(find\\), ta cộng giá trị của đỉnh \\(u\\) với giá trị `heavy` của tất cả các đỉnh thuộc nhóm đỉnh nặng kề với đỉnh \\(u\\) để ra đáp án.

Độ phức tạp thuật toán là \\(O(q\sqrt{n})\\).

## Tổng các số 

Một số thuật toán chia căn sử dụng nhận xét sau: nếu ta phân tích \\(n\\) thành tổng các số nguyên dương thì sẽ không có quá \\(O(\sqrt{n})\\) số nguyên dương *phân biệt*. Để tối đa hoá số lượng số, ta chọn các số tự nhiên đầu tiên: \\(1, 2, \cdots, k\\), tổng của các số này bằng: \\[\frac{k(k+1)}{2}\\]

Do đó, \\(k\\) sẽ không vượt quá \\(O(\sqrt{n})\\).

### Bài toán ghép xâu

### Bài toán cái túi

## Chia nhóm truy vấn

## Thuật toán Mo