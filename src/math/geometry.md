# Hình học

Ta sẽ tập trung chủ yếu về hình học hai chiều.

Trước khi tiếp cận các kiến thức về hình học, ta cần đặc biệt để ý về vấn đề sai số trong khi cài đặt thuật toán về hình học, hay **hình học thuật toán**.

## Về vấn đề sai số

Ta có thể cần sử dụng đến các [kiểu dữ liệu số thực](../programming/variables-data-types.md#kiểu-dữ-liệu-lưu-trữ-số-thực) khi thực hiện cài đặt các thuật toán về hình học. Để nói chi tiết hơn, các kiểu dữ liệu này được cài đặt theo tiêu chuẩn [IEEE 754](https://en.wikipedia.org/wiki/IEEE_754). Khi thực hiện các phép tính cơ bản trên kiểu dữ liệu này (\\(+, -, \times, \div, \sqrt{x}\\)), sai số của các phép tính này sẽ là một hằng số \\(\epsilon\\) được gọi là [sai số máy tính (machine epsilon)](https://en.wikipedia.org/wiki/Machine_epsilon). Đối với `float`, \\(\epsilon\\) sẽ tương đương \\(2^{-24} \approx 6,0 \times 10^{-8}\\) với `double` và `long double` sẽ là \\(2^{-53} \approx 1,1 \times 10^{-16}\\) và \\(2^{-64} \approx 5,5 \times 10^{-20}\\).

Các sai số máy tính này có vẻ rất bé, nhưng nếu thực hiện các phép tính này nhiều lần thì sai số giữa kết quả thuật toán trả về và kết quả thực tế sẽ chênh lệch một khoảng không hề nhỏ.

Chính vì thế, để hạn chế sai số, hoặc là ta *không sử dụng* kiểu dữ liệu số thực, hoặc ta có thể hiện ít các phép tính với kiểu dữ liệu này nhất có thể, và chỉ sử dụng ở các giai đoạn sau của thuật toán.