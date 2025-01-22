# Kiến thức toán cơ bản
 
Toán học có vai trò quan trọng trong lập trình thi đấu. Việc bạn giỏi toán, hoặc có khá năng tư duy toán học tốt là một lợi thế so với những người khác.

Ta sẽ nói về một số kiến thức cơ bản có tính ứng dụng cao trong lập trình thi đấu.

## Công thức tính tổng

Ta có công thức tính tổng của một số dãy số:

**Tổng của \\(n\\) số tự nhiên đầu tiên:** 

\\[1 + 2 + \dots + n = \frac{n(n + 1)}{2}\\]

**Tổng lũy thừa của \\(n\\) số tự nhiên đầu tiên:** 

\\[1^2 + 2^2 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}\\]

**Tổng của một cấp số cộng \\((u_n)\\) với số hạng đầu \\(u_1\\) và công sai \\(d\\):**

\\[u_1 + u_2 + \dots + u_n = \frac{n[2u_1 + (n - 1)d]}{2} = \frac{n(u_1 + u_n)}{2}\\]

Ví dụ: tính tổng \\(5\\) số hạng đầu tiên của một cấp số cộng \\(u_n\\) với số hạng đầu \\(4\\) và công sai \\(3\\):

\\[4 + 7 + 10 + 13 + 16 = \frac{5[2\times4 + (5 - 1)3]}{2} = \frac{5(4 + 16)}{2} = 50\\]

**Tổng của một cấp số nhân \\((u_n)\\) với số hạng đầu \\(u_1\\) và công bội \\(q \neq 1\\):**

\\[u_1 + u_2 + \dots + u_n = \frac{u_1(q^n - 1)}{q - 1}\\]

Ví dụ: tính tổng \\(4\\) số hạng đầu tiên của một cấp số nhân \\(u_n\\) với số hạng đầu \\(1\\) và công sai \\(5\\):

\\[1 + 5 + 25 + 125 = \frac{1(5^4 - 1)}{5 - 1} = 156\\]

Từ đây ta suy ra tổng của \\(n\\) lũy thừa đầu tiên của \\(2\\) bằng:

\\[1 + 2 + \dots + 2^{n - 1} = 2^n - 1\\]


## Lý thuyết tập hợp

Một tập hợp là một bộ các phần tử. Ví dụ với tập hợp \\(X\\):

\\[X = \\{2, 3, 5\\}\\]

chứa các phần tử \\(2\\), \\(3\\) và \\(5\\). 

Một tập hợp không chứa phần tử được gọi là tập rỗng. Kí hiệu là \\(\emptyset\\).

Ta sử dụng kí hiệu \\(\in\\) hoặc \\(\notin\\) để biểu thị nếu phần tử có nằm trong tập hợp hay không. Ví dụ với tập hợp \\(X\\) ở trên, \\(2\\) thuộc tập hợp \\(X\\) nên ta viết \\(2 \in X\\), \\(1\\) không thuộc tập hợp \\(X\\) nên ta viết \\(1 \notin X\\).

Ta kí hiệu số lượng các phần tử trong tập \\(X\\) là \\(|X|\\). Chẳng hạn, tập hợp \\(X\\) ở trên có \\(|X| = 3\\) phần tử.

Một tập hợp \\(Y\\) mà tất cả các phần tử nằm trong \\(Y\\) đều nằm trong \\(X\\) thì ta nói tập hợp \\(Y\\) là con của tập hợp \\(X\\). Kí hiệu \\(Y \subset X\\). 

Một tập hợp \\(X\\) sẽ có \\(2^{|X|}\\) tập con khác nhau. Đối với tập hợp \\(X\\) ở trên sẽ có các tập hợp con:

\\[\emptyset, \\{2\\}, \\{3\\}, \\{5\\}, \\{2, 3\\}, \\{2, 5\\}, \\{3, 5\\}, \\{2, 3, 5\\}\\]

Ta có các phép toán trên tập hợp:

Giao của hai tập hợp \\(X\\) và \\(Y\\) là một tập hợp có các phần tử nằm trong cả tập \\(X\\) và tập \\(Y\\), kí hiệu \\(X \cap Y\\). Nếu \\(X = \\{1, 2, 4\\}\\) và \\(Y = \\{1, 4, 5\\}\\) thì \\(X \cap Y = \\{1, 4\\}\\).

Hợp của hai tập hợp \\(X\\) và \\(Y\\) là một tập hợp có các phần tử nằm trong một trong hai tập \\(X\\) và \\(Y\\) hoặc cả hai, kí hiệu \\(X \cup Y\\). Nếu \\(X = \\{1, 2, 4\\}\\) và \\(Y = \\{1, 4, 5\\}\\) thì \\(X \cup Y = \\{1, 2, 4, 5\\}\\).

Hiệu của hai tập hợp \\(X\\) và \\(Y\\) là một tập hợp có các phần tử nằm trong tập \\(X\\) nhưng không nằm trong tập \\(Y\\), kí hiệu \\(X \setminus Y\\). Nếu \\(X = \\{1, 2, 4\\}\\) và \\(Y = \\{1, 4, 5\\}\\) thì \\(X \setminus Y = \\{1\\}\\).

Nếu \\(Y \subset X\\) thì \\(X \setminus Y\\) được gọi là phần bù của \\(Y\\) trong \\(X\\), kí hiệu \\(C_X Y\\).

Trong toán học ta cũng có kí hiệu cho các tập hợp số.

- Tập hợp các số tự nhiên: \\(\mathbb{N} = \\{0, 1, 2, \dots \\}\\)
- Tập hợp các số nguyên: \\(\mathbb{Z} = \\{\dots, -2, -1, 0, 1, 2, \dots \\}\\)
- Tập hợp các số hữu tỉ: \\(\mathbb{Q} = \\{0, 7, \frac{1}{2} \dots \\}\\)
- Tập hợp các số vô tỉ: \\(\mathbb{R} = \\{\pi, e, \sqrt{2} \dots \\}\\)

Mối quan hệ giữa các tập hợp số: \\(\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R}\\)


## Lôgarít

Định nghĩa của logarit được phát biểu như sau:

> Cho \\(a\\) là một số thực khác \\(0\\) và một số thực \\(x\\). Số thực \\(k\\) để \\(a^k = x\\) được gọi là **logarit cơ số \\(a\\) của \\(x\\)**. Kí hiệu: \\(k = \log_a(x)\\).

Ta có thể hình dung \\(k = \log_a(x)\\) là số lần phải chia \\(x\\) cho \\(a\\) cho tới khi \\(x = 1\\).

Ví dụ, ta có: \\(6 = \log_2(64)\\):

\\[64 \rightarrow 32 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1 \\]

Số \\(64\\) cần \\(6\\) lần chia cho \\(2\\) để bằng \\(1\\), bằng giá trị của \\(\log_2(64)\\).

Một số công thức của logarit:
- Tích: \\(\log_a(xy) = \log_a(x) + \log_a(y)\\)
- Thương: \\(\log_a(\frac{x}{y}) = \log_a(x) - \log_a(y)\\)
- Lũy thừa: \\(\log_a(x^n) = n \times \log_a(x)\\)


Logarit cơ số \\(b\\) của một số \\(x\\) có thể được xác định bằng công thức: \\(\log_b(x) = \frac{\log_a(x)}{\log_a(b)}\\).

Logarit tự nhiên \\(\ln(x)\\) là logarit cơ số \\(e \approx 2.71828\\). 

Trong tin học, khi có hàm \\(\log\\) không có chú thích gì thêm, hãy mặc định nó là logarit cơ số \\(2\\).