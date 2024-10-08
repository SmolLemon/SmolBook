# Thuật toán sắp xếp

Thuật toán sắp xếp là thuật toán tối quan trọng trong lập trình thi đấu. Thuật toán sắp xếp là nền tảng để tối ưu các thuật toán khác, khi việc thực hiện các thao tác sẽ dễ dàng hơn khi các phần tử của một danh sách đã được sắp xếp.

## Khái niệm

Một bài toán sắp xếp kinh điển sẽ được phát biểu như sau:

> Cho một mảng chứa \\(n\\) phần tử. Hãy sắp xếp và trả về các phần tử của mảng theo thứ tự tăng dần theo giá trị.

Ví dụ ta có mảng:

\\[[2, 5, 7, 9, 1, 4, 6, 3, 8]\\] 

Thì sau khi sắp xếp ta có mảng mới

\\[[1, 2, 3, 4, 5, 6, 7, 8, 9]\\]

## Các thuật toán sắp xếp \\(O(n^{2})\\)

Các thuật toán sắp xếp \\(O(n^{2})\\) thường khá đơn giản - thường khá ngắn và sử dụng 2 vòng lặp lồng nhau. Ta sẽ tìm hiểu một số thuật toán sắp xếp \\(O(n^{2})\\) phổ biến.

### Sắp xếp nổi bọt (Bubble sort)

Thuật toán sắp xếp nổi bọt hoạt động như sau: Ta xét cặp 2 phần tử liên tiếp. Nếu phần tử đứng trước lớn hơn phần tử đứng sau, hoán đổi vị trí 2 phần tử. 

Lặp lại cho đến khi nào không còn cặp phần tử nào có thể hoán đổi vị trí.

```C++
for(int i = 1; i <= n; ++i){
	for(int j = 1; j < n; ++j){
		if(a[j] > a[j + 1]){
			swap(a[j], a[j + 1]);
		}
	}
}
```

