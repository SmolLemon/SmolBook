# Đại số tổ hợp

Bạn X đang phân vân giữa việc mua \\(2\\) loại khoá khác nhau: khoá A là khoá số bấm với \\(10\\) số, khoá B là khoá số xoay \\(4\\) vòng, mỗi vòng \\(10\\) chữ số. Bạn X muốn biết rằng khoá nào sẽ bảo mật hơn, nói cách khác: khoá nào có số lượng mật khẩu có thể nhiều hơn?

|Khoá số bấm A|Khoá số xoay B|
|---|---|
|![khoá số A](../images/num_lock_1.png)|![khoá số B](../images/num_lock_2.png)|

Việc liệt kê tất cả các mật khẩu có thể là một quá trình rất phức tạp vì số lượng của chúng là rất lớn. Trong toán học, việc liệt kê tất cả các kết quả thoả mãn cũng thế. Thay vì thế, sử dụng các công thức toán học, ta có thể đếm được chính xác số lượng các kết quả một cách nhanh chóng.

## Quy tắc đếm

Ta sẽ nói về hai quy tắc đếm: quy tắc cộng và quy tắc nhân.

### Quy tắc cộng

Nếu như một công việc có hai phuơng án khác nhau:
- Phương án một có \\(n_1\\) cách,
- Phương án hai có \\(n_2\\) cách

Thì số cách thực hiện công việc sẽ bằng: \\(n_1 + n_2\\) cách.

Cụ thể hơn, nếu có \\(k\\) phương án khác nhau nhằm thực hiện công việc, mỗi phương án có \\(n_i\\) cách, thì số công việc sẽ bằng: \\[n = n_1 + n_2 + \cdots + n_k\\]

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

Số hoán vị của tập hợp chứa \\(n\\) phần tử bằng: \\[P_n = P(n) = n! = n \times (n - 1) \times (n - 2) \times \cdots \times 2 \times 1\\]

Quy ước: \\(0! = 1\\).

Một trường hợp tổng quát hơn của hoán vị có thể được phát biểu như sau: cho một tập hợp \\(n\\) phần tử chứa \\(k\\) phần tử phân biệt, mỗi phần tử phân biệt có \\(n_i\\) phần tử \\(\left(\sum_{i = 1}^{n} n_i = n\right)\\), số lượng hoán vị phân biệt của tập hợp sẽ bằng: \\[\frac{n!}{n_1!n_2!\cdots n_k!}\\] 

Ví dụ, ta có xâu `BOOK` là một xâu có \\(n\\) kí tự, có tổng cộng \\(1\\) kí tự `B`, \\(2\\) kí tự `O` và \\(1\\) kí tự `K`. Tổng số hoán vị phân biệt của xâu sẽ bằng \\(\frac{4!}{1!2!1!} = 12\\).

### Chỉnh hợp

Có \\(2\\) dạng chỉnh hợp: chỉnh lợp có lặp và chỉnh hợp không lặp. Một **chỉnh hợp không lặp chập \\(k\\) của \\(n\\)** là một cách sắp xếp có thứ tự \\(k\\) phần tử từ tập hợp \\(n\\) phần tử, các phần tử không được chọn nhiều hơn \\(1\\) lần \\(\left( 1 \le k \le n \right)\\).

Số chỉnh hợp không lặp chập \\(k\\) của \\(n\\) bằng: \\[P^k_n = P(n, k) = \frac{n!}{(n - k)!} = n \times (n - 1) \times \cdots \times (n - k + 1)\\]

**Chỉnh hợp có lặp**, khác với chỉnh hợp không lặp, cho phép các phần tử được chọn nhiều hơn \\(1\\) lần.

Số chỉnh hợp có lặp chập \\(k\\) của \\(n\\) bằng: \\[n^k = \underbrace{n \times n \cdots n}_{\text{k lần}}\\]

Số chỉnh hợp có lặp sẽ là thứ giúp ta tính được số lượng mật khẩu của hai loại khoá:

