# Thuật toán tìm kiếm nhị phân

Bài toán mở đầu: 

> Cho một mảng `a` chứa \\(n\\) phần tử phân biệt được sắp xếp tăng dần. Kiểm tra xem có tồn tại phần tử có giá trị \\(x\\) trong mảng hay không.

Để giải quyết bài toán này, ta có thể duyệt qua tất cả các phần tử và kiểm tra phần tử nào có giá trị bằng \\(x\\), nhưng độ phức tạp thời gian sẽ là \\(O(n)\\). Ta có thể giải được bài toán này một cách tối ưu bằng các sử dụng thuật toán tìm kiếm nhị phân.

## Thuật toán

Ta nhận xét, vì mảng `a` đã được sắp xếp tăng dần, nên phần tử đứng sau luôn lớn hơn phần tử đứng trước.

Giả sử phần tử `a[i]` nhỏ hơn \\(x\\), ta có thể nhận thấy ngay được rằng mọi phần tử đứng sau `a[i]` đều nhỏ hơn \\(x\\).

Khi này, ta có thuật toán nhị phân:
- Tìm giá trị của phần tử ở giữa mảng.
- Xét trường hợp:
	- Nếu phần tử bằng \\(x\\), vậy ta kết luận có phần tử có giá trị bằng \\(x\\). Khi này ta kết thúc tìm kiếm nhị phân. 
	- Nếu phần tử nhỏ hơn \\(x\\), phần tử ấy và mọi phần tử đứng sau nó đều nhỏ hơn \\(x\\). Loại bỏ tất cả phần tử từ đầu mảng đến phần ở giữa ấy. 
	- Nếu phần tử ấy lớn hơn \\(x\\), phần tử ấy và mọi phần tử đứng trước nó đều lớn hơn \\(x\\). Loại bỏ tất cả phần tử từ cuối mảng đến phần tử ấy. 
- Tiếp tục thực hiện tìm kiếm nhị phân cho tới khi không còn phần tử nào để thực hiện việc tìm kiếm, khi này ta thông báo rằng mảng không tồn tại phần tử có giá trị \\(x\\).

```C++
bool tknp(int a[], int n, int x){
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) >> 1; // dịch 1 bit sang phải, tương đương với `(l + r) / 2`
		if(a[mid] == x) return 1;
		else if(a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return -1; // Không tìm thấy x
}
``` 

Vì mỗi lần ta tìm kiếm ta giảm đi một nửa số phần tử trong mảng, nên độ phức tạp thời gian của thuật toán tìm kiếm nhị phân sẽ là \\(O(\log{n})\\).

## Tìm kiếm nhị phân trên hàm đơn điệu

Ta có một hàm \\(f(x)\\) trả về một trong hai giá trị \\(true\\) hoặc \\(false\\). Trong nhiều bài toán, ta được yêu cầu tìm giá trị \\(x\\) lớn nhất hoặc nhỏ nhất sao cho \\(f(x) = true\\). Giống với bài toán tìm phần tử trên mảng, ta cũng có thể giải quyết dạng bài này bằng tìm kiếm nhị phân nếu hàm \\(f(x)\\) là một hàm đơn điệu, tức giá trị của hàm không giảm hoặc không tăng.

### Tìm kiếm giá trị nhỏ nhất

Bài toán yêu cầu tìm một giá trị \\(k\\) mà \\(f(x) = false\\) với \\(x \lt k\\) và \\(f(x) = true\\) với \\(x \ge k\\).

Ta có bảng sau:

|\\(x\\)|\\(0\\)|\\(1\\)|...|\\(k - 1\\)|\\(k\\)|\\(k + 1\\)|...|
|---|---|---|---|---|---|---|---|
|\\(f(x)\\)|\\(false\\)|\\(false\\)|...|\\(false\\)|\\(true\\)|\\(true\\)|...|

Từ đây, ta có thể tìm \\(k\\) bằng tìm kiếm nhị phân:

```C++
int l = -1, r = n;
while(l + 1 < r){
	int mid = (l + r) >> 1; 
	if(f(mid)) r = mid;
	else l = mid;
}
int k = f(r) ? r : -1;
```
### Tìm kiếm giá trị lớn nhất

Bài toán yêu cầu ta tìm một giá trị \\(k\\) mà \\(f(x) = false\\) với \\(x \gt k\\) và \\(f(x) = true\\) với \\(x \le k\\).

Ta cũng tìm \\(k\\) bằng tìm kiếm nhị phân giống như cách ở trên:

```C++
int l = -1, r = n;
while(l + 1 < r){
	int mid = (l + r) >> 1; 
	if(f(mid)) l = mid;
	else r = mid;
}
int k = f(l) ? l : -1;
```

## Tìm kiếm nhị phân đáp án

Ta có dạng bài toán được phát biểu như sau:

> Tất cả các số được chia làm số đẹp và không đẹp. Nếu \\(x\\) là một số đẹp thì \\(x + 1\\) cũng là số đẹp. Tìm số đẹp nhỏ nhất.

Dễ thấy, dạng bài toán này giống với tìm kiếm nhị phân trên hàm đơn điệu được nói ở phần trên. Chính vì thế bài toán này có thể được giải quyết bằng tìm kiếm nhị phân.

Ta sẽ ứng dụng cách giải quyết này cho bài toán sau:

> Cho \\(n\\) hình chữ nhật kích thước \\(a \times b\\). Tính độ dài của hình vuông nhỏ nhất chứa tất cả \\(n\\) hình chữ nhật này.

Ta tạo hàm \\(f(x)\\) trả về \\(true\\) nếu hình vuông cạnh \\(x\\) chứa được tất cả \\(n\\) hình chữ nhật, và \\(false\\) nếu không thể.

Ta biết được \\(f(x)\\) là một hàm đơn điệu vì nếu ta có thể xếp \\(n\\) hình chữ nhật vào hình vuông cạnh \\(x\\) thì ta cũng thực hiện được với hình vuông cạnh \\(x + 1\\).

Ta có số lượng hình chữ nhật \\(a \times b\\) nhiều nhất có thể được xếp trong hình vuông cạnh \\(x\\) là \\(\left\lfloor \frac{x}{a} \right\rfloor \times \left\lfloor \frac{x}{b} \right\rfloor \\) **(người đọc tự chứng minh)**. Từ đây ta có hàm \\(f(x)\\):
- \\(f(x) = 1\\) nếu \\(\left\lfloor \frac{x}{a} \right\rfloor \times \left\lfloor \frac{x}{b} \right\rfloor \le n\\)
- \\(f(x) = 0\\) trong trường hợp ngược lại.

Việc còn lại bây giờ là tìm kiếm nhị phân số \\(x\\) nhỏ nhất mà \\(f(x) = 1\\).

## Tìm kiếm nhị phân với số thực

Với cách thực hiện tìm kiếm nhị phân với số thực thì ta cần có cách áp dụng thuật toán theo cách khác. Số thực khó so sánh bằng, như đã nói ở phần [số thực](../programming/data-types.md#số-thực), nếu sử dụng kiểu `while (l <= r)`, vòng lặp sẽ chạy vô tận và chương trình sẽ bị TLE.

Để thực hiện việc tìm kiếm nhị phân với số thực, ta chỉnh sửa code như sau:

```C++
double l = 0, r = 1e9f;

for(int i = 1; i <= [iteration_count]; ++i){
	double mid = 0.5f * (l + r);
	if(f(mid)) l = mid;
	else r = mid;
}
```

Thay đổi `[iterator_count]` để tạo sự cân bằng giữa độ chính xác kết quả và tốc độ thuật toán. Thường thì ta sẽ chọn `100` cho `[iterator_count]`.

## Hàm tìm kiếm nhị phân trong C++

C++ có các hàm dựa trên tìm kiếm nhị phân:

- Hàm `lower_bound` trả về vị trí phần tử đầu tiên có giá trị lớn hơn hoặc bằng \\(x\\)
- Hàm `upper_bound` trả về vị trí phần tử đầu tiên có giá trị lớn hơn \\(x\\)
- Hàm `equal_range` trả về \\(2\\) vị trí `lower_bound` và `upper_bound`

```C++
auto idx = lower_bound(a, a + n, x) - a;
if(idx < n && a[idx] == x){
	// phần tử có giá trị x ở chỉ số k
}
```

Code dưới đây đếm số phần tử có giá trị bằng \\(x\\).

```C++
auto l = lower_bound(a, a + n, x) - a;
auto u = upper_bound(a, a + n, x) - a;
cout << u - l;
```

Có thể được rút gọn bằng `equal_range`:

```C++
auto lu = equal_range(a, a + n, x);
cout << lu.second - lu.first;
```

Ta cũng có hàm `binary_search` kiểm tra nếu giá trị \\(x\\) tồn tại trong mảng `a` hay không.

```C++
cout << binary_search(a, a + n, x); // Trả về 1 nếu x có trong a và 0 nếu ngược lại
```

**Bonus**: [BINARY search with FLAMENCO dance](https://www.youtube.com/watch?v=iP897Z5Nerk)