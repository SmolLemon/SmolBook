# Thuật toán Knuth-Morris-Pratt (KMP)

Bài toan so khớp chuỗi là một bài toán về xâu kí tự, yêu cầu ta tìm các xâu S có độ dài \\(m\\) xuất hiện dưới dạng xâu con của một xâu T có độ dài \\(n\\). Thông th các bài toán này có \\(n\\) rất lớn. 

Một thuật toán chạy "trâu" sẽ kiểm tra *tất cả* các xâu con có độ dài \\(m\\) của xâu T và kiểm tra xem liệu nó có bằng xâu S hay không. Độ phức tạp của thuật toán này sẽ bằng \\(O(nm)\\).

**Thuật toán Knuth-Morris-Pratt** hay **thuật toán KMP** là một thuật toán có giải quyết bài toán so khớp chuỗi chỉ trong \\(O(n + m)\\). 