> [!NOTE]
> Khoá số A có \\(10\\) ô bấm, mỗi ô bấm có hai trạng thái: bật và tắt. Vậy, tập hợp các trạng thái của mỗi ô bấm là \\(n = 2\\), và số lượng ô bấm là \\(k = 10\\). Từ đây, số lượng mật khẩu sẽ bằng số chỉnh hợp có lặp chập \\(k\\) của \\(n\\), tức là bằng: \\[2^{10} = 1\ 024\\]
> 
> Khoá số B có \\(4\\) vòng số xoay, mỗi vòng số có \\(10\\) chữ số từ \\(0\\) đến \\(9\\). Vậy, tập hợp các trạng thái của mỗi vòng số là \\(n = 10\\), và số lượng vòng số xoay là \\(k = 4\\). Từ đây, số lượng mật khẩu sẽ bằng số chỉnh hợp có lặp chập \\(k\\) của \\(n\\), tức là bằng: \\[{10}^{4} = 10\ 000\\]
> 
> Vì \\(1\ 024 \le 10\ 000\\) nên ta kết luận rằng khoá số xoay B bảo mật hơn khoá số bấm A. 

### Tổ hợp

Một **tổ hợp chập \\(k\\) của \\(n\\)** là một cách chọn \\(k\\) phần tử của tâp hợp \\(n\\) phần tử \\(\left( 0 \le k \le n \right)\\).

Số tổ hợp chập \\(k\\) của \\(n\\) bằng: \\[C^k_n = \binom{n}{k} = \frac{n!}{k!(n-k)!} = \frac{n \times (n - 1) \times \cdots \times (n - k + 1)}{1\times 2 \cdots k}\\]

Ta quy ước \\(C^k_n = 0\\) nếu \\(k < 0\\) hoặc \\(k > n\\).

Chỉnh hợp không lặp giống với tổ hợp ở chỗ là cả hai đều đếm cách chọn các phần tử trong tập hợp. Điểm khác nhau nằm ở chỗ chỉnh lợp không lặp đếm cả cách xếp còn tổ hợp thì không. Từ đây, ta có: \\[C^k_n = \frac{P^k_n}{k!}\\]

Một trường hợp tổng quát hơn của tổ hợp chính là đếm cách chọn các phần tử cho \\(k\\) nhóm, mỗi nhóm \\(n_i\\) phần tử \\(\left( \sum_{i = 1}^{k} n_i = n \right)\\). Số cách chọn sẽ bằng: \\[\binom{n}{n_1, n_2, \cdots, n_k} = \binom{n}{n_1}\binom{n-n_1}{n_2}\cdots \binom{n_k}{n_k} = \frac{n!}{n_1!n_2!\cdots n_k!}\\]

## Cài đặt

Vì giá trị của hoán vị, chỉnh hợp, tổ hợp rất lớn nên ta tập trung vào tính giá trị modulo của các giá trị này.

### Hoán vị

Vì hoán vị chỉ đơn giản là tích các số từ \\(1\\) đến \\(n\\) nên việc cài đặt vô cùng đơn giản.

```C++
const int MOD;
int mul(int a, int b) {
	return (1ll * a * b) % MOD;
}
int fac(int n) {
	int res = 1;
	for(int i = 2; i <= n; ++i) res = mul(res, i);
	return res;
}
```

Độ phức tạp của cách này là \\(O(n)\\).

Ta có thể tính trước các giai thừa nhằm tránh việc phải tính đi tính lại.

```C++
int fac[N];
void preprocess(){
	fac[0] = 1;
	for(int i = 1; i < N; ++i) {
		fac[i] = mul(fac[i-1], i);
	}
}
```

Độ phức tạp của cách tính này cũng là \\(O(n)\\).

### Chỉnh hợp

Đối với chỉnh hợp có lặp, ta có thể sử dụng [luỹ thừa nhị phân](binary-exponentiation.md) để tính giá trị của \\(n^k\\).

Đối với chỉnh hợp không lặp, hoặc là ta có thể duyệt các giá trị cần tính:

```C++
int npk(int n, int k) {
	int res = 1;
	for(int i = n - k + 1; i <= n; ++i) {
		res = mul(res, i);
	}
	return res;
}
```


