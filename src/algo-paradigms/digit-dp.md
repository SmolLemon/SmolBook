# Quy hoạch động chữ số

*Quy hoạch động chữ số* hay *Digit DP* chỉ các bài toán sử dụng quy hoạch động liên quan đến các chữ số.

## Lý thuyết

Các bài QHĐ chữ số sẽ có mô tả như sau: Cho một khoảng số \\([a, b]\\), hãy đếm số lượng số trong khoảng thỏa mãn yêu cầu đề bài.

Gọi \\(G(X)\\) là số lượng số nằm trong khoảng \\([0, X]\\) thỏa mãn yêu cầu đề bài. Khi này ta có thể tính được đáp án của bài toán bằng công thức: \\(G(b) - G(a - 1)\\) hoặc \\(G(b) - G(a) + g(a)\\) với \\(g(x)\\) là một hàm trả về \\(1\\) nếu \\(x\\) thỏa mãn yêu cầu và \\(0\\) nếu không thỏa mãn.

### Xây dựng hàm \\(G(X)\\)

Để xây dựng hàm \\(G(X)\\), ta sẽ xem các số trong khoảng \\([0, X]\\) như một xâu kí tự: Ta có \\(X = \overline{x_{n - 1}x_{n - 2}...x_{0}}\\) với \\(n\\) là số chữ số trong \\(X\\). Ta sẽ tạo các số \\(A = \overline{a_{n - 1}a_{n - 2}...a_{0}}\\) nhỏ hơn hoặc bằng \\(X\\), và ta thực hiện việc gán giá trị cho các chữ số của \\(A\\) theo chiều từ trái sang phải.

Giả sử ta có \\(X = 3141\\):

|\\(x_3\\)|\\(x_2\\)|\\(x_1\\)|\\(x_0\\)|
|---|---|---|---|
|\\(3\\)|\\(1\\)|\\(4\\)|\\(1\\)|

Ta thực hiện việc gán giá trị cho phần tử \\(a_i\\):

#### Trường hợp không giới hạn

Giả sử ta đã điền các chữ số ở trước \\(a_1\\) bằng các giá trị sau:

|\\(a_3\\)|\\(a_2\\)|\\(a_1\\)|\\(a_0\\)|
|---|---|---|---|
|\\(2\\)|\\(1\\)|\\(\*\\)|\\(\*\\)|

Trường hợp không giới hạn sẽ xảy ra nếu các số được điền trước \\(a_i\\) có thứ tự từ điển nhỏ hơn hẳn \\(X\\). Khi này, ta có thể điền \\(a_i\\) các chữ số từ \\(0\\) đến \\(9\\).

Ở đây, vì \\(21 < 31\\) nên \\(a_1\\) rơi vào trường hợp không giới hạn. Vì vậy ta được quyền gán cho \\(a_1\\) các chữ số từ \\(0\\) đến \\(9\\). Ta có thể kết luận như vậy vì dù có gán \\(a_1\\) bằng chữ số nào đi nữa thì các số có dạng \\(\overline{21**}\\) cũng sẽ nhỏ hơn \\(X\\).

#### Trường hợp có giới hạn

Giả sử ta đã điền các chữ số ở trước \\(a_1\\) bằng các giá trị sau:

|\\(a_3\\)|\\(a_2\\)|\\(a_1\\)|\\(a_0\\)|
|---|---|---|---|
|\\(2\\)|\\(1\\)|\\(\*\\)|\\(\*\\)|

Trường hợp không giới hạn sẽ xảy ra nếu các số được điền trước \\(a_i\\) là một tiền tố của số \\(X\\). Khi này, ta chỉ có thể điền \\(a_i\\) các chữ số từ \\(0\\) đến \\(x_i\\).

