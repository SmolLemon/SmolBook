# Xâu kí tự

**Xâu kí tự (string)** là một chuỗi các kí tự. Trong C++, ta có thể biểu diễn xâu kí tự bằng một bảng kí tự hoặc `string`.

```C++
char xinchao_vn[] = "Xin chao the gioi";
string hello_en = "Hello world";
```

## Thuật ngữ

Một số thuật ngữ liên quan đến xâu kí tự bao gồm:

- **Xâu con (substring)**: một xâu T của xâu S được gọi là một *xâu con* khi nó là một chuỗi các kí tự liên tiếp tồn tại trong S. Ví dụ: xâu `chao` là xâu con của xâu `xinchao_vn`.
- **Tiền số (prefix)**: một xâu T của xâu S là một *tiền tố* khi nó là chuỗi các kí tự liên tiếp **đầu tiên** của S. Ví dụ: xâu `Hello` là tiền tố của xâu `hello_en`.
- **Hậu số (suffix)**: một xâu T của xâu S là một *hậu tố* khi nó là chuỗi các kí tự liên tiếp **cuối cùng** của S. Ví dụ: xâu `gioi` là tiền tố của xâu `xinchao_vn`.

## Các dạng xâu đặc biệt

**Xâu đối xứng (palindrome)** là một xâu mà khi ta đảo ngược các kí tự của xâu thì ta vẫn nhận được xâu ban đầu. Ví dụ: `racecar` là một xâu đối xứng vì khi ta đảo ngược các kí tự thì ta vẫn nhận được `racecar`. `palindrome` không phải là một xâu đối xứng vì xâu sau khi đảo ngược (`emordnilap`) không giống xâu ban đầu. 