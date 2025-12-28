# Các bài toán kinh điển

Các bài toán kinh điển về xâu là các bài toán khá đơn giản về ý tưởng mà ta cần phải biết. 

Ta sẽ chỉ tập trung vào các bài toán xử lí xâu bằng [QHĐ](../paradigms/dp.md) hoặc các CTDL, thuật toán mà ta đã học ở các chương trước. Các bài toán như so khớp chuỗi và tìm các xâu con đối xứng sẽ nằm ở các phần sau. 

## Xâu con chung dài nhất

Bài toán tìm **xâu con chung dài nhất (longest common subsequence)** của hai xâu \\(S\\) và \\(T\\) yêu cầu ta xoá các kí tự bất kì của hai xâu sao cho các kí tự còn lại của hai xâu bằng nhau và chiều dài của xâu là lớn nhất. Có thể không xoá kí tự nào.

Ta có \\(lcs(i, j)\\) là độ dài xâu con chung dài nhất tạo thành từ \\(i\\) kí tự đầu tiên của \\(S\\) và \\(j\\) kí tự đầu tiên của \\(T\\). Dễ thấy, các trường hợp cơ cở của hàm \\(lcs\\) là \\(lcs(0, j) = 0\\) và \\(lcs(i, 0) = 0\\). Các trường hợp này là khi không có kí tự nào từ \\(S\\) hoặc \\(T\\) thì xâu con chung dài nhất sẽ là xâu rỗng.

Giả sử kí tự thứ \\(i\\) của \\(S\\) bằng kí tự thứ \\(j\\) của \\(T\\), hay \\(S_{i-1} = T_{j-1}\\), Vì bằng nhau, nên ta có thể **thêm** kí tự này vào cuối xâu con chung dài nhất của ta, kéo dài độ dài của nó lên \\(1\\). Từ đó ta có: \\[lcs(i, j) = lcs(i-1, j-1) + 1\\]

Trường hợp còn lại là \\(S_{i-1}\\) với \\(T_{j-1}\\) không bằng nhau. Khi này, ta chỉ có thể thêm \\(S_{i-1}\\) hoặc \\(T_{j-1}\\) là kí tự cuối cùng của xâu con chung dài nhất, tương đương với xâu con chung của \\(lcs(i - 1, j)\\) và \\(lcs(i, j - 1)\\). Vì ta cần tìm xâu con chung dài nhất nên ta cần tìm giá trị lớn nhất của một trong hai xâu. Từ đó ta có: \\[lcs(i, j) = max(lcs(i-1, j), lcs(i, j-1))\\]

```C++
int LCS(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 0; i <= n; ++i) dp[i][0] = 0;
	for(int i = 0; i <= m; ++i) dp[0][i] = 0;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[n][m];
}
```

Độ phức tạp của thuật toán là \\(O(|S||T|)\\) với \\(|S|, |T|\\) lần lượt là độ dài của hai xâu \\(S\\) và \\(T\\).

### Xâu con đối xứng chung dài nhất

Bài toán **xâu con đối xứng chung dài nhất (longest palindromic subsequence)** yêu cầu ta xoá các kí tự của một xâu \\(S\\) sao cho sau khi xoá, các kí tự hình thành nên xâu đối xứng và độ dài của nó là lớn nhất.

Ta có thể giải quyết bài toán bằng cách tìm xâu con chung dài nhất của xâu \\(S\\) và xâu đảo ngược của nó.

```C++
int LPS(string s) {
	string t = s;
	reverse(t.begin(), t.end()); // đảo ngược xâu
	return LCS(s, t);
}
```

Độ phức tạp thuật toán tương tự với bài toán xâu con chung dài nhất: \\(O(|S||T|)\\).

## Biến đổi xâu

Bài toán **biến đổi xâu (edit distance)** là bài toán đếm số thao tác nhỏ nhất để biến đổi một xâu \\(S\\) thành xâu \\(T\\). Các thao tác bao gồm:
- **Xoá**: xoá một kí tự trong xâu \\(S\\) (`AB` \\(\rightarrow\\) `A`).
- **Thêm**: thêm một kí tự trong xâu \\(S\\) (`AB` \\(\rightarrow\\) `ABC`).
- **Chỉnh sửa**: chỉnh sửa một kí tự trong xâu \\(S\\) thành một kí tự khác (`AB` \\(\rightarrow\\) `AC`).

Ví dụ, để biến đổi xâu `LOVE` thành `MOVIE`, ta cần tối thiểu **\\(2\\)** thao tác: (1) chỉnh sửa kí tự `L` thành `M`; (2) thêm kí tự `I` vào giữa hai kí tự `V` và `E`.

Giá trị mà bài toán này tìm được cũng là giá trị **khoảng cách Levenshtein (Levenshtein distance)** của hai xâu.

Ta có \\(lev(i, j)\\) là số thao tác tối thiểu để biến đổi \\(i\\) kí tự đầu tiên của \\(S\\) thành \\(j\\) kí tự đầu tiên của \\(T\\). 

Các trường hợp cơ cở của \\(lev\\) là \\(lev(0, j) = j\\). Đây là bởi để biến đổi xâu rỗng thành \\(j\\) kí tự đầu tiên của \\(T\\), ta sẽ thêm \\(j\\) kí tự y hệt \\(j\\) kí tự đầu tiên của \\(T\\). Với lập luận tương tự, ta có \\(lev(i, 0) = i\\).

Giả sử kí tự thứ \\(i\\) của \\(S\\) bằng kí tự thứ \\(j\\) của \\(T\\), hay \\(S_{i-1} = T_{j-1}\\), Vì bằng nhau nên ta không cần thực hiện chỉnh sửa. Khi này ta có: \\[lev(i, j) = lev(i-1, j-1)\\]

Còn khi \\(S_{i-1}\\) và \\(T_{j-1}\\) không bằng nhau, ta *bắt buộc* phải thực hiện chỉnh sửa. Ta có **ba** trường hợp:
- Thêm kí tự \\(T_{j-1}\\) vào xâu. Việc còn lại là xét \\(i\\) kí tự đầu của \\(S\\) với \\(j-1\\) kí tự đầu của T: \\(lev(i, j) = 1 + lev(i, j - 1)\\)
- Xoá kí tự \\(S_{i-1}\\) khỏi xâu. Việc còn lại là xét \\(i-1\\) kí tự đầu của \\(S\\) với \\(j\\) kí tự đầu của T: \\(lev(i, j) = 1 + lev(i - 1, j)\\)
- Biến đổi kí tự \\(S_{i-1}\\) thành \\(T_{j-1}\\). Việc còn lại là xét \\(i-1\\) kí tự đầu với \\(j-1\\) kí tự đầu của \\(S\\) và T: \\(lev(i, j) = 1 + lev(i - 1, j - 1)\\)

Tổng hợp các trường hợp trên, ta có công thức sau: \\[lev(i, j) = 1 + min(lev(i-1, j), lev(i, j-1), lev(i-1, j-1))\\]

```C++
int editDistance(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 0; i <= n; ++i) dp[i][0] = i;
	for(int i = 0; i <= m; ++i) dp[0][i] = i;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = 1 + min({
					dp[i-1][j],
					dp[i][j-1],
					dp[i-1][j-1]
				});
			}
		}
	}

	return dp[n][m];
}
```

Độ phức tạp của thuật toán là \\(O(|S||T|)\\).

Bài toán tìm xâu con chung dài nhất cũng là một biến thể của bài toán biến đổi xâu, với chỉ hai thao tác là *xoá* và *thêm* kí tự mà không có chỉnh sửa kí tự.