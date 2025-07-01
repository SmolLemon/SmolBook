# Kiến thức nền tảng

Ta sẽ nói về một số kiến thức nền tảng về toán học trong lập trình thi đấu.

## Các kiến thức cần biết

Toán học là một lĩnh vực rộng lớn và phức tạp, trải dài từ những con số cơ bản đến những cấu trúc trừu tượng nhất của vũ trụ. Trong chương này, ta chỉ tập trung vào những kiến thức toán học được sử dụng phổ biến trong lập trình thi đấu. Toàn bộ nội dung trong *[Chương trình Giáo dục Phổ thông môn Toán năm 2018](<3. CT_Toan.pdf>)* là kiến thức *bắt buộc* cần phải biết khi đọc chương này. Một số khái niệm sẽ được giải thích lại để hiểu rõ nhằm áp dụng vào phần **cài đặt thuật toán**.

## Công thức tính tổng

Một số công thức tính tổng của các dãy số vô cùng hữu ích mà ta nên biết:

Tổng các số từ \\(1\\) đến \\(n\\): \\[1 + 2 + \dots + n = \frac{n(n + 1)}{2}\\]

Tổng bình phương các số từ \\(1\\) đến \\(n\\): \\[1^2 + 2^2 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}\\]

Tổng \\(n\\) số đầu tiên của một dãy cấp số cộng (dãy cấp số cộng \\((u_n)\\) có công sai \\(d\\) là một dãy số có dạng: \\((u_1, u_1 + d, u_1 + 2d, u_1 + 3d, \dots, u_1 + (n - 1)d, \dots)\\)): \\[u_1 + u_2 + \dots + u_n = \frac{n(u_1 + u_n)}{2} = \frac{n[2u_1 + (n - 1)d]}{2}\\]

Tổng \\(n\\) số đầu tiên của một dãy cấp số nhân (dãy cấp số nhân \\((u_n)\\) có công bội \\(q\\) là một dãy số có dạng: \\((u_1, u_1 \times q, u_1 \times q^2, u_1 \times q^3, \dots, u_1 \times q^{n - 1}, \dots)\\)): \\[u_1 + u_2 + \dots + u_n = \frac{u_1(q^n - 1)}{q - 1}\\]

Từ công thức tính tổng của dãy cấp số nhân trên, ta có thể tính nhanh tổng của \\(n\\) luỹ thừa đầu tiên của \\(2\\): \\[2^0 + 2^1 + \dots + 2^{n - 1} = 2^n - 1\\]

## Lí thuyết tập hợp

**Tập hợp** là một *khái niệm cơ bản* (không định nghĩa) trong toán học. Các đối tượng có chung một hay nhiều tính chất quy tụ lại thành một tập hợp, với mỗi đối tượng là một phần tử. Để chỉ một phần tử \\(a\\) là một phần tử nằm trong một tập hợp \\(A\\), hay phần tử \\(a\\) thuộc tập hợp \\(A\\), ta kí hiệu \\(a \in A\\). Ngược lại, ta có kí hiệu \\(a \notin A\\) để chỉ phần tử \\(a\\) không thuộc tập hợp \\(A\\). 

Ta kí hiệu số phần tử trong tập hợp \\(A\\) là \\(|A|\\). Một tập hợp không có phần tử nào được gọi là một **tập rỗng**, kí hiệu là \\(\emptyset\\).

Tập hợp \\(A\\) là một **tập hợp con** của tập hợp \\(B\\) nếu mọi phần tử của tập hợp \\(A\\) đều là phần tử của tập hợp \\(B\\), kí hiệu là \\(A \subset B\\). Hai tập hợp được gọi là hai tập hợp bằng nhau nếu nếu mọi phần tử của tập hợp \\(A\\) đều là phần tử của tập hợp \\(B\\) và ngược lại, kí hiệu là \\(A = B\\). 

