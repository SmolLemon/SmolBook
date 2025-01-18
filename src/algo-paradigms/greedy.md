# Tham lam

*Tham thì thâm - Thành ngữ*

<br>

Một thuật toán **tham lam** là một thuật toán xây dựng đáp án từ phương án nhìn tốt nhất ở thời điểm hiện tại. Các thuật toán tham lam sẽ không chọn lại đáp án, làm cho nó thực hiện thuật toán vô cùng nhanh và hiệu quả.

Hầu hết các bài toán tham lam sẽ có hai tính chất:

- **Tính tham lam**: Nếu ta chọn phương án tốt nhất ở hiện tại và cứ tiếp tục như thế cho đến cuối thuật toán, ta sẽ có kết quả tối ưu. Việc xác định tính tham lam của một bài toán là một điều khó! 
- **Cấu trúc con tối ưu (optimal substructure)**: Ta nói một bài toán có tính chất tối ưu nếu đáp án tối ưu được xây dựng từ kết quả tối ưu của các bài toán con.

Ta cùng điểm qua một số bài toán kinh điển có thể được giải bằng thuật toán tham lam.

## Bài toán đổi tiền - Coin Change

Giả sử ta có một số lượng rất lớn tờ tiền Việt Nam Đồng (nghìn đồng): 

\\[\\{1, 2, 5, 10, 20, 50, 100, 200, 500\\}\\]

Nhiệm vụ của ta là sử dụng ít tờ tiền nhất sao cho tổng giá trị những tờ tiền ta chọn bằng \\(X\\) nghìn đồng. Ví dụ: nếu \\(X = 670\\) thì ta cần ít nhất \\(4\\) tờ tiền. Một cách chọn tối ưu chính là \\(500 + 100 + 50 + 20\\).

Một thuật toán tham lam giải quyết bài toán này là ta lần lượt trừ số tiền hiện tại bằng giá trị tờ tiền lớn nhất có thể cho đến khi số tiền hiện tại bằng \\(0\\).

Ta có:

\\[670 \rightarrow 670 - 500 = 170\\]
\\[170 \rightarrow 170 - 100 = 70 \\]
\\[70 \rightarrow 70 - 50 = 20\\]
\\[20 \rightarrow 20 - 20 = 0\\]

Thuật toán trên thỏa mãn hai tính chất của một thuật toán tham lam:

- Cấu trúc con tối ưu: Lời giải tối ưu cho \\(670\\) nghìn đồng sử dụng đáp án của lời giải tối ưu cho \\(170\\) nghìn đồng. Lời giải cho \\(170\\) lại sử dụng đáp án của lời giải \\(70\\) nghìn đồng và cứ tiếp tục như thế.
- Tính tham lam: Sử dụng thuật toán tham lam, ta có thể tìm ra kết quả tối ưu của bài toán (bỏ qua phần chứng minh).

Tuy nhiên các thuật toán tham lam chỉ đúng với một số trường hợp như trường hợp trên. Giả sử các tờ tiền được thay đổi thành:

\\[\\{1, 3, 4\\}\\]

Thì thuật toán tham lam sẽ không còn đúng nữa. Nếu \\(X = 6\\) thì thuật toán trên sẽ cần \\(3\\) tờ tiền \\(4 + 1 + 1\\), trong khi đáp án tối ưu là \\(2\\) tờ tiền \\(3 + 3\\).

## Bài toán xếp lịch

