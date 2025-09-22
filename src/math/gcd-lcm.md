# Ước chung lớn nhất - Bội chung nhỏ nhất

## Ước chung lớn nhất

Với hai số nguyên \\(a\\) và \\(b\\), ta có **ước chung lớn nhất - UCLN (Greatest Common Divisor - GCD)** của hai số là số nguyên dương lớn nhất chia hết cho cả hai số \\(a\\) và \\(b\\). Ví dụ, UCLN của \\(6\\) và \\(8\\) là \\(UCLN(6, 8) = 2\\).

Nếu \\(a\\) hoặc \\(b\\) bằng \\(0\\), giá trị UCLN sẽ bằng trị tuyệt đối của số còn lại: \\(UCLN(0, a) = |a|\\). Ta không thể tính \\(UCLN(0, 0)\\).

Hai số \\(a\\) và \\(b\\) nguyên tố cùng nhau khi \\(UCLN(a, b) = 1\\). 

### Tìm UCLN

#### Phân tích thừa số nguyên tố

Giả sử \\(a\\) được phân tích thành thừa số nguyên tố \\(p_1^{u_1} \times p_2^{u_2} \times \cdots \times sp_k^{u_k}\\), và \\(b\\) là \\(p_1^{v_1} \times p_2^{v_2} \times \cdots \times sp_k^{v_k}\\), ta có thể tính được giá trị UCLN của hai số sẽ bằng:

\\[UCLN(a, b) = p_1^{min(u_1, v_1)} \times p_2^{min(u_2, v_2)} \times \cdots \times sp_k^{min(u_k, v_k)}\\]

#### Thuật toán Euclid

Thuật toán Euclid là thuật toán UCLN dựa trên nhận xét rằng với hai số \\(a > b\\), UCLN của \\(a\\) và \\(b\\) sẽ bằng UCLN của \\(a - b\\) và \\(b\\). Ta có thể lặp lại quá trình này cho tới khi giá trị của hai số bằng nhau, và quá trị ấy chính là UCLN của hai số ban đầu.

Ví dụ, để tính \\(UCLN(180, 196)\\):

\\[
\begin{align*}
UCLN (180, 196) & \rightarrow & UCLN(180, 196 - 180) = UCLN(180, 16)  \\\\
				& \rightarrow & UCLN(180 - 16, 16) = UCLN(164, 16)  \\\\
				& \rightarrow & UCLN(164 - 16, 16) = UCLN(148, 16)  \\\\
				& \cdots \\\\
				& \rightarrow & UCLN(20 - 16, 16) = UCLN(4, 16)  \\\\
				& \cdots \\\\
				& \rightarrow & UCLN(4, 8 - 4) = UCLN(4, 4)  \\\\
\end{align*}
\\]

Vậy \\(UCLN(180, 196) = 4\\).

```C++
// giả sử a và b không âm
int gcd(int a, int b){
	while(a != b) { 
		if(a < b) swap(a, b);
		a -= b;
	}
	return a;
}
```

Ta có thể tối ưu thuật toán bằng cách cập nhật \\(a\\) thành \\(a \bmod b\\) thay vì \\(a - b\\). Thuật toán khi này sẽ kết thúc khi \\(a\\) hoặc \\(b\\) bằng \\(0\\), và UCLN sẽ bằng giá trị số còn lại.

Ví dụ, để tính \\(UCLN(180, 196)\\):

\\[
\begin{align*}
UCLN (180, 196) & \rightarrow & UCLN(180, 196 \bmod 180) = UCLN(180, 16)  \\\\
				& \rightarrow & UCLN(180 \bmod 16, 16) = UCLN(4, 16)  \\\\
				& \rightarrow & UCLN(4, 16 \bmod 4) = UCLN(4, 0)  \\\\
\end{align*}
\\]

Vậy \\(UCLN(180, 196) = 4\\).

```C++
// giả sử a và b không âm
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
```

Độ phức tạp của thuật toán tối ưu này là \\(O(\log{min(a, b)})\\).

