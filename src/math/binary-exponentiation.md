# Luỹ thừa nhị phân

**Luỹ thừa nhị phân (binary exponentation)** là một phương pháp tối ưu để tính nhanh giá trị của \\(a^n\\) với \\(n\\) là một số nguyên. Ngoài ra, luỹ thừa nhị phân cũng có thể được sử dụng để tính các biểu thức có tính chất giao hoán: \\[(a \cdot b) \cdot c = a \cdot (b \cdot c)\\]

## Luỹ thừa nhị phân

Một tính chất của luỹ thừa được áp dụng trong luỹ thừa nhị phân chính là công thức: \\(a^m \times a^n = a^{m + n}\\). Sử dụng công thức này, ta có thể tính được \\(a^n\\) bằng cách tách \\(n\\) ra thành các luỹ thừa nhị phân để dễ dàng tính toán. Ví dụ với \\(a^{12}\\), ta có thể tính như sau: \\[a^{12} = a^{1100_2} = a^8 \times a^4\\]

Các luỹ thừa nhị phân của \\(a\\) có thể dễ dàng được tính: 

\\[
\begin{align*}
a^1 &= a \\\\ 
a^2 &= \left(a^1\right)^2 \\\\ 
a^4 &= \left(a^2\right)^2 \\\\ 
& \dots 
\end{align*}
\\]


```C++
int Pow(int a, int n, int MOD = 1e9 + 7){ // tính a^n mod MOD
	int res = 1;
	while(n){
		if(n & 1) res = (1ll * res * a) % MOD;
		a = (1ll * a * a) % MOD;
		n >>= 1;
	}
	return res;
}
``` 

Độ phức tạp của thuật toán là \\(O(\log{n})\\).

Ngoài ra, ta có thể thực hiện quay lui để giải quyết bài toán. Ta có:
\\[
a^n = \begin{cases}
1 \text{ khi } n = 0 \\\\
\left(a^{n/2}\right)^2 \text{ khi } n \gt 0, n \text{ chẵn } \\\\
\left(a^{\left\lfloor n/2 \right\rfloor}\right)^2 \times a \text{ khi } n \gt 0, n \text{ lẻ }
\end{cases}
\\]

```C++
int Pow(int a, int n, int MOD = 1e9 + 7){ // tính a^n mod MOD
	if (n == 0) return 1;
	if (n == 1) return a % MOD; // a^1 = a
	int t = Pow(a, n >> 1);
	t = (1ll * t * t) % MOD;
	t = (1ll * t * Pow(a, n & 1)) % MOD;
	return t;
}
```

Độ phức tạp của thuật toán cũng là \\(O(\log{n})\\).

## Phép nhân Ấn Độ

Ở bài viết về [modulo](modulo.md), ta đã được biết cách tính \\((a \times b) \mod {M} = ((a \mod {M}) \times (b \mod {M})) \mod {M}\\). Tuy nhiên, nếu ta viết chương trình theo kiểu này để tính với các giá trị \\(a, b, M \ge 10^{10}\\) thì kể cả khi sử dụng `long long` thì ta vẫn có thể bị tràn số. 

Để giải quyết vấn đề này, ta sử dụng phép nhân Ấn Độ. Phép nhân Ấn Độ cũng giống với luỹ thừa nhị phân, chỉ khác nhau ở việc thay vì sử dụng phép nhân thì ta sử dụng phép cộng. Ví dụ, để tính \\(a \times b\\), ta tính: 

\\[
a \times b = \begin{cases}
\left(a \times \frac{b}{2}\right) \times 2 \text { khi } b \text { chẵn } \\\\
\left(a \times \left\lfloor \frac{b}{2} \right\rfloor \right) \times 2 + a \text { khi } b \text{ lẻ } \\\\
\end{cases}
\\]



```C++
ll Mul(ll a, ll b, ll MOD = 1e9 + 7){ // tính a * b mod MOD
	if (b == 0) return 0;
	if (b == 1) return a % MOD; // a * 1 = a
	ll t = Mul(a, b >> 1);
	t = (t + t + Mul(a, b & 1)) % MOD;
	return t;
}
```

Độ phức tạp của phép nhân Ấn Độ là \\(O(\log{n})\\).