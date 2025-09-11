# Phi hàm Euler

**Hàm số Euler** hay **phi hàm Euler** của một số nguyên dương \\(n\\) là số lượng số bé hơn hoặc bằng \\(n\\) và nguyên tố cùng nhau với \\(n\\). Kí hiệu của hàm số Euler là \\(\phi(n)\\).

## Cách tính

Theo định nghĩa, ta có thể tính được \\(\phi(p) = p - 1\\) và \\(\phi(p^k) = p^k - p^{k-1}\\) với \\(p\\) là một số nguyên tố.

Nếu như ta đã biết giá trị phi hàm Euler của hai số \\(a\\) và \\(b\\), ta có thể tính được giá trị \\(\phi(ab)\\).
- Nếu \\(a, b\\) nguyên tố cùng nhau: \\[\phi(ab) = \phi(a) \times \phi(b)\\].
- Nếu \\(a, b\\) không nguyên tố cùng nhau, với \\(d = UCLN(a, b)\\): \\[\phi(ab) = \phi(a) \times \phi(b) \times \frac{d}{\phi(d)}\\].

Với các số \\(n = p_1^{q_1}p_2^{q_2}\cdots p_k^{q_k}\\) với \\(p\\) là các số nguyên tố, \\(q\\) là luỹ thừa tương ứng, giá trị của \\(\phi(n)\\) bằng:

\\[\phi(n) = \prod_{i = 1}^{k} p_i^{k_i-1} (p_i - 1)\\]

Ví dụ, \\(\phi(24) = \phi(2^3 \times 3^1) = 2^2 \times (2 - 1) \times 3^0 \times (3 - 1) = 8\\).

Ngoài ra, ta còn có công thức:

\\[\phi(n) = n \times \prod_{p | n} (1 - \frac{1}{p})\\]

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