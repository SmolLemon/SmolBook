# Phi hàm Euler

*Được xuất hiện trên [VNOI Wiki](https://wiki.vnoi.info/algo/algebra/phi-ham-euler)*

<br>

**Hàm số Euler** hay **phi hàm Euler** của một số nguyên dương \\(n\\) là số lượng số bé hơn hoặc bằng \\(n\\) và nguyên tố cùng nhau với \\(n\\). Kí hiệu của hàm số Euler là \\(\phi(n)\\) (hoặc \\(\varphi(n)\\)).

## Cách tính

Từ định nghĩa, ta có thể tính được \\(\phi(p) = p - 1\\) và \\(\phi(p^k) = p^k - p^{k-1}\\) với \\(p\\) là một số nguyên tố.
- Đối với \\(\phi(p) = p - 1\\), ta dễ dàng thấy được rằng với các số \\(x\\) từ \\(1\\) đến \\(p-1\\): \\(\text{UCLN}(x, p) = 1\\).
- Đối với \\(\phi(p^k) = p^k - p^{k-1}\\), ta thấy các số \\(x\\) thoả mãn \\(\text{UCLN}(x, p^k) > 1\\) chỉ có thể là các bội số của \\(p\\), tức là các số thuộc tập hợp \\(\\{p, 2p, 3p, \cdots, p^{k-1}p\\}\\). Vì trong \\(p^k\\) số từ \\(1\\) đến \\(p\\) có \\(p^{k-1}\\) số là bội số của \\(p\\) nên ta có \\(p^k - p^{k-1}\\) số nguyên tố cùng nhau với \\(p^k\\).

Nếu đã biết trước giá trị phi hàm Euler của hai số \\(a\\) và \\(b\\), ta có thể tính được giá trị \\(\phi(ab)\\).
- Nếu \\(a, b\\) nguyên tố cùng nhau: \\[\phi(ab) = \phi(a) \times \phi(b)\\]
- Nếu \\(a, b\\) không nguyên tố cùng nhau, với \\(d = \text{UCLN}(a, b)\\): \\[\phi(ab) = \phi(a) \times \phi(b) \times \frac{d}{\phi(d)}\\]

Từ các công thức trên, ta có thể tính giá trị phi hàm Euler của các số \\(n = p_1^{q_1}p_2^{q_2}\cdots p_k^{q_k}\\) với \\(p\\) là các số nguyên tố, \\(q\\) là luỹ thừa tương ứng:

\\[
\begin{align}
\phi(n) &= \phi\left(\prod_{i = 1}^{k}p_i^{q_i}\right) \\\\
        &= \prod_{i = 1}^{k}\phi(p_i^{q_i}) \\\\
        &= \prod_{i = 1}^{k}(p_i^{q_i} - p_i^{q_i-1}) \\\\
		&= \prod_{i = 1}^{k} p_i^{q_i-1} (p_i - 1)
\end{align}
\\]

Ví dụ, \\(\phi(24) = \phi(2^3 \times 3^1) = 2^2 \times (2 - 1) \times 3^0 \times (3 - 1) = 8\\).

Để đưa công thức trên vào chương trình, ta đơn giản hoá công thức để tăng tốc thuật toán. Ta có:

\\[
\begin{align}
\phi(n) &= \prod_{i = 1}^{k} p_i^{k_i-1} (p_i - 1) \\\\
		&= \prod_{i = 1}^{k} p_i^{k_i} \left(1 - \frac{1}{p_i}\right) \\\\
		&= n \times \prod_{i = 1}^{k} \left(1 - \frac{1}{p_i}\right)
\end{align}
\\]

Từ đây, ta có công thức tính \\(\phi(n)\\) bằng:

\\[\phi(n) = n \times \prod_{p|n} \left(1 - \frac{1}{p}\right)\\]

Với \\(p\\) là các ước nguyên tố của \\(n\\).

```C++
int phi(int n){
	int totient = n;
	for(int i = 2; 1ll * i * i <= n; ++i){
		if(n % i == 0){ // i là số nguyên tố
			while(n % i == 0) n /= i;
			totient -= totient / i; // tương đương totient * (1 - 1/i)
		}
	}
	if(n != 1) totient -= totient / n;

	return totient;
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
        if(phi[i] == i){ // i là số nguyên tố
            for(int j = i; j <= n; j += i){
               phi[j] -= phi[j] / i; // tương đương phi[j] * (1 - 1/i)
            }
        }
    }
}
```

Vì phi hàm Euler là một [hàm nhân tính](https://vi.wikipedia.org/wiki/H%C3%A0m_nh%C3%A2n_t%C3%ADnh), ta có thể tính giá trị phi hàm Euler dựa trên công thức \\[\phi(n) = n - \sum_{d|n}\phi(d)\\]

Với \\(d\\) là các ước của \\(n\\) nhỏ hơn \\(n\\).

```C++
int phi[N];

void sievePhi(int n){
    for(int i = 1; i <= n; ++i) phi[i] = i;
    for(int i = 1; i <= n; ++i){
        for(int j = i + i; j <= n; j += i){
           phi[j] -= phi[i];
        }
    }
}
```
## Ứng dụng

### Định lí Euler

Phi hàm Euler xuất hiện trong [định lí Euler](https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_Euler): với hai số \\(a\\) và \\(p\\) nguyên tố cùng nhau, ta có: \\[a^{\phi(p)} \equiv 1 \pmod p\\]

Từ đây, ta dễ dàng tính được giá trị [nghịch đảo modulo](modulo.md#nghịch-đảo-modulo) của \\(a\\) bằng \\(a^{\phi(p)-1} \bmod p\\).

### Luỹ thừa

Với hai số \\(a\\) và \\(p\\) nguyên tố cùng nhau, nếu \\(c \equiv d \pmod{\phi(p)}\\), thì: \\[a^c \equiv a^d \pmod p\\]

Tính chất này rất hữu dụng khi ta muốn tính luỹ thừa bậc \\(b\\) của \\(a\\) với số mũ \\(b\\) rất lớn: \\[a^b \equiv a^{b \bmod \phi(p)} \pmod p\\]