Trong C++, ta có sẵn hàm `__gcd` để tìm UCLN.

## Bội chung nhỏ nhất

Với hai số nguyên \\(a\\) và \\(b\\), ta có **bội chung nhỏ nhất - BCNN (Least Common Multiple - LCM)** của hai số là số nguyên dương nhỏ nhất là bội số của cả \\(a\\) và \\(b\\). Ví dụ, BCNN của \\(6\\) và \\(8\\) là \\(BCNN(6, 8) = 48\\).

### Tìm BCNN

#### Phân tích thừa số nguyên tố

Giống như khi ta tìm UCLN, ta có thể tính được giá trị BCNN của hai số sẽ bằng:

\\[BCNN(a, b) = p_1^{max(u_1, v_1)} \times p_2^{max(u_2, v_2)} \times \cdots \times sp_k^{max(u_k, v_k)}\\]

Từ đây, ta có nhận xét khá hay rằng: \\(|a \times b| = UCLN(a, b) \times BCNN(a, b)\\)

#### Sử dụng UCLN

Sử dụng các phương thức tìm UCLN và công thức được nói ở trên, ta có thể tìm giá trị BCNN sẽ bằng:

\\[BCNN(a, b) = \frac{|a \times b|}{UCLN(a, b)}\\] 

## Thuật toán Euclid mở rộng

Thuật toán Euclid mở rộng là một thuật toán bên cạnh việc tìm UCLN của \\(a\\) và \\(b\\), nó còn tìm cặp nghiệm \\((x, y)\\) thoả mãn phương trình: \\[ax + by = UCLN(a, b)\\]

Để giải quyết bài toán này, ta quay lại với việc tính UCLN. Việc thay \\(a\\) bằng \\(a \bmod b\\) tương tự với việc thay \\(a\\) bằng \\(r\\) với \\(r\\) nằm trong phương trình \\(a = bq + r \\ (q = \left\lfloor\frac{a}{b}\right\rfloor, r = a \bmod b)\\).

Để tìm cặp nghiệm \\((x, y)\\) thoả mãn phương trình \\(ax + by = UCLN(a, b)\\), ta cần gán thêm một số thông tin. 

Gọi \\((x_a, y_a)\\) là cặp nghiệm thoả mãn \\(ax_a + by_a = a\\), ta có thể tính được \\((x_a, y_a) = (1, 0)\\). Tương tự, ta có \\(x_b, y_b\\) là cặp nghiệm thoả mãn \\(ax_b + by_b = b\\). Ở đây, \\((x_b, y_b) = (0, 1)\\).

Với phương trình \\(a = bq + r\\), ta có thể tính được cặp nghiệm \\((x_r, y_r)\\) sao cho \\(ax_r + by_r = r\\) với \\((x_r, y_r) = (x_a - q \times x_b, y_a - q \times y_b)\\). 

Sau khi đã tìm được UCLN của hai số, cặp nghiệm của UCLN sẽ là cặp nghiệm của phương trình gốc mà ta cần tìm.

```C++
tuple<int, int, int> extgcd(int a, int b){
	int xa = 1, ya = 0, xb = 0, yb = 1;	
	while(b){
		int q = a / b;
		tie(a, b) = make_tuple(b, a % b);
		tie(xa, xb) = make_tuple(xb, xa - q * xb);
		tie(ya, yb) = make_tuple(yb, ya - q * yb);
	}

	return make_tuple(a, xa, ya);
}
```

Độ phức tạp của thuật toán mở rộng tương đương với độ phức tạp của thuật toán Euclid gốc: \\(O(\log{min(a, b)})\\).

Ta còn có cách cài đặt đệ quy có độ phức tạp tương tự:

```C++
tuple<int, int, int> extgcd(int a, int b){
	if(b == 0) return {a, 1, 0};
	int x, y, d; 
	tie(d, x, y) = ext_gcd(b, a % b);
	return make_tuple(d, y, x - y * (a / b));
}
```