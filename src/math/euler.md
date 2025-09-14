# Phi hàm Euler

**Hàm số Euler** hay **phi hàm Euler** của một số nguyên dương \\(n\\) là số lượng số bé hơn hoặc bằng \\(n\\) và nguyên tố cùng nhau với \\(n\\). Kí hiệu của hàm số Euler là \\(\phi(n)\\) (hoặc \\(\varphi(n)\\)).

## Cách tính

Từ định nghĩa, ta có thể tính được \\(\phi(p) = p - 1\\) và \\(\phi(p^k) = p^k - p^{k-1}\\) với \\(p\\) là một số nguyên tố.
- Đối với \\(\phi(p) = p - 1\\), ta dễ dàng thấy được rằng với các số \\(x\\) từ \\(1\\) đến \\(p-1\\): \\(UCLN(x, p) = 1\\).
- Đối với \\(\phi(p^k) = p^k - p^{k-1}\\), ta thấy các số \\(x\\) mà \\(UCLN(x, p) > 1\\) chỉ có thể là các số là bội số của \\(p\\), tức là các số thuộc tập hợp \\(\\{p, 2p, 3p, \cdots, p^{k-1}p\\}\\). Vì trong \\(p^k\\) số từ \\(1\\) đến \\(p\\) có \\(p^k\\) bội số của \\(p\\) nên ta có \\(p^k - p^{k-1}\\) số nguyên tố cùng nhau với \\(p^k\\).

Nếu như ta đã biết giá trị phi hàm Euler của hai số \\(a\\) và \\(b\\), ta có thể tính được giá trị \\(\phi(ab)\\).
- Nếu \\(a, b\\) nguyên tố cùng nhau: \\[\phi(ab) = \phi(a) \times \phi(b)\\].
- Nếu \\(a, b\\) không nguyên tố cùng nhau, với \\(d = UCLN(a, b)\\): \\[\phi(ab) = \phi(a) \times \phi(b) \times \frac{d}{\phi(d)}\\].

Tổng quát hơn, với các số \\(n = p_1^{q_1}p_2^{q_2}\cdots p_k^{q_k}\\) với \\(p\\) là các số nguyên tố, \\(q\\) là luỹ thừa tương ứng, giá trị của \\(\phi(n)\\) bằng:

\\[\phi(n) = \prod_{i = 1}^{k} p_i^{k_i-1} (p_i - 1)\\]

Ví dụ, \\(\phi(24) = \phi(2^3 \times 3^1) = 2^2 \times (2 - 1) \times 3^0 \times (3 - 1) = 8\\).

Để đưa công thức trên vào chương trình, ta đơn giản hoá công thức để tăng tốc thuật toán. Ta có:

\\[
\begin{align}
\phi(n) &= \prod_{i = 1}^{k} p_i^{k_i-1} (p_i - 1) \\\\
		&= \prod_{i = 1}^{k} p_i^{k_i} (1 - \frac{1}{p_i}) \\\\
		&= n \times \prod_{i = 1}^{k} (1 - \frac{1}{p_i})
\end{align}
\\]

Từ đây, ta có công thức tính \\(\phi(n)\\) bằng:

\\[\phi(n) = \prod_{i = 1}^{k} p_i^{k_i-1} (p_i - 1)\\]

Với \\(p\\) là các ước nguyên tố của \\(n\\).

```C++
int phi(int n){
	int totient = n;
	for(int i = 2; 1ll * i * i <= n; ++i){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			totient -= totient / p;
		}
	}
	if(n != 1) totient -= totient / n;

	return n;
}
```

Độ phức tạp của thuật toán bằng \\(O(\sqrt{n})\\).

### Sàng phi hàm Euler

Ta có thể chỉnh sửa thuật toán [sàng số nguyên tố](prime.md#sàng-số-nguyên-tố) để tính giá trị phi hàm Euler của các số từ \\(1\\) đến \\(n\\).

```C++
int phi[N];

void sievePhi(int n){
	for(int i = 1; i <= n; ++i) phi[i] = i;
    for(int i = 2; i <= n; ++i){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
               phi[j] -= phi[j] / i;
            }
        }
    }
}
```

## Ứng dụng

### Định lí Euler

Phi hàm Euler xuất hiện trong [định lí Euler](https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_Euler): với hai số \\(a\\) và \\(p\\) nguyên tố cùng nhau, ta có: \\[a^{\phi(p)} \equiv 1 \pmod p\\]

Từ đây, ta dễ dàng tính được giá trị [nghịch đảo modulo](modulo.md#nghịch-đảo-modulo) của \\(a\\) bằng \\(a^{\phi(p)-1}\\).