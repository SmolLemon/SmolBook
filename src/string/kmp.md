# Thuật toán Knuth-Morris-Pratt (KMP)

**Thuật toán Knuth-Morris-Pratt** hay **thuật toán KMP** là một thuật toán giải quyết bài toán so khớp chuỗi. 

Khác với [thuật toán băm xâu](string-hashing.md), có khả năng cho ra kết quả sai do [va chạm băm](string-hashing.md#hạn-chế-va-chạm-băm), thuật toán KMP không gặp vấn đề này.

## Thuật toán

Thuật toán KMP tìm sự xuất hiện của xâu \\(S\\) trong xâu \\(T\\) bằng cách tạo một bảng dựa trên thông tin của mảng \\(S\\), sau đó sử dụng bảng để tìm kiếm xâu \\(S\\) một cách hiệu quả.

### Bảng tiền tố

Ta có hàm \\(\pi(S)\\) là một **hàm tiền tố**. Hàm tiền tố này sẽ trả về xâu con dài nhất vừa là **tiền tố**, vừa là **hậu tố** của xâu \\(S\\), đồng thời phải khác xâu \\(S\\). Xâu mà hàm này trả về được gọi là **xâu tiền tố chuẩn (proper prefix)**.

Ví dụ, ta có \\(\pi(\underline{aba}ab\underline{aba}) = abc\\), \\(\pi(\underline{a}b\underline{a}) = a\\), \\(\pi(a) = \emptyset\\), \\(pi(\emptyset) = \text{NULL}\\).

Từ đây, ta xây dựng bảng tiền tố \\(p\\) chứa \\(|S|\\) phần tử và bắt đầu từ chỉ số \\(0\\), phần tử có chỉ số \\(i\\) sẽ lưu xâu \\(\pi(S[0..i])\\).

Nhiệm vụ cần làm ngay lúc này chính là làm sao để tính bảng tiền tố một cách hiệu quả.

Giả sử ta có \\(\pi(S[0..(i-1)]) = X\\). Để tính được xâu \\(\pi(S[0..i])\\), ta so sánh hai xâu \\(X+S_{|X|}\\) và \\(X+S_{i}\\). 
- Nếu \\(X+S_{|X|} = X+S_{i}\\), ta tính được \\(\pi(S[0..i])\\) bằng xâu \\(XS_{i}\\). 
- Nếu \\(X+S_{|X|} \neq X+S_{i}\\), ta cập nhật \\(X = \pi(X)\\) và quay lại việc so sánh hai xâu như ở trên. Nếu \\(\pi(X) = \text{NULL}\\) thì \\(\pi(S[0..i]) = \emptyset\\).

Để tối ưu thuật toán, ta chỉ cần lưu độ dài của xâu \\(\pi(S[0..i])\\).

```C++
vector<int> pi(const string &s) {
	int n = s.length();
	vector<int> p(n, 0);
	for(int i = 1, j = 0; i < n; ++i){
		while(s[i] != s[j] && j > 0) j = p[j - 1]; // Cập nhật xâu X thành pi(X) 
		if(s[i] == s[j]) p[i] = ++j;
		else p[i] = 0;
	}
	return p;
}
```

Độ phức tạp của việc xây dựng bảng tiền tố là \\(O(|S|)\\).

### Tìm kiếm xâu

Sau khi đã xâu dựng xong bảng tiền tố trên xâu \\(S\\), ta có thể tìm những vị trí xuất hiện của xâu này trên xâu \\(T\\).

Cách dễ nhất để thực hiện điều này là xây dựng bảng tiền số của xâu lớn gồm xâu \\(S\\) ở bên trái, xâu \\(T\\) ở bên phải và một kí tự đặc biệt không xuất hiện trong cả hai xâu nằm ở giữa (ví dụ như \\(X = S+\text{#}+T\\)). Sau đó, ta tìm các vị trí \\(i\\) thoả mãn \\(\pi(X[0..i]) = S\\).

```C++
vector<int> kmp(string &s, string &t) {
	vector<int> p = pi(s + '#' + t);
	int n = t.size();
	int m = s.size();
	vector<int> idx;
	for(int i = (int)p.size() - n; i < (int)p.size(); ++i){

		// vị trí của kí tự đầu tiên của xâu S trên xâu T
		if(p[i] == m) idx.emplace_back(i - m * 2);
	}
	return idx;
}
```

Một cách khác nữa đó là xây dựng bảng tiền tố của xâu \\(S\\). Sau đó, ta duyệt xâu \\(T\\) gần giống như lúc ta xây dựng bảng tiền tố. Cụ thể hơn, ta xem cách cài đặt dưới đây.

```C++
vector<int> kmp(string &s, string &t) {
	vector<int> p = pi(s);
	int n = t.size();
	int m = s.size();
	vector<int> idx;
	for(int i = 0, j = 0; i < n; ++i){
		while(t[i] != s[j] && j > 0) j = p[j - 1];
		if(t[i] == s[j]) ++j;

		if(j == m) idx.emplace_back(i - m + 1), j = p[j - 1]; 
	}
	return idx;
}
```

Độ phức tạp của việc tìm kiếm xâu của cả hai cách đều là \\(O(|S| + |T|)\\).