Ở đây, ta có \\(31\\) là một tiền tố của \\(X\\) nên rơi vào trường hợp có giới hạn. Ta chỉ có thể gán cho \\(a_1\\) các chữ số từ \\(0\\) đến \\(x_1 = 4\\). Giả sử ta gán \\(a_1 = 5\\). Khi này, các số có dạng \\(\overline{315*}\\) sẽ có giá trị lớn hơn \\(X\\), và các số có dạng này là các số mà ta không cần xét đến.

Từ \\(2\\) trường hợp trên, ta có các trạng thái QHĐ cần thiết để giải một bài toán QHĐ chữ số:

\\[f(idx, smaller, S_1, S_2, ..., S_k) \\]

Trong đó:

- \\(idx\\) là chỉ số ta cần điền
- \\(smaller\\) bằng \\(0/1\\) với ý nghĩa:	
	- \\(smaller = 0\\) nếu rơi vào trường hợp có giới hạn.
	- \\(smaller = 1\\) nếu rơi vào trường hợp không giới hạn.
- \\(S_1, S_2, ...,S_k\\) là các tính chất của đoạn số \\(\overline{a_{n - 1}a_{n - 2}...a_{idx + 1}}\\).

Khi này, ta sẽ gọi hàm \\(f\\) để tính \\(G(X)\\):

\\[G(X) = f(n - 1, 0, S_1, S_2, ..., S_k)\\]

Độ phức tạp của QHĐ chữ số thường sẽ có dạng: \\(O(D \times 2 \times n \times S_1 \times S_2 \times ... \times S_k)\\), trong đó:
- \\(D\\) là hệ số của số đang xét.
- \\(n\\) là số chữ số của \\(X\\).

Ta cùng xem qua một số bài toán ví dụ để hiểu rõ hơn.

## Một số bài toán ví dụ

### Ví dụ 1: [Free Contest Testing Round 3 - DIGITSUM](https://oj.vnoi.info/problem/fct003_digitsum)

Tóm tắt: Cho hai số nguyên không âm \\(a\\) và \\(b\\), tính tổng chữ số của các số trong đoạn \\([a, b]\\).

Giới hạn: \\(0 \le a \le b \le 10^{15}\\).

Ví dụ: \\([49; 52] = 4 + 9 + 5 + 0 + 5 + 1 + 5 + 2 = 31\\).

Ta có các trạng thái QHĐ: \\((idx, smaller, sum)\\) với \\(idx\\), \\(smaller\\) có định nghĩa như trên và \\(sum\\) là tổng của các chữ số đã điền.

**Tính giá trị:**

Khi ta ở trạng thái \\((idx, smaller, sum)\\):

Nếu \\(idx = -1\\), ta không còn vị trí nào để điền giá trị, từ đấy ta trả về giá trị \\(sum\\). Nếu \\(idx\\) lớn hơn \\(-1\\), ta sẽ thực hiện gán giá trị cho \\(a_{idx}\\). 

Ta có thể điền các số từ \\(0\\) đến \\(limit\\) cho số \\(a_{idx}\\), với \\(limit = 9\\) nếu \\(smaller = 1\\), hoặc \\(limit = x_{idx}\\) nếu \\(smaller = 0\\). 

**Chuyển trạng thái:**

Giả sử ta đã điền được số cho \\(a_{idx}\\), ta sẽ bắt đầu điền số tiếp theo.

