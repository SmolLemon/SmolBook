# Số nguyên tố

Một số tự nhiên lớn hơn \\(1\\) được gọi là một **số nguyên tố (prime number)** khi nó chỉ chia hết cho hai số là \\(1\\) và chính nó. Ví dụ với số \\(5\\) là số nguyên tố vì nó chỉ chia hết cho \\(1\\) và \\(5\\), trong khi \\(6\\) không phải là số nguyên số vì nó chia hết cho \\(4\\) số - \\(1, 2, 3\\) và \\(6\\). Các số tự nhiên lớn hơn \\(1\\) không phải số nguyên tố được gọi là **hợp số (composite number)**.

Các số nguyên tố đầu tiên nhỏ hơn \\(100\\) là: \\(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97\\).

## Tính chất

Ta có một số tính chất về số nguyên tố khá phổ biến sau:

### Thừa số nguyên tố

Một hợp số bất kì đều có thể phân tích thành các thừa số nguyên tố, đồng thời các thừa số nguyên tố này là độc nhất với mọi hợp số.

Ví dụ, ta phân tích số \\(2025\\) thành các thừa số nguyên tố: \\(2025 = 3 \times 3  \times 3 \times 3 \times 5 \times 5 = 3^4 \times 5^2\\). Số nguyên tố cũng có thể được phân tích thành thừa số nguyên tố, với chính nó là một thừa số nguyên tố.

Ta có: \\(n = p_1^{q_1} \times p_2^{q_2} \times \dots p_k^{q_k}\\)

Một số công thức liên quan đến số \\(n\\):

- **Số lượng ước số** của \\(n\\) bằng:

\\[\tau(n) = \prod_{i = 1}^{k} (q_i + 1)\\]

- **Tổng các ước số** của \\(n\\) bằng:

\\[\sigma(n) = \prod_{i = 1}^{k} (1 + p_i + \dots + p_i^{q_i}) = \prod_{i = 1}^{k} \frac{p_i^{q_i + 1} - 1}{p_i - 1} \\]

### Số lượng số nguyên tố

Tồn tại vô hạn số nguyên tố. Định lí Euclid chứng minh điều này bằng cách phản chứng. 

Giả sử tồn tại hữu hạn số nguyên tố, và tất cả các số nguyên số đều nằm trong một tập hợp \\(P = \\{p_1, p_2, \dots, p_n\\}\\). Ta tạo một số mới \\(N\\) có giá trị bằng tích tất cả số nguyên tố cộng \\(1\\), hay 

\\[N = p_1 \times p_2 \times \dots \times p_n + 1\\]

Dễ thấy, \\(N\\) nguyên tố cùng nhau với \\(p_1, p_2, \dots, p_n\\). Tuy nhiên, vì \\(N > 1\\) nên ta có thể phân tích \\(N\\) thành các thừa số nguyên tố và sẽ tồn tại một số nguyên tố \\(p\\). Tuy nhiên, do \\(p \notin P\\) nên nó mâu thuẫn với việc tất cả các số nguyên tố đều thuộc \\(P\\). Vậy ta kết luận có vô hạn số nguyên tố.

#### Số lượng số nguyên tố nhỏ hơn hoặc bằng \\(n\\)

Để xác định tương đối số lượng số nguyên tố nhỏ hơn hoặc bằng \\(n\\), hay \\(\pi(n)\\), ta sử dụng công thức \\(\pi(n) \approx \frac{n}{\ln{n}}\\). Ví dụ, ta có \\(\pi(2025) = 306\\), và \\(\frac{2025}{\ln{2025}} \approx 266\\).


## Một số thuật toán

Ta cùng điểm qua một số thuật toán liên quan đến số nguyên tố.

### Kiểm tra số nguyên tố

Một cách tiếp cận đơn giản cho bài toán kiểm tra một số \\(n\\) là số nguyên tố hay không chính là kiểm tra xem có tồn tại số nào trong khoảng \\([2; n - 1]\\) chia hết cho \\(n\\) không. 

```C++
bool isPrime(int n){
	if(n <= 1) return 0; // các số này không phải số nguyên tố
	for(int i = 2; i < n; ++i) {
		if (n % i == 0) return 0; // nếu tồn tại số chia hết thì không phải là số nguyên tố
	}
	return 1; // n là số nguyên tố
}
```

