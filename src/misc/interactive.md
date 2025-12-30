# Bài toán tương tác với máy chấm

**Bài toán tương tác với máy chấm (gọi tắt là bài toán tương tác)** là các bài toán yêu cầu ta phải tìm đáp án bằng cách "hỏi" máy chấm các câu hỏi và máy chấm sẽ "trả lời" những câu hỏi của ta. Ta cần "hỏi" với số lượng được giới hạn cho tới khi ta tìm được đáp án.

Bài toán tương tác rất giống với trò chơi [Akinator](https://vi.akinator.com/) vậy: ta, người chơi, sẽ chọn cho mình một nhân vật có thật hoặc hư cấu. Sau đó, Akinator sẽ cho ta các câu hỏi và ta cần phản hồi với Akinator bằng các câu trả lời như "có", "không", "không biết", "có thể" hoặc "có thể là không". Dựa vào các câu trả lời, Akinator sẽ cho ta biết được nhân vật mà ta chọn là ai. Bài toán tương tác cũng tương tự, tuy nhiên điểm khác biệt nằm ở chỗ ta sẽ đóng vai trò là một Akinator, còn máy chấm sẽ là người chơi, quyết định đáp án là gì.

Các bài toán này thường xuất hiện trên các cuộc thi lập trình như ICPC hoặc các cuộc thi online. 

> [!IMPORTANT]
>
> Một số lưu ý khi làm bài toán tương tác:
> 
> - Việc nhập xuất đối với các chương trình tương tác sẽ chậm hơn các chương trình thông thường.
> - Việc kiểm tra chương trình tương tác sẽ khó khăn hơn vì ta phải đóng vai trò của máy chấm.
> - Ta vẫn có thể giữ [Fast I/O](../programming/io.md#fast-io) trong chương trình tương tác. Ta chỉ cần nhớ `flush` dữ liệu xuất trong mỗi lần in ra hoặc sử dụng `endl`.

## Bài toán ví dụ

Ta có bài toán ví dụ sau: bạn Lan đã chọn một số nằm trong khoảng \\([1, 1\space 000\space 000]\\). Bạn chỉ được phép hỏi \\(25\\) câu hỏi đoán một số \\(x\\). Bạn Lan sẽ trả lời bạn nếu số \\(x\\) lớn hơn hoặc bằng số bạn Lan đã chọn hay không. Tìm số mà bạn Lan đã chọn.

Đối với chương trình tương tác của ta, các câu hỏi sẽ ở dạng `? x`. Khi tìm được số cần tìm, ta in ra `! x`.

Đối với máy chấm, nếu số \\(x\\) lớn hơn hoặc bằng số bạn Lan đã chọn, chương trình sẽ trả về `1`, nếu không thì chương trình sẽ trả về `0`.

Việc đoán bừa \\(25\\) trên \\(1\\) triệu số sẽ ít có khả năng đúng. Tuy nhiên, nếu nhìn vào câu trả lời của bạn Lan, ta có thể thực hiện thực hiện [tìm kiếm nhị phân đáp án](../basic/binary-search.md#tìm-kiếm-nhị-phân-đáp-án). gọi \\(f(x)\\) là một hàm trả về \\(1\\) nếu số \\(x\\) lớn hơn hoặc bằng số bạn Lan và \\(0\\) nếu ngược lại. Ta cần tìm số \\(x\\) nhỏ nhất sao cho \\(f(x) = 1\\).

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ask(int x);
void ans(int x);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l = 1, r = 1'000'000;
	while(l != r) {
		int mid = (l + r + 1) >> 1;
		if(ask(mid) == 1) l = mid;
		else r = mid - 1;
	}
	ans(l);
	
	
	return 0;
}

int ask(int x) {
	cout << "? " << x << endl;
	int g; cin >> g;
	return g;
}

void ans(int x){
	cout << "! " << x << endl;
}
```

Độ phức tạp thuật toán bằng \\(O(\log_2{10^6}) = O(1)\\). Với độ phức tạp này, ta có thể đảm bảo thuật toán sẽ chỉ cần hỏi không quá \\(25\\) câu.