Nếu trạng thái của ta đang là \\((idx, smaller, sum)\\), và ta điền \\(a_{idx} = v\\), ta sẽ chuyển trạng thái tiếp theo \\((idx', smaller', sum')\\):

- \\(idx' = idx - 1\\).
- \\(smaller'\\):
	- Nếu \\(smaller = 1\\) thì \\(smaller' = 1\\).
	- Nếu \\(smaller = 0\\) thì \\(smaller' = 1\\) nếu \\(v < limit\\), \\(smaller' = 0\\) nếu \\(v = limit\\).
- \\(sum' = sum + v\\).


```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][20][200];
int x[20];

ll f(int idx, bool smaller, int sum);
ll G(ll X);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a, b; cin >> a >> b;
	cout << G(b) - G(a - 1);

	return 0;
}

ll f(int idx, bool smaller, int sum){
	if(idx < 0) return sum;
	ll &memo = dp[smaller][idx][sum];
	if(memo != -1) return memo;
	int lim = smaller ? 9 : x[idx];
	memo = 0;
	for(int digit = 0; digit <= lim; ++digit){
		memo += f(idx - 1, smaller || (digit < lim), sum + digit);
	}	
	return memo;
}

ll G(ll X){
	int n = 0; x[n] = 0;
	while(X > 0){
		x[n++] = X % 10;
		X /= 10;
	}
	memset(dp, -1, sizeof(dp));
	return f(n - 1, 0, 0);
}

```
Độ phức tạp của thuật toán này là \\(O(10 \times n \times 2 \times sum)\\).

Ngoài cách giải QHĐ chữ số, ta cũng có thể [giải theo phương pháp khác](https://oj.vnoi.info/problem/fct003_digitsum#comment-5859).

### Ví dụ 2: [Atcoder Educational DP Contest S - Digit Sum](https://oj.vnoi.info/problem/atcoder_dp_s)

Tóm tắt: Cho hai số \\(K\\) và \\(D\\), đếm số lượng số từ \\(1\\) đến \\(K\\) có tổng chữ số chia hết cho \\(D\\), modulo \\(10^9 + 7\\).

Giới hạn: \\(1 \le K \lt 10^{10000}\\), \\(D \lt 100\\).

Bài toán này tương tự với bài toán ở ví dụ \\(1\\), có \\(3\\) trạng thái QHĐ \\((idx, smaller, sum)\\) nhưng có một chút khác biệt.

Nếu \\(idx = -1\\), hàm \\(f\\) của ta trả về \\(1\\) nếu \\(sum = 0\\) và \\(0\\) trong các trường hợp còn lại. Đồng thời, việc chuyển trạng thái \\(sum\\) sang \\(sum'\\) cũng thay đổi thành \\(sum' = (sum + v) \mod{D}\\).

Một điều nữa là hàm \\(f\\) cũng sẽ xét cả số \\(0\\) mặc dù bài toán không yêu cầu nên kết quả bài toán sẽ là: \\((G(K) - 1) \mod{10^9 + 7}\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10;
const int MOD = 1e9 + 7;
ll dp[2][110][N];
int x[N];
int D;
string K;

ll f(int idx, bool smaller, int sum);
ll G(string &X);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> D;
	cout << G(K);		
	
	return 0;
}
ll f(int idx, bool smaller, int sum){
	if(idx < 0) return sum == 0;
	ll &memo = dp[smaller][sum][idx];
	if(memo != -1) return memo;
	memo = 0;
	int lim = smaller ? 9 : x[idx];
	for(int i = 0; i <= lim; ++i){
		memo += f(idx - 1, smaller || (i < lim), (sum + i) % D);
		memo %= MOD;
	}
	return memo;
}
ll G(string &X){
	int n = 0; x[n] = 0;
	for(int i = X.length() - 1; i >= 0; --i){
		x[n++] = X[i] - '0';
	}
	memset(dp, -1, sizeof dp);
	return (f(n - 1, 0, 0) -1 + MOD) % MOD;
}
```
Độ phức tạp của thuật toán này là \\(O(10 \times n \times 2 \times D)\\).

### Ví dụ 3: [Số lượng số](https://oj.vnoi.info/problem/snad)

Tóm tắt: Cho \\(T\\) cặp số \\([X; Y]\\), đếm số lượng số mà có tích của một số với tổng chữ số của nó đó nằm trong khoảng \\([X; Y]\\).

Giới hạn: \\(T \lt 21\\), \\(0 \lt X \le Y \lt 10^{19}\\).

Gọi \\(A\\) là một số thỏa mãn điều kiện. Vì \\(A\\) thỏa mãn điều kiện nên:

\\[X \le A \times d(A)\le Y\\]

Với \\(d(A)\\) là tổng các chữ số của \\(A\\).

Ta thấy rằng các số \\(X\\), \\(Y\\), \\(A\\) là các số rất lớn, nhưng \\(d(A)\\) lại nhỏ một cách bất ngờ - \\(d(x) \le 171, \forall{x} \lt 10^{19}\\).

Từ đây, ta có thể viết lại công thức trên như sau:

\\[\left\lfloor \frac{X}{d(A)}\right\rfloor \le A \le \left\lfloor \frac{Y}{d(A)}\right\rfloor\\]

Qua công thức này, ta đã chuyển đổi bài toán sang một dạng khác đơn giản hơn: Cho \\(S\\) chạy từ \\(1\\) đến \\(171\\), đếm số lượng số từ \\(\left\lfloor \frac{X}{S}\right\rfloor\\) đến \\(\left\lfloor \frac{Y}{S}\right\rfloor\\) có tổng chữ số bằng \\(S\\). 

Tổng các số đếm được sẽ là đáp án của bài toán gốc.

Ta có \\(3\\) trạng thái QHĐ: \\((idx, smaller, sum)\\).

Nếu \\(idx = -1\\), hàm \\(f\\) sẽ trả về \\(1\\) nếu \\(sum = S\\) và trả về \\(0\\) trong các trường hợp còn lại.

Việc chuyển đổi trạng thái \\((idx, smaller, sum)\\), sang \\((idx', smaller', sum')\\) sẽ tương tự ví dụ \\(1\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][20][180];
int x[20];
ll l, r; 
ll s;

ll f(int idx, bool smaller, int sum);
ll G(ll X);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> l >> r;
		--l;
		ll sum = 0;
		for(s = 1; s <= 171; ++s){
			sum += G(r / s) - G(l / s);
		}
		cout << sum << '\n';
	}
	return 0;
}
ll f(int idx, bool smaller, int sum){
	if(idx < 0) return sum == s;
	ll &memo = dp[smaller][idx][sum];
	if(memo != -1) return memo;
	int lim = smaller ? 9 : x[idx];
	memo = 0;
	for(int digit = 0; digit <= lim; ++digit){
		memo += f(idx - 1, smaller || (digit < lim), sum + digit);
	}	
	return memo;
}
ll G(ll X){
	if(X <= 0) return 0;
	int n = 0; x[n] = 0;
	for(; X > 0; ++n){
		x[n] = X % 10;
		X /= 10;
	}
	memset(dp, -1, sizeof(dp));
	return f(n - 1, 0, 0);
}
```

Độ phức tạp của thuật toán này là \\(O((10 \times n \times 2 \times sum) \times 171 \times T)\\).

#### Tối ưu QHĐ chữ số

Nhiều bài toán QHĐ chữ số (giống như bài này) có thể yêu cầu ta tính đi tính lại các khoảng số với cùng một tính chất. việc này vô tình làm cho thuật toán của ta chạy chậm đi khi phải tính đi tính lại các số.

Một cách tối ưu cực kì hay ho chính là ta sẽ chỉ thực hiện việc `memset` một lần ở ngoài hàm \\(G\\), đồng thời bỏ trạng thái \\(smaller\\) khi lưu kết quả của trạng thái. 

Vì các giá trị của trạng thái QHĐ có \\(smaller = 0\\) phụ thuộc vào một giá trị cụ thể, nên không thể sử dụng lại cho các số tiếp theo. Bằng cách loại bỏ trạng thái \\(smaller\\) khi lưu kết quả của trạng thái và xét riêng từng trường hợp \\(smaller\\), ta có thể sử dụng lại các kết quả đã được tính ở những lần trước.

Có thể xem qua đoạn code của bài toán khi áp dụng cách cài đặt mới:

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 20;
int x[N];
ll dp[N][172];

ll f(int idx, bool smaller, int sum);
ll G(ll X, ll sum);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));	
	int t; cin >> t;
	while(t--){
		ll x, y; cin >> x >> y;
		--x;
		ll cnt = 0;
		for(int i = 1; i < 172; ++i){
			cnt += G(y / i, i) - G(x / i, i);
		}
		cout << cnt << '\n';
	}


	
	return 0;
}
ll f(int idx, bool smaller, int sum){
	if(sum < 0) return 0;
	if(idx < 0) return !sum;
	ll &memo = dp[idx][sum];
	if(smaller && memo != -1) return memo;
	int lim = smaller ? 9 : x[idx];
	ll ans = 0;
	for(int i = 0; i <= lim; ++i){
		ans += f(idx - 1, smaller || (i < lim), sum - i);
	}

	if(smaller) return memo = ans;
	return ans;
}
ll G(ll X, ll sum){
	int n = 0;
	while(X){
		x[n++] = X % 10;
		X /= 10;
	}
	return f(n - 1, 0, sum);
}

```

Độ phức tạp của thuật toán giờ đây giảm xuống còn: \\(O(10 \times n \times sum)\\)

### Ví dụ 4: [NUMTSN - 369 Numbers](https://www.spoj.com/problems/NUMTSN/)

Tóm tắt: Cho \\(T\\) cặp số \\(A\\) và \\(B\\), với mỗi cặp số, đếm số lượng số \\(369\\) nằm trong khoảng \\([A; B]\\), modulo \\(10^9 + 7\\).

Một số \\(X\\) là số \\(369\\) khi số lượng chữ số \\(3\\) bằng số lượng chữ số \\(6\\) và bằng số lượng chữ số \\(9\\) và có ít nhất một chữ số \\(3\\). 

Giới hạn: \\(T \lt 100\\), \\(1 \le A \le B \le 10^{50}\\).

Ta có \\(5\\) trạng thái QHĐ: \\((idx, smaller, three, six, nine)\\) với \\(idx\\), \\(smaller\\) có định nghĩa như các ví dụ trước và \\(three\\), \\(six\\), \\(nine\\) là số lượng số \\(3\\), \\(6\\), và \\(9\\).

Nếu \\(idx = -1\\), hàm \\(f\\) trả về \\(1\\) nếu \\(three > 0, three = six = nine\\), và \\(0\\) trong các trường hợp còn lại.

Nếu trạng thái của ta đang là \\((idx, smaller, three, six, nine)\\), và ta điền \\(a_{idx} = v\\), ta sẽ chuyển trạng thái tiếp theo \\((idx', smaller', three', six', nine')\\):

- \\(idx'\\), \\(smaller'\\) giống các ví dụ trước.
- \\(three' = three + 1\\) nếu \\(v = 3\\) hoặc \\(three' = three\\) nếu \\(v \neq 3\\).
- \\(six' = six + 1\\) nếu \\(v = 6\\) hoặc \\(six' = six\\) nếu \\(v \neq 6\\).
- \\(nine' = nine + 1\\) nếu \\(v = 9\\) hoặc \\(nine' = nine\\) nếu \\(v \neq 9\\).

Vì \\(A, B\\) là những số rất lớn, ta áp dụng cách tính thứ hai được nói ở phần lý thuyết: \\((G(b) - G(a) + g(a)) \mod{10^9 + 7}\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll dp[51][51][51][51];
int x[51];

ll f(int idx, bool smaller, int three, int six, int nine);
ll G(string &X);
bool g(string &X);
int main (int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		cout << (G(b) - G(a) + g(a) + MOD) % MOD << '\n';
	}	



	
	return 0;
}
ll f(int idx, bool smaller, int three, int six, int nine){
	if(idx < 0) return three > 0 && three == six && three == nine;
	ll &memo = dp[idx][three][six][nine];
	if(smaller && memo != -1) return memo;
	ll ans = 0;
	int lim = smaller ? 9 : x[idx];
	for(int i = 0; i <= lim; ++i){
		ans += f(idx - 1, smaller || (i < lim), three + (i == 3), six + (i == 6), nine + (i == 9));
		ans %= MOD;
	}

	if(smaller) memo = ans;
	return ans;
}

ll G(string &X){
	int n = 0; x[n] = 0;
	for(int i = X.length() - 1; i >= 0; --i){
		x[n++] = X[i] - '0';
	}
	return f(n - 1, 0, 0, 0, 0);
}
bool g(string &X){
	int three = 0, six = 0, nine = 0;
	for(char c : X){
		three += c == '3';
		six += c == '6';
		nine += c == '9';
	}
	return three > 0 && three == six && three == nine;
}
```

Độ phức tạp của thuật toán là: \\(O(10 \times n \times three \times six \times nine)\\).

### Ví dụ 5: [Số đặc biệt](https://lqdoj.edu.vn/problem/pearlnum)

Tóm tắt: Ta có hàm \\(f(x)\\) trả về tổng bình phương các chữ số trong \\(x\\). Một số \\(x\\) được gọi là số đặc biệt nếu \\(x = 1\\) sau khi áp dụng không hoặc nhiều lần công thức: \\(x = f(x)\\). Cho \\(T\\) cặp số \\([L, R]\\), hãy cho biết số lượng số đặc biệt trong khoảng \\([L, R]\\).

Giới hạn: \\(T \le 100\\), \\(1 \le L \le R \le 10^{18}\\).

Một điều dễ nhận thấy đối với bài toán này là với mỗi \\(x \le 10^{18}\\), \\(f(x) \le 1458\\). Vì vậy, ta có thể viết lại bài toán như sau: hãy cho biết số lượng số \\(x\\) trong khoảng \\([L, R]\\) mà \\(f(x)\\) là số đặc biệt.

Việc tìm các số đặc biệt \\(\le 1458\\) có thể được thực hiện một cách đơn giản.

Ta có \\(3\\) trạng thái QHĐ: \\((idx, smaller, sum)\\) với \\(idx\\), \\(smaller\\) có định nghĩa như các ví dụ trước và \\(sum\\) là tổng bình phương các chữ số đã được điền.

Nếu \\(idx = -1\\), hàm \\(f\\) trả về \\(1\\) nếu \\(sum\\) là một số đặc biệt và \\(0\\) nếu không là số đặc biệt.

Nếu trạng thái của ta đang là \\((idx, smaller, sum)\\), và ta điền \\(a_{idx} = v\\), ta sẽ chuyển trạng thái tiếp theo \\((idx', smaller', sum')\\):

- \\(idx'\\), \\(smaller'\\) giống các ví dụ trước.
- \\(sum' = sum + v^2\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1459;
ll dp[20][N];
int x[20];
vector<int> adj[N];
bitset<N> special;

void dfs(int u);
ll f(int idx, int smaller, int sum);
ll G(ll X);

int main (int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	// tìm các số đặc biệt <= 1458
	for(int i = 1; i < N; ++i){
		int x = i;
		ll sum = 0;
		while(x > 0){
			int digit = x % 10;
			x /= 10;
			sum += digit * digit;
		}
		adj[sum].push_back(i);
	}
	dfs(1);

	int t; cin >> t;
	while(t--){
		ll l, r; cin >> l >> r;
		cout << G(r) - G(l - 1) << '\n';
	}	
	
	return 0;
}
void dfs(int u){
	if(special[u]) return;
	special[u] = 1;
	for(int v : adj[u]) dfs(v);
}

ll f(int idx, int smaller, int sum){
	if(idx < 0) return !special[sum];
	ll &memo = dp[idx][sum];
	if(smaller && memo != -1) return memo;
	int lim = smaller ? 9 : x[idx];
	ll ans = 0;
	for(int i = 0; i <= lim; ++i){
		ans += f(idx - 1, smaller || (i < lim), sum + i * i);
	}

	if(smaller) return memo = ans;
	return ans;
}

ll G(ll X){
	int n = 0; x[n] = 0;
	for(; X > 0; ++n){
		x[n] = X % 10;
		X /= 10;
	}
	return f(n - 1, 0, 0);
}
```

Độ phức tạp của thuật toán này là: \\(O([10 \times n \times (n \times 81)])\\).

### Ví dụ 6: [LUCKY13](https://oj.vnoi.info/problem/lucky13)

Tóm tắt: Cho một hoặc nhiều cặp số nguyên không âm \\(A\\) và \\(B\\), đếm số lượng các số trong khoảng \\([A, B]\\) mà trong dạng biểu diễn không có số \\(13\\).

Giới hạn: \\(0 \le X \le Y \le 10^{15}\\).

Ta có \\(3\\) trạng thái QHĐ: \\((idx, smaller, one)\\) với \\(idx\\), \\(smaller\\) có định nghĩa như các ví dụ trước và \\(one\\) với \\(one = 1\\) nếu số được điền ở vị trí \\(idx + 1\\) bằng \\(1\\) và \\(one = 0\\) trong trường hợp còn lại.

Nếu \\(idx = -1\\), hàm \\(f\\) trả về \\(1\\).

Nếu trạng thái của ta đang là \\((idx, smaller, one)\\), và ta điền \\(a_{idx} = v\\), ta sẽ chuyển trạng thái tiếp theo \\((idx', smaller', one')\\):

- \\(idx'\\), \\(smaller'\\) giống các ví dụ trước.
- \\(one' = 1\\) nếu \\(v = 1\\), \\(one = 0\\) nếu \\(v \neq 1\\).

Đồng thời, nếu \\(one = 1\\) thì ta không được điền \\(a_{idx} = 3\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][20];
int x[20];
ll f(int idx, bool one, bool smaller);
ll G(ll X);
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	ll a, b;
	while(cin >> a >> b){
		cout << G(b) - G(a - 1) << '\n';
	}

	return 0;
}
ll f(int idx, bool one, bool smaller){
	if(idx < 0) return 1;
	ll &memo = dp[one][idx];
	if(smaller && memo != -1) return memo;
	int lim = smaller ? 9 : x[idx];
	ll sum = 0;
	for(int digit = 0; digit <= lim; ++digit){
		if(digit == 3 && one == 1) continue;
		sum += f(idx - 1, digit == 1, smaller || (digit < lim));
	}	
	if(smaller) memo = sum;
	return sum;
}
ll G(ll X){
	if(X < 0) return 0;
	int n = 0; x[n] = 0;
	for(; X > 0; ++n){
		x[n] = X % 10;
		X /= 10;
	}
	return f(n - 1, 0, 0);
}
```

Độ phức tạp của thuật toán này là \\(O(10 \times 2 \times n)\\). 

Ngoài các trạng thái biểu thị đoạn số \\(\overline{a_{n - 1}a_{n - 2}...a_{idx + 1}}\\) quen thuộc như \\(sum\\), ta còn có một số trạng thái phổ biến khác như:

- \\(nonz\\): biểu thị nếu \\(\overline{a_{n - 1}a_{n - 2}...a_{idx + 1}}\\) là các chữ số không vô nghĩa. 
- \\(prevDigit\\): biểu thị giá trị của \\(a_{idx + 1}\\).
- \\(isRising\\): biểu thị nếu \\(a_{n - 1} \le a_{n - 2} \le ... \le a_{idx + 1}\\) đúng hoặc sai.
- \\(isFalling\\): biểu thị nếu \\(a_{n - 1} \ge a_{n - 2} \ge ... \ge a_{idx + 1}\\) đúng hoặc sai.
- \\(s\\): tập hợp các phần tử phân biệt \\(\\{a_{n - 1}, a_{n - 2}, ..., a_{idx + 1}\\}\\).
- ...