Độ phức tạp của thuật toán này là \\(O(n)\\), tuy nhiên ta có thể tối ưu thuật toán này.

Có thể dễ dàng chứng minh được rằng ta chỉ cần kiểm tra \\(n\\) có chia hết một trong các số trong khoảng \\([2; \sqrt{n}]\\) để xác định số nguyên tố. 

```C++
bool isPrime(int n){
    if(n <= 1) return 0; 
    for(int i = 2; 1ll * i * i <= n; ++i){ // i <= sqrt(n) <=> i * i <= n
        if(n % i == 0) return 0;
    }
    return 1;
}
``` 

Độ phức tạp được cải thiện thành \\(O(\sqrt{n})\\).

Ta có thể tối ưu hơn nữa bằng cách xét các số nguyên tố nhỏ hơn \\(\sqrt{n}\\).

```C++
vector<int> primes; // danh sách số nguyên tố

bool isPrime(int n){
    if(n <= 1) return 0; 
    for(int i : primes){ 
        if(1ll * i * i > n) break;
        if(n % i == 0) return 0;
    }
    return 1;
}
```

Độ phức tạp bây giờ là \\(O(\pi(\sqrt{n}))\\).

### Sàng số nguyên tố

Thuật toán sàng là thuật toán tìm các số nguyên tố trong khoảng \\([2, n]\\) bằng một nhận xét đơn giản nhưng tài tình: Nếu \\(p\\) là một số nguyên tố thì các bội số lớn hơn \\(p\\) của nó: \\(2p, 3p, 4p, \dots\\) không phải là số nguyên tố.

Từ nhận xét trên, ta có thuật toán sàng số nguyên tố sau:
- Tạo một mảng bao gồm các số từ \\(2\\) tới \\(n\\).
- Bắt đầu từ số nguyên tố đầu tiên \\(p\\) là \\(2\\), ta đánh đấu tất cả các bội số lớn hơn \\(2\\) của \\(2\\): (\\(2p, 3p, 4p, \dots\\)) có trong mảng không phải là số nguyên tố.
- Tìm phần tử nhỏ nhất lớn hơn \\(p\\) chưa được đánh dấu, phần tử ấy sẽ là số nguyên tố tiếp theo. Ta thực hiện tương tự số nguyên tố \\(2\\).
- Lặp lại bước trên cho tới khi không còn số nào thoả mãn.

```C++
bitset<N> isPrime; // phần tử có phải số nguyên tố hay không

void sieve(int n){
	isPrime.set(); // tất cả các giá trị isPrime bằng 1
	isPrime[0] = isPrime[1] = 0; // 0, 1 không phải số nguyên tố
	for (int i = 2; i <= n; ++i){
		if(isPrime[i]){ // nếu i là số nguyên tố
			for(int j = i * 2; j <= n; j += i) isPrime[j] = 0; // các bội số không phải số nguyên tố
		}
	}
}
```
Độ phức tạp của thuật toán sàng là \\(O(n\log{\log{n}})\\).

Ta có một số phương pháp tối ưu khi sàng số nguyên tố.
- Đánh dấu từ bội số thứ \\(p\\) của số nguyên tố \\(p\\). Dễ thấy, khi xoá các bội số của \\(p\\), các bội số từ \\(2\\) đến \\(p - 1\\) của \\(p\\) đều đã được đánh dấu ở các lần trước đó. Ví dụ, ta không cần đánh dấu bội số thứ \\(3\\) của số nguyên tố \\(7\\), tức số \\(21\\), bởi vì số này đã được đánh dấu tại lần đánh dấu các bội số của số nguyên tố \\(3\\).
- Chỉ đánh dấu các bội số của các số từ \\(2\\) đến \\(\sqrt{n}\\). Việc sàng về cơ bản đã hoàn thành khi ta duyệt tới \\(\sqrt{n}\\) - tất cả các bội số của các số nguyên tố đã được đánh dấu. 

#### Tìm thừa số nguyên tố nhỏ nhất

