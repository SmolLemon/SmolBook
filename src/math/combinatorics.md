# Đại số tổ hợp

Bạn X đang phân vân giữa việc mua \\(2\\) loại khoá khác nhau: khoá A là khoá số bấm với \\(10\\) số, khoá B là khoá số xoay \\(4\\) vòng, mỗi vòng \\(10\\) chữ số. Bạn X muốn biết rằng khoá nào sẽ bảo mật hơn, nói cách khác: khoá nào có số lượng mật khẩu có thể nhiều hơn?

|Khoá số bấm A|Khoá số xoay B|
|---|---|
|![khoá số A](../images/num_lock_1.png)|![khoá số B](../images/num_lock_2.png)|

Việc liệt kê tất cả các mật khẩu có thể là một quá trình rất phức tạp vì số lượng của chúng là rất lớn. Trong toán học, việc liệt kê tất cả các kết quả thoả mãn cũng thế. Thay vì thế, sử dụng các công thức toán học, ta có thể đếm được chính xác số lượng các kết quả một cách nhanh chóng.

## Quy tắc đếm

Ta sẽ nói về hai quy tắc đếm: quy tắc cộng và quy tắc nhân.

### Quy tắc cộng

Nếu như một công việc có hai phuơng án:
- Phương án một có \\(n_1\\) cách,
- Phương án hai có \\(n_2\\) cách

Thì số cách thực hiện công việc sẽ bằng: \\(n_1 + n_2\\) cách.

Cụ thể hơn, nếu có \\(k\\) phương án thực hiện công việc, mỗi phương án có \\(n_i\\) cách, thì số công việc sẽ bằng: \\[n = n_1 + n_2 + \cdots + n_k\\]

Ví dụ, một cửa hàng có \\(5\\) món xôi và \\(4\\) món phở, số cách chọn món ăn sẽ bằng \\(5 + 4 = 9\\) món.

### Quy tắc nhân

Nếu như một công việc có hai công đoạn:
- Công đoạn một có \\(m_1\\) cách thực hiện,
- Với mỗi cách ở công đoạn một có \\(m_2\\) cách thực hiện công đoạn hai 

Thì số cách thực hiện công việc sẽ bằng: \\(m_1m_2\\) cách.

Cụ thể hơn, nếu có \\(k\\) công đoạn thực hiện công việc, mỗi công đoạn có \\(m_i\\) cách, thì số công việc sẽ bằng: \\[m = m_1m_2\cdots m_k\\]

## Hoán vị, chỉnh hợp, tổ hợp

### Hoán vị

Một **hoán vị** của một tập hợp chứa \\(n\\) là một cách sắp xếp có thứ tự \\(n\\) phần tử đó.

Ví dụ, ta có hoán vị của một tập hợp của các phần tử có giá trị từ \\(1\\) đến \\(5\\): \\[\\{5, 2, 1, 4, 3\\}\\]

Số hoán vị của tập hợp chứa \\(n\\) phần tử bằng: \\[P_n = P(n) = n! = n \times (n - 1) \times (n - 2) \cdots 2 \times 1\\]

Quy ước: \\(0! = 1\\).

Một trường hợp tổng quát hơn của hoán vị có thể được phát biểu như sau: cho một tập hợp \\(n\\) phần tử chứa \\(k\\) phần tử phân biệt, mỗi phần tử phân biệt có \\(n_i\\) phần tử \\(\left(\sum_{i = 1}^{n} n_i = n\right)\\), số lượng hoán vị phân biệt của tập hợp sẽ bằng: \\[\frac{n!}{n_1!n_2!\cdots n_k!}\\] 

Ví dụ, ta có xâu `BOOK` là một xâu có \\(n\\) kí tự, có tổng cộng \\(1\\) kí tự `B`, \\(2\\) kí tự `O` và \\(1\\) kí tự `K`. Tổng số hoán vị phân biệt của xâu sẽ bằng \\(\frac{4!}{1!2!1!} = 12\\).

### Chỉnh hợp

Có \\(2\\) dạng chỉnh hợp: chỉnh lợp có lặp và chỉnh hợp không lặp. Một **chỉnh hợp không lặp chập \\(k\\) của \\(n\\)** là một cách sắp xếp có thứ tự \\(k\\) phần tử từ tập hợp \\(n\\) phần tử, các phần tử không được chọn nhiều hơn \\(1\\) lần \\(\left( 1 \le k \le n \right)\\).

Số chỉnh hợp không lặp chập \\(k\\) của \\(n\\) bằng: \\[P^k_n = P(n, k) = \frac{n!}{(n - k)!} = n \times (n - 1) \cdots (n - k + 1)\\]

**Chỉnh hợp có lặp**, khác với chỉnh hợp không lặp, cho phép các phần tử được chọn nhiều hơn \\(1\\) lần.

Số chỉnh hợp có lặp chập \\(k\\) của \\(n\\) bằng: \\[n^k = \underbrace{n \times n \cdots n}_{\text{k lần}}\\]

Số chỉnh hợp có lặp sẽ là thứ giúp ta tính được số lượng mật khẩu của hai loại khoá:

> Khoá số A có \\(10\\) ô bấm, mỗi ô bấm có hai trạng thái: bật và tắt. Vậy, tập hợp các trạng thái của mỗi ô bấm là \\(n = 2\\), và số lượng ô bấm là \\(k = 10\\). Từ đây, số lượng mật khẩu sẽ bằng số chỉnh hợp có lặp chập \\(k\\) của \\(n\\), tức là bằng: \\[2^{10} = 1\ 024\\]
> 
> Khoá số B có \\(4\\) vòng số xoay, mỗi vòng số có \\(10\\) chữ số từ \\(0\\) đến \\(9\\). Vậy, tập hợp các trạng thái của mỗi vòng số là \\(n = 10\\), và số lượng vòng số xoay là \\(k = 4\\). Từ đây, số lượng mật khẩu sẽ bằng số chỉnh hợp có lặp chập \\(k\\) của \\(n\\), tức là bằng: \\[{10}^{4} = 10\ 000\\]
> 
> Vì \\(1\ 024 \le 10\ 000\\) nên ta kết luận rằng khoá số xoay B bảo mật hơn khoá số bấm A. 

### Tổ hợp

Một **Tổ hợp chập \\(k\\) của \\(n\\)** là một cách chọn \\(k\\) phần tử của tâp hợp \\(n\\) phần tử \\(\left( 0 \le k \le n \right)\\).

Số tổ hợp chập \\(k\\) của \\(n\\) bằng: \\[C^k_n = \binom{n}{k} = \frac{n!}{k!(n-k)!}\\]

Chỉnh hợp không lặp giống với tổ hợp ở chỗ là cả hai đều đếm cách chọn các phần tử trong tập hợp. Điểm khác nhau nằm ở chỗ chỉnh lợp không lặp đếm cả cách xếp còn tổ hợp thì không. Từ đây, ta có: \\[C^k_n = \frac{P^k_n}{k!}\\]

Một trường hợp tổng quát hơn của tổ hợp chính là đếm cách chọn các phần tử cho \\(k\\) nhóm, mỗi nhóm \\(n_i\\) phần tử \\(\left( \sum_{i = 1}^{k} n_i = n \right)\\). Số cách chọn sẽ bằng: \\[\binom{n}{n_1, n_2, \cdots, n_k} = \binom{n}{n_1}\binom{n-n_1}{n_2}\cdots \binom{n_k}{n_k} = \frac{n!}{n_1!n_2!\cdots n_k!}\\]

