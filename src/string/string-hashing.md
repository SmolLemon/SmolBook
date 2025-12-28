# Băm xâu

**Thuật toán băm xâu** là một thuật toán vô cùng hữu ích trong lập trình thi đấu. 

Ta đã được biết về băm nói chung qua CTDL [bảng băm](../data-structures/hash-table.md).

## Thuật toán

Công năng của thuật toán băm xâu được thể hiện rõ qua ví dụ về bài toán so khớp chuỗi. **Bài toán so khớp chuỗi** là một bài toán về xâu kí tự, yêu cầu ta tìm các xâu \\(S\\) có độ dài \\(m\\) xuất hiện dưới dạng xâu con của một xâu \\(T\\) có độ dài \\(n\\). Thông thường các bài toán này có \\(n\\) rất lớn. 

Ta có thuật toán sau: kiểm tra *tất cả* các xâu con có độ dài \\(m\\) của xâu \\(T\\) và kiểm tra xem liệu nó có bằng xâu \\(S\\) hay không. 

Dễ thấy, độ phức tạp của thuật toán trên sẽ bằng \\(O(nm)\\), do ở xâu \\(T\\) tồn tại \\(n - m + 1\\) xâu con có độ dài \\(m\\) và với mỗi xâu con này, ta cần kiểm tra từng kí tự của nó với kí tự ở xâu \\(T\\) tương ứng có khác nhau hay không.

Thuật toán băm xâu sẽ thực hiện "băm" các xâu thành một giá trị nào đó thông qua [hàm băm](#hàm-băm). Với giá trị này, ta có thể nhanh chóng kiểm tra xem nếu hai xâu có giống nhau hay không bằng cách kiểm tra giá trị băm của nó, từ đó giảm đáng kể độ phức tạp thuật toán.

Quay lại với bài toán so khớp chuỗi, với hàm băm, ta có thể so sánh xâu con của \\(T\\) với \\(S\\) trong \\(O(1)\\), từ đây độ phức tạp giảm xuống chỉ còn \\(O(n)\\). 

## Hàm băm

Gọi hàm \\(hash(s)\\) là một hàm trả về giá trị băm của một xâu \\(s\\). Phương pháp phổ biến để tính giá trị băm của một xâu \\(S\\) với độ dài \\(n\\) có dạng như sau:

\\[
\begin{align}
hash(s) = hash(s_0s_1\cdots s_{n}s_{n-1}) &= \sum_{i=0}^{n-1} s_i \times p^{n-i-1} \bmod{m} \\\\
&= (s_0 \times p^{n-1} + s_1 \times p^{n-2} + \cdots + s_{n - 2} \times p + s_{n-1}) \bmod{m}
\end{align}\\]

Với \\(s_i\\) là các kí tự của xâu s. Hai số \\(p\\) và \\(m\\) là các tham số. 

Khi tính toán, ta chuyển đổi \\(s_i\\) thành một số nguyên - có thể chuyển đổi thành thứ tự trong bảng chữ cái hoặc bảng ASCII, giá trị của \\(p\\) cũng phải lớn hơn dạng số nguyên của các kí tự này. Để tránh việc giá trị băm quá lớn, ta modulo giá trị cho một số \\(m\\) thường là số nguyên tố. 

```C++
const int P, M;

int Hash(string &s) {
	int hash_value = 0;
	for(char c : s) {
		// chuyển đổi thành thứ tự bảng ASCII
		hash_value = (1ll * hash_value * P + int(c)) % M;
	}
	return hash_value;
}
```

Độ phức tạp của việc băm xâu là \\(O(|S|)\\).

### Giá trị băm của xâu con

Để tính giá trị băm của các xâu con của \\(s\\), ta có thể tiền xử lí các tiền tố của nó, từ đó tính được giá trị băm của các xâu con. Gọi \\(hsh(i)\\) là giá trị băm của \\(i\\) kí tự đầu tiên của xâu \\(s\\), ta có: \\[hsh(l) = (hsh(l - 1) \times p + s_{l - 1}) \bmod{m}\\]

Với trường hợp cơ sở \\(hsh(0) = 0\\).

Dễ thấy: \\(hash(s_0s_1\cdots s_{i-1}) = hsh(i)\\).

Lưu trữ các giá trị \\(hsh(i)\\), ta có thể tính nhanh giá trị băm của xâu con của \\(s\\) gồm các kí tự từ kí tự thứ \\(i\\) đến kí tự thứ \\(j\\) bằng: \\[hash(s_{i-1}s_{i-2}\cdots s_{j-2}s_{j-1}) = (hsh(j) - hsh(i-1)\times p^{j - i + 1}) \bmod{m}\\]

```C++
int hsh[N], Pow[N];
void preprocess(string &s){
	int n = s.size();
	hsh[0] = 0;
	Pow[0] = 1;
	for(int i = 1; i <= n; ++i) {
		Pow[i] = (1ll * Pow[i-1] * P) % M;
		hsh[i] = ((1ll * hsh[i-1] * P) + int(s[i-1])) % M;
	}
}

int Hsh(int l, int r) {
	return (hsh[r] - 1ll * hsh[l-1] * Pow[r - l + 1] + 1ll * M * M) % M;
}
```

Việc tiền xử lí tính giá trị băm của các tiền tố có độ phức tạp \\(O(|S|)\\). Sau đó, ta có thể tính giá trị băm của các xâu con trong \\(O(1)\\).

## Hạn chế va chạm băm

Ta có xác suất về khả năng **va chạm băm** của hai xâu \\(a\\) và \\(b\\), hay \\(hash(a) = hash(b)\\) nằm trong khoảng \\(P \equiv \frac{1}{m}\\). Từ đây, ta có xác suất việc *không xảy ra* va chạm băm sẽ bằng \\(\left(1 - \frac{1}{m}\right)\\). Tổng quát hơn, ta có khả năng không xảy ra va chạm băm khi so sánh \\(n\\) cặp xâu sẽ bằng \\(\left(1 - \frac{1}{m}\right)^n\\).

Nếu \\(m = 10^9 + 7\\), ta có thể yên tâm so sánh một vài, thâm chí là hơn \\(100\\) cặp cũng không sao, nhưng nếu bài yêu cầu so sánh các xâu con của một xâu có độ dài \\(10^5\\) thì xác suất không xảy ra va chạm băm sẽ chỉ còn là \\(0,0067\\).

Để khắc phục vấn đề này, ta có thể tăng giá trị của \\(m\\), hoặc modulo \\(\left(\sum_{i=0}^{n-1} s_i \times p^{n-i-1}\right)\\) cho nhiều tham số \\(m\\) khác nhau với hiệu quả tương đương. Với phương pháp thứ hai, ta xét hai xâu bằng cách xét giá trị băm trên modulo của từng tham số \\(m\\), nếu tất cả giống nhau thì hai xâu giống nhau, không thì ngược lại. Giả sử ta có \\(k\\) tham số \\(m\\), xác suất xảy ra va chạm băm khi so sánh xâu bằng: \\[P = \frac{1}{m_1 \times m_2 \times \cdots \times m_k}\\]

> [!IMPORTANT]
> Lưu ý rằng không nên có quá nhiều tham số \\(m\\) do việc modulo nhiều lần có thể làm chậm chương trình. 