Thuật toán sàng số nguyên tố có thể được sửa đổi để tìm thừa số nguyên tố nhỏ nhất các số trong khoảng \\([2; n]\\).

```C++
int spf[N];

void sievePrime(int n){
	for (int i = 2; i <= n; ++i){
		if(spf[i] == 0){
			for(int j = i; j <= n; j += i){
				if(spf[j] == 0) spf[j] = i;
			}
		}
	}
}
```

Độ phức tạp thuật toán tương tự thuật toán sàng.

#### Sàng trên đoạn

Ta có thể sàng số nguyên tố trong một khoảng lớn \\((l \le r \le 10^{14}, n = r - l + 1 \le 10^7)\\) bằng cách áp dụng triệt để các phương pháp tối ưu ở trên. 

Việc cần đánh dấu các bội số của các số nguyên tố \\(\le \sqrt{n}\\) đã có thể tìm được tất cả các số nguyên tố \\(\le n\\). Từ đây suy ra rằng ta chỉ cần tìm tất cả các số nguyên tố nhỏ hơn \\(\sqrt{r}\\) để sàng các số nguyên tố trong khoảng \\([l; r]\\).

Do đó, với mỗi số nguyên tố \\(p\\) nhỏ hơn \\(\sqrt{r}\\), ta đánh dấu từ bội số thứ \\(p\\) hoặc từ bội số nhỏ nhất của \\(p\\) mà lớn hơn hoặc bằng \\(l\\).

```C++
bitset<N> isPrime;

void sieve(ll l, ll r){
	// Tìm các số nguyên tố nhỏ hơn sqrt(r)
	isPrime.set(); 
	isPrime[0] = isPrime[1] = 0; 
	vector<int> prime;
	int n = sqrt(r);
	for (int i = 2; i <= n; ++i){
		if(isPrime[i]){ 
			prime.emplace_back(i);
			for(int j = i * 2; j <= n; j += i) isPrime[j] = 0; 
		}
	}

	// sàng số nguyên tố các số trong khoảng [l; r]
	isPrime.set(); 
	// x là số nguyên tố nếu isPrime[x - l] == true
	for(int i : prime){
		// ((l + i - 1) / i) * i là bội số nhỏ nhất của i lớn hơn hoặc bằng l
		for(ll j = max(1ll * i * i, (l + i - 1) / i * i); j <= r; j += i){
			isPrime[j - L] = 0;
		}
	}
}
```

Độ phức tạp của thuật toán là \\(O(n \log{\log{r}} + \sqrt{r}\log{\log{\sqrt{r}}})\\).

### Phân tích thành các thừa số nguyên tố

Việc phân tích một số \\(n\\) thành các thừa số nguyên tố có thể được thực hiện một cách đơn giản.

```C++
// giả sử n = a^x * b^y * c^z thì hàm sẽ trả về mảng pf = {(a, x), (b, y), (c, z)}
vector<pair<int, int>> primeFactorization(int n){
	vector<pair<int, int>> pf;
	if (n <= 1) return pf; // không phải số nguyên tố
	for (int i = 2; 1ll * i * i <= n; ++i){ 
		if(n % i == 0){ // nếu i là thừa số nguyên tố của n
			pf.emplace_back(i, 0); // thêm i
			while(n % i == 0){
				n /= i;
				++pf.back().second; // đếm số lượng thừa số nguyên tố i
			}
		}
	}
	if(n != 1) pf.emplace_back(n, 1); // thừa số nguyên tố duy nhất >= sqrt(n)
	return pf;
}
```

Độ phức tạp của thuật toán này là \\(O(\sqrt{n})\\).

Ta có thể sử dụng thừa số nguyên tố nhỏ nhất của một số để tính nhanh các thừa số nguyên tố của \\(n\\).

```C++
vector<pair<int, int>> primeFactorization(int n){
	vector<pair<int, int>> pf;
	if (n <= 1) return pf;
	while(n != 1){
		if(pf.empty() || pf.back().first != spf[n]) pf.emplace_back(spf[n], 0); 
		++pf.back().second;
		n /= spf[n];
	}
	return pf;
}
```

Độ phức tạp của thuật toán này là \\(O(\log{n})\\).