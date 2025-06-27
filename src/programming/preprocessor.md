# Bộ tiền xử lí

**Bộ tiền xử lí (preprocessor)** là những chỉ thị để trình biên dịch tiền xử lí các đoạn trong chương trình trước khi bắt đầu biên dịch thực sự. Ta đã được thấy một bộ tiền xử lí `#define` ở các đoạn code trước, thêm các đoạn code từ những file khác vào chương trình của ta.

Ta sẽ tập trung vào việc sử dụng `#define`. Đây là một bộ tiền xử lí thay thế các biểu tượng trong code thành các biểu tượng khác.

Việc khai báo một `define` được viết như sau:

```C++
#define biểu_tượng_cần_thay_thế biểu_tượng_thay_thế
```

Ví dụ, giả sử ta sử dụng `#define` thay thế `ll` thành `long long`

```C++
#define ll long long
```

Thì đoạn code 

```C++
ll a = 5;
```

sẽ được trình biên dịch thay thế thành:

```C++
long long a = 5;
```

Ta gọi các `#define` này là **macro**.

Có hai dạng macro chính: macro *object-like* và macro *function-like*.

Các macro object-like đơn giản chỉ thay đổi các biểu tượng, trong khi các macro function-like sẽ nhìn và cư xử giống như một hàm.

```C++
// macro object-like
#define ll long long
#define PI 3.1415926

// macro function-like
#define SQRT(a) ((a)*(a))
#define rep(i, a, b) for(int i = a; i <= b; ++i)
``` 

## Template

Trong các bài nộp, ta sẽ bắt gặp các *template*, chứa các macro, một số hàm được viết sẵn mà các hằng số được định nghĩa trước. Việc có những template sẽ giúp ta viết các chương trình một cách ngắn gọn hơn.

Dưới đây là template của một bài nộp ngẫu nhiên trên VNOJ.

```C++
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define plli pair<ll, int>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define bit(mask, i) ((mask >> i) & 1)
#define fi first
#define se second
#define FILE freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define mod 1000000007

using namespace std;

using ll = long long;
using str = string;
```

Tác giả không khuyến khích việc lạm dụng template trong các chương trình bởi các đoạn của ta sẽ trở nên khó đọc hơn và những người khác sẽ gặp khó khăn khi đọc đoạn code ấy.

Trong các phần sau, các đoạn code sẽ chỉ áp dụng một template duy nhất: `#define ll long long`