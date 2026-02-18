# Ma trận

**Ma trận** là một mảng hai chiều chứa các số. Ở ví dụ này, ta có ma trận \\(A_{2 \times 3}\\) (ma trận \\(2\\) hàng, \\(3\\) cột) \\[A = \begin{bmatrix}1 & 2 & 3\\\\4 & 5 & 6\end{bmatrix}\\] 

Kí hiệu thường gặp nhất của ma trận là kí hiệu ma trận được viết hoa, còn các phần tử thì viết thường. Chỉ số của các phần tử trên ma trận được đánh số theo chiều từ trái sang phải đối với các cột, từ trên xuống dưới đối với các hàng. 

<center>
<img src="../images/MatrixLabelled.svg" alt="Ma trận" height="300px"/>

<sup> Một ma trận kích thước \\(m\times n\\) - [Mavaddat](https://commons.wikimedia.org/wiki/File:MatrixLabelled.svg) - [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.en)</sup>
</center>

## Các ma trận đặc biệt

### Ma trận chuyển vị 

Một ma trận \\(B_{m\times n}\\) được gọi là **ma trận chuyển vị** của ma trận \\(A_{n\times m}\\) nếu \\(b_{i, j} = a_{j, i} \forall 1 \le i \le m, 1\le j \le m\\). Ta kí hiệu ma trận chuyển vị của \\(A\\) là \\(A^{T}\\). Ta có: \\[A^T = \begin{bmatrix}1 & 4\\\\ 2 & 5 \\\\ 3 & 6\end{bmatrix}\\] 

### Ma trận hàng, ma trận cột, ma trận vuông

**Ma trận hàng** là các ma trận có kích thước \\(1 \times n\\): \\[\begin{bmatrix}1 & 2 & 3\end{bmatrix}\\] 

Tương tự như vậy, **ma trận cột** là các ma trận có kích thước \\(n \times 1\\): \\[\begin{bmatrix}1 \\\\ 2 \\\\ 3\end{bmatrix}\\] 

> [!NOTE]
> Nhận xét:
> 
> \\[\begin{bmatrix}a_1 & a_2 & a_3\end{bmatrix}^T = \begin{bmatrix}a_1 \\\\ a_2 \\\\ a_3\end{bmatrix}\\]
> 
> \\[\begin{bmatrix}a_1 \\\\ a_2 \\\\ a_3\end{bmatrix}^T = \begin{bmatrix}a_1 & a_2 & a_3\end{bmatrix}\\]

**Ma trận vuông** là các ma trận có kích thước \\(n\times n\\): \\[\begin{bmatrix}1 & 2 & 3\\\\4 & 5 & 6\\\\7 & 8 & 9\end{bmatrix}\\]

### Ma trận đơn vị 

Một **ma trận đơn vị bậc \\(n\\)** là một ma trận có kich thước \\(n \times n\\) và các phần tử thuộc đường chéo chính (**đường chéo chính** là tập hợp \\(\\{a_{i, j} \\ | \\ i = j, 1 \le i \le m, 1\le j \le m \\}\\)) bằng \\(1\\). 

\\[\begin{bmatrix}1 & 0 & 0\\\\0 & 1 & 0\\\\0 & 0 & 1\end{bmatrix}\\]

Ta kí hiệu một ma trận đơn vị bậc \\(n\\) là \\(I_n\\).

## Các thao tác trên ma trận

### Cộng ma trận

Khi ta cộng ma trận \\(A_{m\times n}\\) với ma trận \\(B_{m\times n}\\), ta được một ma trận \\(C_{m\times n}\\) với \\(c_{i, j} = a_{i, j} + b_{i, j} \forall 1 \le i \le m, 1\le j \le m\\).

\\[\begin{bmatrix}1 & 2 & 3\\\\4 & 5 & 6\end{bmatrix} + \begin{bmatrix}7 & 8 & 9\\\\10 & 11 & 12\end{bmatrix} = \begin{bmatrix}1 + 7 & 2 + 8 & 3 + 9\\\\4 + 10 & 5 + 11 & 6 + 12\end{bmatrix} = \begin{bmatrix}6 & 10 & 12\\\\14 & 16 & 18\end{bmatrix}\\]

### Trừ ma trận

Khi ta trừ ma trận \\(A_{m\times n}\\) cho ma trận \\(B_{m\times n}\\), ta được một ma trận \\(C_{m\times n}\\) với \\(c_{i, j} = a_{i, j} - b_{i, j} \forall 1 \le i \le m, 1\le j \le m\\).

\\[\begin{bmatrix}1 & 2 & 3\\\\4 & 5 & 6\end{bmatrix} - \begin{bmatrix}7 & 8 & 9\\\\10 & 11 & 12\end{bmatrix} = \begin{bmatrix}1 - 7 & 2 - 8 & 3 - 9\\\\4 - 10 & 5 - 11 & 6 - 12\end{bmatrix} = \begin{bmatrix}-6 & -6 & -6\\\\-6 & -6 & -6\end{bmatrix}\\]

### Phép nhân vô hướng (scalar multiplication)

Khi ta cộng ma trận \\(A_{m\times n}\\) với một số \\(c\\), ta được một ma trận \\(B_{m\times n}\\) với \\(b_{i, j} = c\times a_{i, j} \forall 1 \le i \le m, 1\le j \le m\\).

\\[\begin{bmatrix}1 & 2 & 3\\\\4 & 5 & 6\end{bmatrix} \times 2 = \begin{bmatrix}1 \times 2 & 2 \times 2 & 3 \times 2\\\\4 \times 2 & 5 \times 2 & 6 \times 2\end{bmatrix} = \begin{bmatrix}2 & 4 & 6\\\\8 & 10 & 12\end{bmatrix}\\]


### Nhân ma trận

Nhân ma trận mà một phép tính khá khó hiểu nếu chỉ đọc lướt qua. Ta có hai ma trận \\(A_{m\times n}\\) và \\(B_{n\times p}\\). Khi ta nhân ma trận \\(A\\) với ma trận \\(B\\), ta được một ma trận \\(C_{m\times p}\\) với \\[c_{i,j} = a_{i,1}b_{1,j} +  a_{i,2}b_{2,j}  + \cdots + a_{i,n}b_{n,j} = \sum_{k=1}^n a_{i,k}b_{k,j}\\]

<center>
<img src="../images/MatrixMultiplication.png" alt="Nhân ma trận"/>

<sup> Nhân hai ma trận - [Svjo](https://commons.wikimedia.org/wiki/File:MatrixMultiplication.png) - [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.en)</sup>
</center>

## Ứng dụng