# Modulo

Đây là một chiếc đồng hồ điện tử.

<center>
<img src="../images/1280px-Telechron_clock_2H07-Br_Administrator.JPG" alt="Đồng hồ"/>

<sup> Đồng hồ điện tử - [Wissembourg](https://commons.wikimedia.org/wiki/File:Telechron_clock_2H07-Br_Administrator.JPG) - [CC BY-SA 3.0 Umported](https://creativecommons.org/licenses/by-sa/3.0/deed.en)</sup>
</center>

## Tính chất


## Nghịch đảo modulo

*Phần "Nghịch đảo modulo" được xuất hiện trên [VNOI Wiki](https://wiki.vnoi.info/vi/algo/math/modular-inverse)*

<br>

Giả sử ta có \\(a, m\\) là hai số nguyên tố cùng nhau. Khi này, tồn tại một số nguyên \\(x\\) thoả mãn: \\[ax \equiv 1 \pmod {m}\\]

Số nguyên \\(x\\) được gọi là **nghịch đảo modulo (modular multiplicative inverse)** của \\(a\\), kí hiệu là \\(a^{-1}\\) hay \\(\frac{1}{a}\\). 

Với nghịch đảo modulo, ta có thể tính được giá trị của biểu thức \\(\frac{a}{b} \bmod{m}\\).

Ta có một số phương pháp để tính nghịch đảo modulo:

### Sử dụng định lí Euler

Đây là một trong những phương pháp đơn giản nhất để tính nghịch đảo modulo. Theo [định lí Euler](https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_Euler), ta có: \\[a^{\phi(p)} \equiv 1 \pmod {p}\\]

Với \\(\phi(p)\\) là [phi hàm Euler](euler-totient-function.md) của \\(p\\). Từ đây, ta suy ra: \\[a \times a^{\phi(p) - 1} \equiv 1 \pmod {p}\\]

Vậy, nghịch đảo modulo sẽ bằng \\(a^{-1} = a^{\phi(p) - 1} \bmod{p}\\).

Nếu \\(p\\) là số nguyên tố, ta có thể áp dụng [định lí Fermat nhỏ](https://vi.wikipedia.org/wiki/%C4%90%E1%BB%8Bnh_l%C3%BD_nh%E1%BB%8F_Fermat), từ đó tính được \\(a^{-1}  \equiv a^{p - 2} \pmod{p}\\).

```C++
int modInv(int a, int m){ // giả sử a, m nguyên tố cùng nhau
	int p = phi(m); // hàm `phi(n)` ở phần "Phi hàm Euler"
	int x = Pow(a, p - 1, m); // hàm `Pow(a, b, c)` ở phần "Lũy thừa nhị phân"
	return x;
}
```

Việc tính phi hàm Euler với độ phức tạp \\(O(\sqrt{m})\\), cộng thêm với việc tính luỹ thừa với độ phức tạp \\(O(\log{p})\\), làm độ phức tạp của thuật toán bằng \\(O(\sqrt{m} + \log{p})\\). Nếu \\(m\\) là số nguyên tố thì việc tính phi hàm Euler sẽ nhanh hơn (phi hàm Euler của một số nguyên số \\(p\\) là \\(p - 1\\)), và độ phức tạp của thuật toán sẽ bằng \\(O(\log{m})\\).

### Sử dụng thuật toán Euclid mở rộng

Nhìn lại biểu thức tìm nghịch đảo modulo, ta thấy các giá trị của đồng dư thức \\(ax \equiv 1 \pmod {m}\\) có thể được viết thành đẳng thức \\(ax = 1 + m(-y)\\) với \\(y\\) là một số nguyên bất kì. Ta viết lại đẳng thức này thành phương trình \\(ax + my = 1\\). 

Phương trình \\(ax + my = 1\\) là một phương trình Diophantine tuyến tính hai ẩn. Phương trình chỉ có nghiệm khi hai số \\(a\\) và \\(m\\) nguyên tố cùng nhau. Điều kiện này khớp với điều kiện để có nghịch đảo modulo.

```C++
int modInv(int a, int m){
	int d, x, y;
	tie(d, x, y) = extgcd(x, y); // hàm euclid mở rộng ở phần `Ước số - bội số`
	if (d != 1) return -1; // không tồn tại nghịch đảo modulo
	x = (x % m + m) % m; 
	return x; // nghịch đảo modulo
}
```

Độ phức tạp của thuật toán bằng \\(O(\log{a})\\).

## Tính nhanh nghịch đảo modulo trong đoạn \\([1; m - 1]\\)

Giả sử \\(m\\) là số nguyên tố. Khi này, ta có thể tìm được nghịch đảo modulo của các số \\(a\\) trong khoảng từ \\([1; m - 1]\\) bằng công thức \\[a^{-1} = -kr^{-1} \bmod {m}\\]

Với \\(a\\) là số cần tìm nghịch đảo modulo, \\(k, r\\) là các số có giá trị sao cho \\(ka + r = m\\) (\\(k = \left \lfloor \frac{m}{a} \right \rfloor,\ r = m \bmod {a}\\)). 
	
Với \\(m = ka + r \\ (k = \left \lfloor \frac{m}{a} \right \rfloor,\ r = m \bmod {a})\\), ta có:

\\[
\begin{align*}
&      & m        & \equiv 0      & \pmod{m} \\\\
& \iff & ka + r   & \equiv 0      & \pmod{m} \\\\
& \iff & -ka      & \equiv r      & \pmod{m} \\\\
& \iff & -kr^{-1} & \equiv a^{-1} & \pmod{m} \\\\
\end{align*}
\\]

Nguyên nhân \\(m\\) phải là số nguyên tố là bởi như đã nói ở trên: để tìm nghịch đảo modulo của \\(a\\) với modulo \\(m\\) thì \\(a, m\\) phải nguyên tố cùng nhau. Mặc dù ta có thể đảm bảo \\(a\\) với \\(m\\) nguyên tố cùng nhau, nhưng chưa chắc ta có thể đảm bảo \\(r\\) và \\(m\\) cũng nguyên tố cùng nhau.
</details>

Khi duyệt từ \\([1; m - 1]\\), các giá trị \\(r^{-1}\\) đã được tính trước do \\(r \lt a\\).

```C++
int inv[N];

void findInv(int m){
	inv[1] = 1;
	for(int i = 2; i < m; ++i){
		inv[i] = m - 1ll * (m / i) * inv[m % i] % m;
	}
}
```

Độ phức tạp của thuật toán này bằng \\(O(m)\\).

## Tính nhanh nghịch đảo modulo của một mảng

Để tính nghịch đảo modulo của một mảng, ta có thể tính bằng cách tìm nghịch đảo modulo của từng phần tử một (độ phức tạp \\(O(n \log{m})\\)) hoặc tính nhanh nghịch đảo modulo trong đoạn \\([1; m - 1]\\) rồi tìm phần tử tương ứng (độ phức tạp \\(O(m)\\)). Thay vì thế, ta chỉ cần thực hiện một lần tính nghịch đảo modulo  của tích tất cả các phần tử. Khi tìm nghịch đảo của một phần tử, ta chỉ cần nhân nó với các phần tử còn lại trong mảng.

\\[
\begin{align}
\frac{1}{x_i} &= \frac{x_1x_2\dots x_{i - 1} \times 1 \times x_{i + 1}\dots x_{n - 1}x_n}{x_1x_2\dots x_{n - 1}x_n} \\\\
&= (x_1x_2\dots x_{i - 1}x_{i + 1}\dots x_{n - 1}x_n) \times (x_1x_2\dots x_{n - 1}x_n)^{-1}
\end{align}
\\]

```C++
vector<int> arrInv (vector<int> &arr, int m){
	int n = arr.size();
	int v = 1; 
	vector<int> inv(n, 0);
	for(int i = 0; i < n; ++i){
		inv[i] = v;
		v = (1ll * v * arr[i]) % m;
	}
	v = modInv(v, m);
	for(int i = n - 1; i >= 0; --i){
		inv[i] = (1ll * inv[i] * v) % m;
		v = (1ll * v * arr[i]) % m;
	}
	return inv;
}
```

Độ phức tạp của thuật toán bằng \\(O(n + \log{m})\\) với \\(n\\) là kích thước mảng.

Ta cũng có thể làm điều tương tự để tính nghịch đảo modulo của \\(n\\) giai thừa đầu tiên: \\(a!^{-1} = (a + 1)!^{-1} \times a\\).

```C++
vector<int> facInv (int n, int m){
	int v = 1; 
	for(int x = 2; x <= n; ++x){
		v = (1ll * v * x) % m;
	}
	vector<int> inv(n + 1, 1);
	inv[n] = modInv(v, m);
	for(int i = n; i >= 1; --i){
		inv[i - 1] = (1ll * inv[i] * i) % m;
	}
	return inv;
}
```

Độ phức tạp của thuật toán này cũng bằng \\(O(n + \log{m})\\).