Hoặc ta có thể tính trước các giai thừa và tính giá trị của \\(n! \times (k!)^{-1}\\) nếu \\(k!\\) và \\(MOD\\) nguyên tố cùng nhau.

```C++
int npk(int n, int k) {
	return mul(fac[n], modInv(fac[k], MOD)); // hàm modInv(a, m) ở phần modulo
}
```

Độ phức tạp của hai cách tính này lần lượt là \\(O(k)\\) và \\(O(\log{MOD})\\).

### Tổ hợp

Ta có thể tính tổ hợp theo nhiều cách khác nhau.

Cách thứ nhất là sử dụng công thức đệ quy: \\[C^k_n = C^{k-1} _ {n-1} + C^{k} _ {n-1} \\]

Với các trường hợp cơ sở: \\(C^{0} _ n = C^{n} _ {n} = 1\\)

```C++
int ncr[N][K];

void preprocess(){
	for(int i = 1; i < N; ++i) {
		ncr[i][0] = ncr[i][i] = 1;
	}
	for(int i = 1; i < N; ++i) {
		for(int j = 1; j < min(i, K); ++j) {
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
			if(ncr[i][j] >= MOD) ncr[i][j] -= MOD;
		}
	}
}
```

Độ phức tạp của cách tính thứ nhất là \\(O(nk)\\).

Cách thứ hai là duyệt các giá trị cần tính. Áp dụng công thức \\(C^k_n = \frac{P^k_n}{k!}\\), ta có thể tận dụng cách tính thứ nhất của hàm `npk` ở trên, rồi chia kết quả của hàm cho \\(k!\\).

```C++
int ncr(int n, int k){
	int res = 1, div = 1;
	for(int i = 1; i <= k; ++i) {
		res = mul(res, n - i + 1);
		div = mul(div, i);
	}
	return mul(res, modInv(div, MOD));
}
```
Độ phức tạp của cách tính thứ hai là \\(O(k + \log{MOD})\\).

Cách thứ ba là tính trước các giai thừa và tính giá trị của \\(n! \times (k!)^{-1} \times \left((n-k)!\right)^{-1}\\) nếu \\(k!\\) và \\((n-k)!\\) nguyên tố cùng nhau với \\(MOD\\).

```C++
int npk(int n, int k) {
	return mul(fac[n], mul(modInv(fac[n-k], MOD), modInv(fac[k], MOD))); 
}
```

Độ phức tạp của cách tính thứ ba là \\(O(\log{MOD})\\).

Ngoài các cách tính tổng quát trên, nếu \\(MOD\\) là một số nguyên tố có giá trị nhỏ, ta có thể sử dụng [định lí Lucas](https://en.wikipedia.org/wiki/Lucas%27s_theorem) để tính giá trị tổ hợp.

Cụ thể, với hai số \\(n\\), \\(k\\) và một số nguyên tố \\(p\\), ta có:

\\[C^k _ n \equiv C^{k_m} _ {n_m} \times C^{k_{m-1}} _ {n_{m-1}} \times \cdots \times C^{k_1} _ {n_1} \times C^{k_0} _ {n_0} \pmod p\\]

Với:

\\[k = k_m \times p^m + k_{m - 1} \times p^{m - 1}  + ... + k_{1} \times p^{1} + k_{0}\\]

Và:

\\[n = n_m \times p^m + n_{m - 1} \times p^{m - 1}  + ... + n_{1} \times p^{1} + n_{0}\\]

```C++
int lucas_ncr(int n, int k){
	if(k == 0) return 1;
	int ni = n % MOD;
	int ki = k % MOD;
	if(ni < ki) return 0;
	return mul(lucas_ncr(n / MOD, k / MOD), ncr(ni, ki));
}
```

Độ phức tạp của thuật toán khi áp dụng định lí Lucas là \\(O(\log_p{n} + NCR)\\) với \\(NCR\\) là độ phức tạp của việc tính \\(C^k_n\\) theo các cách được nói ở trên.