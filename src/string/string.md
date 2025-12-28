# Xâu kí tự

**Xâu kí tự (string)** là một chuỗi các kí tự. Trong C++, ta có thể biểu diễn xâu kí tự bằng một bảng kí tự hoặc `string`.

```C++
char xinchao_vn[] = "Xin chao the gioi";
string hello_en = "Hello world";
```

Ta quy ước các các kí tự của xâu có chỉ số từ \\(0\\).

## Thuật ngữ

Một số thuật ngữ liên quan đến xâu kí tự bao gồm:

- **Xâu con (substring)**: một xâu \\(T\\) của xâu \\(S\\) được gọi là một *xâu con* khi nó là một chuỗi các kí tự liên tiếp tồn tại trong \\(S\\). Ví dụ: xâu `chao` là xâu con của xâu `Xin chao the gioi`.
- **Tiền số (prefix)**: một xâu \\(T\\) của xâu \\(S\\) là một *tiền tố* khi nó là chuỗi các kí tự liên tiếp **đầu tiên** của \\(S\\). Ví dụ: xâu `Hello` là tiền tố của xâu `Hello world`.
- **Hậu số (suffix)**: một xâu \\(T\\) của xâu \\(S\\) là một *hậu tố* khi nó là chuỗi các kí tự liên tiếp **cuối cùng** của \\(S\\). Ví dụ: xâu `gioi` là tiền tố của xâu `Xin chao the gioi`.

## Thứ tự từ điển

Ta xét xâu \\(X = x_0x_1\dots c_n\\) bé hơn xâu \\(Y = y_0y_1\dots c_m\\) theo *thứ tự từ điển* nếu xâu X là tiền tố của xâu Y hoặc tồn tại một chỉ số \\(i \lt min(n, m)\\) sao cho \\(x_j = y_j\\) với mọi \\(j \lt i\\) và \\(x_i\\) là kí tự xuất hiện trước kí tự \\(y_i\\) theo bảng ACSII.

Ví dụ, ta có `1000 < 11` vì tại chỉ số \\(1\\) thì \\(0 < 1\\). Hoặc `aaa > aa` vì xâu `aa` là tiền tố của xâu `aaa`.  

## Các dạng xâu đặc biệt

**Xâu đối xứng (palindrome)** là một xâu mà khi ta đảo ngược các kí tự của xâu thì ta vẫn nhận được xâu ban đầu. Ví dụ: `racecar` là một xâu đối xứng vì khi ta đảo ngược các kí tự thì ta vẫn nhận được `racecar`. `palindrome` không phải là một xâu đối xứng vì xâu sau khi đảo ngược (`emordnilap`) không giống xâu ban đầu. 