Một tập hợp \\(A\\) có \\(|A|\\) phần tử sẽ có tổng cộng \\(2^{|A|}\\) tập con. Ví dụ với tập hợp \\(A = \\{1, 3, 4\\}\\), ta có các tập con: \\[\emptyset, \\{1\\}, \\{3\\}, \\{4\\}, \\{1, 3\\}, \\{1, 4\\}, \\{3, 4\\}, \\{1, 3, 4\\}\\]

Ta có các tập hợp số:
- Tập hợp số tự nhiên: \\(\mathbb{N} = \\{0, 1, 2, 3, \dots\\}\\)
- Tập hợp số nguyên: \\(\mathbb{Z} = \\{\dots, -3, -2, -1, 0, 1, 2, 3, \dots\\}\\)
- Tập hợp số hữu tỉ: \\(\mathbb{Q} = \\{\frac{1}{2}, \frac{7}{5}, \frac{16}{9}, \dots\\}\\)
- Tập hợp số vô tỉ: \\(\mathbb{R} = \\{\sqrt{2}, \pi, e, \dots\\}\\)

Mỗi quan hệ của các tập hợp số: \\(\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R}\\).

Có hai cách để mô tả một tập hợp:
- Cách \\(1\\): liệt kê các phần tử của tập hợp. Ta có ví dụ về một tập hợp \\(A = \\{1, 2, 3, 4, 5\\}\\)
- Cách \\(2\\): chỉ ra tính chất đặc trưng cho các phần tử của tập hợp. Quay lại với tập hợp \\(A\\), ta có thể viết lại thành \\(A = \\{x \in N | 1 \le x \le 5\\}\\)

Ta có các phép toán trên tập hợp:
- **Giao của hai tập hợp**: Tập hợp gồm các phần tử nằm trong cả hai tập hợp \\(A\\) và \\(B\\) được gọi là **giao của hai tập hợp** \\(A\\) và \\(B\\), kí hiệu là \\(A \cap B\\). \\[A \cap B = \\{x | x \in A\ và\ x \in B\\}\\]
- **Hợp của hai tập hợp**: Tập hợp gồm các phần tử nằm trong cả tập hợp \\(A\\) hoặc tập hợp \\(B\\) hoặc cả hai tập hợp được gọi là **hợp của hai tập hợp** \\(A\\) và \\(B\\), kí hiệu là \\(A \cup B\\). \\[A \cup B = \\{x | x \in A\ hoặc\ x \in B\\}\\]
- **Hiệu của hai tập hợp**: Tập hợp gồm các phần tử nằm trong cả tập hợp \\(A\\) và không nằm trong tập hợp \\(B\\) được gọi là **hiệu của hai tập hợp**, kí hiệu là \\(A \backslash B\\). \\[A \backslash B = \\{x | x \in A\ và\ x \notin B\\}\\]
	Nếu \\(B \subset A\\) thì \\(A \backslash B\\) được gọi là **phần bù** của \\(B\\) trong \\(A\\), kí hiệu là \\(C_A{B}\\).

Một kĩ thuật hữu ích quan trọng trong việc đếm các phần tử của hợp của hai hoặc nhiều tập hợp chính là kĩ thuật [bao hàm - loại trừ](https://vi.wikipedia.org/wiki/Nguy%C3%AAn_l%C3%BD_bao_h%C3%A0m-lo%E1%BA%A1i_tr%E1%BB%AB). Ví dụ, với hai tập hợp \\(A, B\\), ta có: \\[|A \cup B| = |A| + |B| - |A \cap B|\\]

Ta có công thức tính hợp cho \\(3\\) tập hợp \\(A, B, C\\): \\[|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|\\]

Ta có công thức tổng quát để tính hợp của \\(n\\) tập hợp \\(A_1, A_2, \dots, A_n\\): \\[\bigcup_{i = 1}^n A_i = \sum_{J \subset \\{1, 2, \dots, n\\}} (-1)^{|J| + 1}|\bigcap_{j \in J} A_j|\\]