# Kiến thức nền tảng

Ta sẽ nói về một số kiến thức nền tảng về toán học trong lập trình thi đấu.

## Các kiến thức cần biết

Toán học là một lĩnh vực rộng lớn và phức tạp, trải dài từ những con số cơ bản đến những cấu trúc trừu tượng nhất của vũ trụ. Trong chương này, ta chỉ tập trung vào những kiến thức toán học được sử dụng phổ biến trong lập trình thi đấu. Toàn bộ nội dung trong *[Chương trình Giáo dục Phổ thông môn Toán năm 2018](<3. CT_Toan.pdf>)* là kiến thức *bắt buộc* cần phải biết khi đọc chương này. Một số khái niệm sẽ được giải thích lại.

## Công thức tính tổng

Một số công thức tính tổng của các dãy số vô cùng hữu ích mà ta nên biết:

Tổng các số từ \\(1\\) đến \\(n\\): \\[1 + 2 + \dots + n = \frac{n(n + 1)}{2}\\]

Tổng bình phương các số từ \\(1\\) đến \\(n\\): \\[1^2 + 2^2 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}\\]

Tổng \\(n\\) số đầu tiên của một dãy cấp số cộng (dãy cấp số cộng \\((u_n)\\) có công sai \\(d\\) là một dãy số có dạng: \\((u_1, u_1 + d, u_1 + 2d, u_1 + 3d, \dots, u_1 + (n - 1)d, \dots)\\)): \\[u_1 + u_2 + \dots + u_n = \frac{n(u_1 + u_n)}{2} = \frac{n[2u_1 + (n - 1)d]}{2}\\]

Tổng \\(n\\) số đầu tiên của một dãy cấp số nhân (dãy cấp số nhân \\((u_n)\\) có công bội \\(q\\) là một dãy số có dạng: \\((u_1, u_1 \times q, u_1 \times q^2, u_1 \times q^3, \dots, u_1 \times q^{n - 1}, \dots)\\)): \\[u_1 + u_2 + \dots + u_n = \frac{u_1(q^n - 1)}{q - 1}\\]

Từ công thức tính tổng của dãy cấp số nhân trên, ta có thể tính nhanh tổng của \\(n\\) luỹ thừa đầu tiên của \\(2\\): \\[2^0 + 2^1 + \dots + 2^{n - 1} = 2^n - 1\\]

## Lí thuyết tập hợp

Một kĩ thuật hữu ích quan trọng trong việc đếm các phần tử của hợp của hai hoặc nhiều tập hợp chính là kĩ thuật [bao hàm - loại trừ](https://vi.wikipedia.org/wiki/Nguy%C3%AAn_l%C3%BD_bao_h%C3%A0m-lo%E1%BA%A1i_tr%E1%BB%AB). Ví dụ, với hai tập hợp \\(A, B\\), ta có: \\[|A \cup B| = |A| + |B| - |A \cap B|\\]

Ta có công thức tính hợp cho \\(3\\) tập hợp \\(A, B, C\\): \\[|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|\\]

Ta có công thức tổng quát để tính hợp của \\(n\\) tập hợp \\(A_1, A_2, \dots, A_n\\): \\[\bigcup_{i = 1}^n A_i = \sum_{J \subseteq \\{1, 2, \dots, n\\}} (-1)^{|J| + 1}|\bigcap_{j \in J} A_j|\\]

## Logarit

Sẽ có lúc ta muốn kiểm tra nếu tích hai số có lớn hơn giới hạn của `int` hoặc `long long`. Thay vì nhân hai số và kiểm tra (có thể bị tràn số), ta có thể sử dụng công thức \\(\log{a} + \log{b} = \log{ab}\\) để kiểm tra. Ví dụ, thay vì viết:

```C++
const ll LIMIT = 1e18;
if (a * b <= LIMIT){
	// code
}
``` 

Ta có thể viết:

```C++
if (log(a) + log(b) <= log(LIMIT)){
	// code
}
```