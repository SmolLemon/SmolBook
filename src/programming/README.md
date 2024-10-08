# Lập trình

Đã là lập trình thi đấu thì phải có lập trình!

Ngôn ngữ lập trình C++ là một trong ngôn ngữ được sử dụng phổ biến, nếu không muốn nói là phổ biến nhất trong lập trình thi đấu. Chính vì thế, tất cả các đoạn code được viết trong Smol Book đều sẽ được viết trên C++, tương thích với tiêu chuẩn C++14 để phù hợp với **[Themis [Θέμις]- Chương trình chấm bài tự động](https://dsapblog.wordpress.com/2013/12/24/themis/)** - phần mềm chấm thi *chính thức* của Bộ Giáo dục và Đào tạo, thường xuyên được sử dụng để chấm thi trong các kỳ thi Học sinh giỏi cấp Tỉnh, Khu vực và Quốc gia.

Nên nhớ rằng ngôn ngữ lập trình chỉ là một phần nhỏ trong quá trình giải bài, điều quan trọng quan trọng là phải biết cách tư duy thuật toán và biết hiện thực hóa nó qua chương trình mình viết nên.

## Lập trình C++

Đối với C++ nói riêng và ngôn ngữ lập trình nói chung, những kiến thức về *[nhập xuất dữ liệu](io.md)*, *câu lệnh lặp*, *lệnh rẽ nhánh*, *chương trình con* là quá đủ để giải quyết hầu hết các yêu cầu về cài đặt của thuật toán. Những tính năng cụ thể về ngôn ngữ lập trình ví vụ như *Con trỏ*, *Tham chiếu*,... trong C++ có thể học sau.

[Một số mẹo khi lập trình C++ trong lập trình thi đấu](cpp-tips-and-tricks.md).

## Cài đặt môi trường code C++

Để chạy chương trình code C++ thì cần 2 phần mềm chính:

- Trình biên dịch C++ (Compiler)
- Trình soạn thảo văn bản (Text editor)

**GNU Compiler Collection (GCC)** là một trình biên dịch C++ vô cùng phổ biến.

Người dùng Windows có thể tải MinGW để sử dụng GCC.

Người dùng GNU+Linux/MacOS có thể tải về g++ thông qua package manager tương ứng.

[Codeblocks](https://www.codeblocks.org/) là một IDE được sử dụng rộng rãi trong các máy thi.

Trên các máy Windows, để tải về Codeblocks, ta truy cập [trang web](https://www.codeblocks.org/downloads/binaries/) của Codeblocks và tải về phiên bản mingw-setup bằng 1 trong 2 đường dẫn mà trang chỉ ta đến, sau đó thực hiện việc tải Codeblocks.

### Cài đặt Codeblocks cho lập trình thi đấu

Codeblocks trong các máy thi thường hoặc là mới được tải về hoặc là đang sử dụng các cài đặt mặc định. Mặc định, Codeblocks sẽ cho trình biên dịch C++ biên dịch chương trình của ta theo tiêu chuẩn C++98 (hơn 26 năm về trước). 

Để Codeblocks chạy chương trình của ta với theo những tiêu chuẩn mới hơn của C++, ta thực hiện các bước sau:

- Từ thanh menu, chọn `Settings -> Compiler`.
- Ở phần `Select compiler` chọn `GNU GCC Compiler` làm trình biên dịch C++.
- Ở phần `Compiler Flags`, đánh dấu tích <input type="checkbox" disabled checked /> ở phần `Have g++ follow the C++14 ISO C++ language standard [-std=c++14]`

Ngoài việc thêm flag `-std=c++14` để trình biên dịch biên dịch theo tiêu chuẩn C++14, ta còn thêm một số flag để giúp ta trong việc lập trình:

- `Enable all common compiler warnings (overrides many other settings) [-Wall]`
- `Enable extra compiler warnings [-Wextra]`
- `Optimize even more (for speed) [-O2]`