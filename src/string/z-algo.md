# Thuật toán Z

**Thuật toán Z** là một thuật toán xử lí xâu. Một trong những ứng dụng phổ biến của thuật toán Z là để giải quyết bài toán so khớp chuỗi.

```C++
vector<int> zArray(const string &s) {
	int n = s.size();
	vector<int> z(n, 0);
	for(int i = 1, l = -1, r = -1; i < n; ++i) {
		if(i < r) z[i] = min(r - i, z[i - l]);
		
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

		if(i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}
```

Độ phức tạp thuật toán là \\(O(|S|)\\).

Để sử dụng thuật toán Z nhằm giải quyết bài toán so khớp chuỗi, ta xây dựng mảng Z trên xâu lớn giống như ở thuật toán [KMP](kmp.md#tìm-kiếm-xâu), sau đó tìm các vị trí \\(i\\) thoả mãn \\(z_i = |S|\\).

```C++
vector<int> stringMatching(string &s, string &t){
	int n = s.size(), m = t.size();
	vector<int> z = zArray(s + '#' + t);
	vector<int> idx;
	for(int i = 0; i < (int)z.size(); ++i) {
		if(z[i] == n) idx.emplace_back(i - n - 1);
	}
	return idx;
}
```