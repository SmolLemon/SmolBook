# Duyệt toàn bộ

**Duyệt toàn bộ (Complete search)**, hay với các tên gọi khác như *duyệt trâu*, *vét cạn*, *brute force*, là một mô hình thuật toán. Các thuật toán duyệt toàn bộ sẽ giải quyết bài toán bằng cách kiểm tra (gần như) toàn bộ không gian tìm kiếm của bài để tìm kiếm kết quả thỏa mãn, ví dụ như kiểm tra các phần tử, các cặp giá trị, các tập con, hoán vị, v.v. 

Ưu điểm của duyệt toàn bộ là luôn đảm bảo tìm ra nghiệm đúng, chính xác. Tuy nhiên, thời gian thực thi lại lâu, độ phức tạp lớn. 

Trong các cuộc thi lập trình, các thí sinh có xem xét việc cài đặt thuật toán theo mô hình duyệt toàn bộ khi không thể tìm ra thuật toán khác tốt hơn. Bằng cách này, thí sinh có thể giành điểm ở những subtask đầu tiên - các subtask dễ và có thể giải được bằng duyệt toàn bộ (nếu có). Ngoài ra, thí sinh cũng có thể cài đặt thuật toán duyệt toàn bộ kể cả khi tồn tại thuật toán tối ưu hơn nếu giới hạn của bài toán đủ nhỏ.

Đôi khi, việc chạy thuật toán duyệt toàn bộ trên một số test nhỏ có thể giúp ta hiểu được bản chất của bài toán dễ dàng hơn, giúp tăng khả năng tìm được thuật toán chuẩn của bài.

## Sinh tập con

Ta xem xét các bài toán yêu cầu ta sinh ra tất cả các tập con của danh sách \\(n\\) phần tử. Ví dụ với danh sách \\(3\\) phần tử thì ta sẽ có các tập con chứa chỉ số của các phần tử (bắt đầu tử chỉ số 0): 
\\[\emptyset, \\{0\\}, \\{1\\}, \\{2\\}, \\{0, 1\\}, \\{0, 2\\}, \\{1, 2\\}, \\{0, 1, 2\\}\\].

Ta có thể sử dụng đệ quy để sinh các tập con.

```C++
vector<int> subset;

void search(int idx) {
	if (idx == n) {
		// Xét tập con
		return;
	}

	// Phần tử idx có trong tập con
	subset.push_back(idx);
	search(idx + 1);
	
	// Phần tử idx không có trong tập con
	subset.pop_back();
	search(idx + 1);
}
```

Ta có thể sử dụng [bitmask](../basic/bit-manipulation.md#bitmask-mảng-bit) để xét các tập con.

Ví dụ: \\(5_{10} = 101_2\\) biểu thị tập hợp \\(\\{0, 2\\}\\). 

Ta duyệt các số từ \\(0\\) đến \\(2^n - 1\\), tương đương với duyệt các tập con của tập hợp \\(n\\) phần tử

```C++
for(int s = 0; s < (1 << n); ++s){
	vector<int> subset;
	for(int j = 0; j < n; ++j){
		if((i >> j) & 1){
			subset.push_back(j);
		}
	}
	// Xét tập con
}
```

Ta cũng có thể sử dụng [cách duyệt khác](../basic/bit-manipulation.md#duyệt-các-tập-con-của-bitmask) với khả năng tương tự.

```C++
int mask = (1 << n) - 1;
for(int s = mask; ; s = (s - 1) & mask){
	vector<int> subset;
	for(int j = 0; j < n; ++j){
		if((i >> j) & 1){
			subset.push_back(j);
		}
	}
	// Xét tập con
	if(s == 0) break;
}
```

Có nhiều nhất \\(n\\) phần tử cho mỗi tập con nên độ phức tạp khi sinh và xét các tập con sẽ là \\(O(2^n \times n)\\). Nếu ta có thể vừa xét vừa duyệt các tập con đối với phương thức đệ quy thì có thể giảm xuống thành \\(O(2^n)\\).

## Sinh hoán vị

Ta xem xét các bài toán yêu cầu ta sinh ra tất cả các hoán vị của danh sách \\(n\\) phần tử. Ví dụ với danh sách \\(3\\) phần tử thì ta sẽ có các hoán vị chứa chỉ số của các phần tử (bắt đầu tử chỉ số 0): 

\\[\\{0, 1, 2\\}, \\{0, 2, 1\\}, \\{1, 0, 2\\}, \\{1, 2, 0\\}, \\{2, 0, 1\\}, \\{2, 1, 0\\}\\].

Ta có thể sử dụng đệ quy:

```C++
vector<int> permutation;
bitset<N> chosen;

void search() {
	if (permutation.size() == n) {
		// Xét hoán vị
		return;
	} 
	for (int i = 0; i < n; ++i) {
		if (chosen[i]) continue;
		chosen[i] = true;
		permutation.push_back(i);
		search();
		chosen[i] = false;
		permutation.pop_back();
	}
}
```

hoặc có thể sử dụng hàm `next_permutaion` để xét các hoán vị.

```C++
vector<int> permutation(n, 0);
// Gán các số từ 0 đến n - 1
iota(permutation.begin(), permutation.end(), 0);
do{
	// Xét hoán vị
}while(next_permutaion(permutation.begin(), permutation.end()));
```

Có \\(n\\) phần tử cho mỗi hoán vị nên độ phức tạp cho cả hai cách là \\(O(n! \times n)\\).

## Quay lui


### Bài toán 8 quân hậu


## Chia đôi tập