Minh họa bằng video: [Bubble-sort with Hungarian ("Csángó") folk dance](https://www.youtube.com/watch?v=lyZQPjUT5B4)

### Sắp xếp chọn (Selection sort)

thuật toán sắp xếp chọn hoạt động như sau: với mỗi vị trí `i` từ 1 đến \\(n\\), ta sẽ tìm số nhỏ nhất từ vị trí `i` đến vị trí `n` và hoán đổi phần tử ở vị trí `i` với phần tử ở vị trí số nhỏ nhất ấy.

Khi này, với mỗi lần hoàn tất duyệt phần tử thứ `i`, ta có `i` phần tử nhỏ nhất đã được sắp xếp tăng dần.

```C++
for(int i = 1; i < n; ++i){
	int id = i;
	for(int j = i; j <= n; ++j){
		if(a[id] > a[j]){
			id = j;
		}
	}
	swap(a[i], a[id]);
}
```

Minh họa bằng video: [Select-sort with Gypsy folk dance](https://www.youtube.com/watch?v=Ns4TPTC8whw)

### Sắp xếp chèn (Insertion sort)

Thuật toán sắp xếp chèn sẽ lần lượt sắp xếp 1 phần tử đầu tiên, sau đó là 2 phần tử, 3 phần tử, ..., cho tới khi toàn bộ \\(n\\) phần tử đã được sắp xếp.

Với mỗi phần tử có chỉ số `i` từ 2 đến \\(n\\), ta tìm chỉ số của phần tử lớn nhất không lớn hơn phần tử có chỉ số `i`, gọi là `j`. Sau đó, chèn phần tử có chỉ số `i` vào vị trí `j` trong mảng.

```C++
for(int i = 2; i <= n; ++i){
	int j = i;
	while(j >= 2 && a[j] > a[j - 1]) {
		swap(a[j], a[j - 1]);
		--j;
	}
}
```

Minh họa bằng video: [Insert-sort with Romanian folk dance](https://www.youtube.com/watch?v=ROalU379l3U)

## Các thuật toán sắp xếp \\(O(n \log{n})\\)

Thuật toán sắp xếp có thể được tối ưu xuống còn \\(O(n \log{n})\\). Ta sẽ tìm hiểu một số thuật toán sắp xếp phổ biến.

### Sắp xếp trộn (Merge sort)

Thuật toán sắp xếp trộn (Merge sort) là cách sắp xếp sử dụng kĩ thuật [chia để trị](../algo-paradigm/d&c.md).

Mô tả thuật toán:

- Nếu kích cỡ mảng là 1, kết thúc sắp xếp.
- Nếu kích cỡ lớn hơn 1:
  - Chia đôi mảng thành 2 mảng con có kích thước \\(\left\lfloor \frac{n}{2} \right\rfloor \\) và \\(\left\lceil \frac{n}{2} \right\rceil \\)
  - Sắp xếp 2 mảng con cách đệ quy bằng merge sort
  - Hợp 2 mảng con lại thành một mảng đã sắp xếp

Độ phức tạp của thuật toán là \\(O(n \log{n})\\).

```C++
int arr[N];
int tmp[N];
void mergesort(int l, int r){
	if(l >= r) return;

	int k = (l + r) >> 1;
	mergesort(l, k); 
	mergesort(k + 1, r);
	int i = l, j = k + 1;
	int id = 1;
	while(i <= k && j <= r){
		if(arr[i] < arr[j]){
			tmp[id] = arr[i];
			++i;
		}else {
			tmp[id] = arr[j];
			++j;
		}
		++id;
	} 
	while(i <= k){
		tmp[id] = arr[i];
		++i; ++id;
	}
	while(j <= r){
		tmp[id] = arr[j];
		++j; ++id;
	}
	for(int idx = l; idx <= r; ++idx){
		arr[idx] = tmp[idx - l + 1];
	}
}
```

Minh hoạ bằng ảnh:

![Merge Sort](../images/merge_sort.svg)

Minh họa bằng video: [Merge-sort with Transylvanian-saxon (German) folk dance](https://www.youtube.com/watch?v=XaqR3G_NVoo)

### Sắp xếp nhanh (QuickSort)

Thuật toán sắp xếp nhanh là một thuật toán sử dụng kĩ thuật chia để trị. Mặc dù độ phức tạp của thuật toán chậm nhất là \\(O(n^{2})\\) thuật toán lại có độ phức tạp trung bình là \\(O(n \log{n})\\), và khi so sánh trên máy thì nhanh hơn sắp xếp trộn trong nhiều trường hợp.

Mô tả thuật toán:

- Nếu kích cỡ mảng là 1, kết thúc sắp xếp.
- Nếu kích cỡ lớn hơn 1:
  - Chọn một phần tử bất kì trong mảng 
  - Chia mảng ra thành 2 mảng con: Một mảng con chứa các số nhỏ hơn phần tử bất kì kia, một mảng con chứa các số còn lại
  - Sắp xếp 2 mảng con một cách đệ quy bằng quicksort
  - Hợp 2 con mảng con lại thành một mảng đã sắp xếp

```C++
int a[N];
void quickSort(int l, int r) {
	if(l >= r) return;
    int i = l, j = r;
    int pivot = a[(l + r) >> 1]; // chọn phần tử ở chính giữa mảng 
    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    if (l < j) quickSort(l, j);
    if (i < r) quickSort(i, r);
}
```

Minh họa bằng video: [Quick-sort with Hungarian (Küküllőmenti legényes) folk dance](https://www.youtube.com/watch?v=ywWBy6J5gz8)

## Thuật toán sắp xếp nhỏ hơn \\(O(n \log {n})\\)?

Đến đây, ta tự hỏi rằng liệu có thuật toán sắp xếp nào có độ phức tạp còn nhỏ hơn \\(O(n \log {n})\\) không? Nếu như ta giới hạn ở việc so sánh giá trị giữa các phần tử thì điều này là không thể.

Một mảng chứa \\(n\\) phần tử sẽ có tất cả \\(n!\\) cách sắp xếp. Với mỗi lần thực hiện một bước so sánh, số lượng cách sắp xếp giảm đi một nửa, suy ra số bước so sánh cần thực hiện để mảng được sắp xếp tăng dần sẽ là \\(O(\log{n!})\\).

Sử dụng [công thức Stirling](https://vi.wikipedia.org/wiki/X%E1%BA%A5p_x%E1%BB%89_Stirling), ta có: \\(\log{n!} = n \log{n} - n + O(\log{n})\\). Suy ra: \\(O(\log{n!}) = O(n\log{n})\\).

### Sắp xếp đếm (Counting sort)

Giới hạn \\(O(n\log{n})\\) ở trên sẽ chỉ áp dụng với các thuật toán so sánh các giá trị của phần tử. Nếu ta sử dụng phương pháp khác, độ phức tạp có thể thay đổi.

Một trong những thuật toán sắp xếp ấy chính là sắp xếp đếm.

Thuật toán sắp xếp đếm là một thuật toán sắp xếp nhanh các phần tử trong mảng, với các phần tử trong mảng là các số nguyên. Thuật toán sẽ đếm số lần xuất hiện của các giá trị có trong mảng, từ đấy sắp xếp lại các giá trị.

Độ phức tạp của thuật toán sắp xếp này là \\(O(n + k)\\), với \\(k\\) là khoảng giá trị của các phần tử trong mảng. Dễ thấy, nếu \\(k\\) đủ nhỏ, độ phức tạp của sắp xếp nhanh sẽ hơn nhiều so với các thuật toán sắp xếp được nói ở trên. 

## Thuật toán sắp xếp trong C++

Việc tự tay viết cả một thuật toán sắp xếp rất tốn thời gian và rất dễ xảy ra sai sót. Vì vậy ta có thể dùng hàm `sort` có sẵn trong thư viện C++. Điều này không những giúp tiết kiệm thời gian viết mà còn giúp tối ưu chương trình khi những hàm trong thư viện C++ thường rất nhanh và hiệu quả.

Hàm sort của C++ sẽ sắp xếp các số trong khoảng \\([l, r)\\).

VD: sắp xếp các phần tử trong mảng `a` từ vị trí 0 đến `n - 1`.
```C++
sort(a, a + n);
```

Hàm sort cũng có thể sắp xếp được `string`, với các kí tự được sắp xếp theo giá trị ASCII tương ứng:

```C++
string s = "sorting";
sort(s.begin(), s.end());
cout << s; // 'ginorst'
```

### Phép so sánh trong hàm sort C++

Hàm `sort` trong C++ yêu cầu một thao tác so sánh để có thể thực hiện việc so sánh các phần tử. Hầu hết các kiểu dữ liệu trong C++ đều có phép so sánh, ví dụ như `int` sắp xếp theo giá trị của nó. 

Kiểu dữ liệu `pair` sẽ được sắp xếp theo giá trị của giá trị đầu tiên trong cặp giá trị: `first`. Nếu có nhiều `first` bằng nhau thì sẽ sắp xếp theo giá trị còn lại của pair: `second`.

```C++
vector<pair<int, int>> v;
v.push_back({1, 5});
v.push_back({2, 3});
v.push_back({1, 2});
sort(v.begin(), v.end());
```

Sau khi sắp xếp xong mảng `v` sẽ có các phần tử được xắp xếp theo thứ tự lần lượt là `(1, 2)`, `(1, 5)`, `(2, 3)`.

### Struct

`struct` trong C++ mặc định không có thao tác so sánh. Vì vậy ta phải tự viết thao tác với mỗi `struct` mà ta muốn thực hiện việc sắp xếp bằng hàm `sort`.

Ví dụ:

```C++
struct phanso {
	int x, y;
	bool operator<(const phanso &p) const{
		return x * p.y < p.x * y;
	}
};
```
`struct` `phanso` ở ví dự trên có thao tác so sánh theo giá trị của `a / b`:

### Hàm so sánh

Ta có thể viết hàm so sánh để sắp xếp các phần tử:

Ví dụ:

```C++
bool cmp(const phanso &a, const phanso &b){
	return a.x * b.y < a.x * b.y;
}

int main(){
	vector<phanso> a = {{1, 2}, {2, 3}, {4, 2}};
	sort(a.begin(), a.end(), cmp);
}
```

Mảng `a` sau khi sắp xếp xong sẽ cho ta các phần tử theo thứ tự: `(1, 2)`, `(2, 3)`, `(4, 2)`.
