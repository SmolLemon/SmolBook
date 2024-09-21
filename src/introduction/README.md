# Giới thiệu về lập trình thi đấu

**Lập trình thi đấu**, tên tiếng anh là **competitive programming**, về cơ bản là một *bộ môn thể thao*, nơi thí sinh viết nên các chương trình máy tính để giải quyết các bài toán.

## Tổng quan

Một bài toán về lập trình thi đấu sẽ yêu cầu thí sinh viết ra một chương trình máy tính với khả năng giải quyết bài toán ấy mà không vượt quá các giới hạn về thời gian và bộ nhớ được cho. Những bài này mang tính toán học và có tính thực tiễn. Các bài toán thường sẽ liên quan đến những chủ đề khác nhau: tổ hợp, lí thuyết số, lí thuyết đồ thị, lí thuyết trò chơi, xử lí xâu, cấu trúc dữ liệu,... 

Một chương trình máy tính được viết ra bởi thí sinh để giải một bài toán cụ thể sẽ lấy dữ liệu nhập (**input**) và xuất dữ liệu (**output**) chứa đáp án đúng tương ứng. 

Ta ví dụ với bài toán "A cộng B" trên [VNOJ - VNOI Online Judge](https://oj.vnoi.info/problem/post):

![Bài toán A + B](../images/A_+_B_VNOJ.png)

Bài toán cho ta 2 số A và B và yêu cầu ta tính tổng của hai số ấy. Dữ liệu vào sẽ là 2 số A và B trên 1 dòng và yêu cầu ta in ra tổng hai số.

Khi ta nộp chương trình ta viết ra, máy chấm của VNOJ sẽ chạy chương trình với một danh sách các dữ liệu nhập (tạm gọi là testcase) và kiểm tra đáp án mà chương trình in ra với mỗi testcase tương ứng. Với mỗi testcase, máy chấm sẽ trả về cho ta một trong các kết quả sau đây:

|Kết quả|Ý nghĩa|
|---|---|
|<span style="color:Green">Accepted (AC)</span>| Chương trình in kết quả đúng và thỏa mãn các yêu cầu của bài.|
|<span style="color:Red">Wrong Answer (WA)</span>| Chương trình cho ra kết quả sai.|
|<span style="color:gray;">Compilation Error (CE)</span>| Chương trình bị lỗi biên dịch.|
|<span style="color:Orange">Runtime Error (RTE)</span>| Chương trình gặp lỗi khi chạy.|
|<span style="color:Orange">Output Limit Exceeded (OLE)</span>| Chương trình in ra quá nhiều dữ liệu. |
|<span style="color:Orange">Memory Limit Exceeded (MLE)</span>| Chương trình sử dụng bộ nhớ nhiều hơn quy định.|
|<span style="color:gray;">Time Limit Exceeded (TLE)</span>| Chương trình chạy quá thời gian quy định.|
|<span style="color:Red">Internal Error (IE)</span>| Lỗi đến từ hệ thống máy chấm.|

Tùy theo *thể thức* mà điểm cho mỗi bài sẽ khác nhau. Có thể thức sẽ tính điểm theo `số lượng testcase AC/số lượng testcase`, có thể thức chỉ cho điểm khi ta AC toàn bộ các testcase. 

## Vì sao cần rèn luyện lập trình thi đấu?

Việc giải các bài toán và tham gia các cuộc thi lập trình thi đấu có thể giúp các thí sinh có hứng thú với các ngành liên quan đến khoa học máy tính. Những kiến thức học được từ lập trình thi đấu cũng cải thiện khả năng lập trình và tư duy logic của các lập trình viên, giúp họ có lợi thế trong công việc.

## Các cuộc thi lập trình

Có vô số cuộc thi lập trình phổ biến trên toàn quốc và quốc tế. Ta cùng điểm qua một số cuộc thi tiêu biểu.

### Kì thi Học sinh giỏi cấp trường/thành phố/tỉnh (môn Tin học)

Mục đích của các cuộc thi này nhằm động viên, khuyến khích học sinh và giáo viên phát huy và nâng cao năng lực của bản thân, đồng thời phát hiện và bồi dưỡng những học sinh có năng khiếu ở các môn học.

### Kỳ thi Olympic truyền thống 30/4 (môn Tin học)

**Cuộc thi Olympic truyền thống 30/4** là một cuộc thi học sinh giỏi hàng năm dành cho học sinh khối 10 và 11 của khu vực phía Nam. Cuộc thi này do trường THPT Chuyên Lê Hồng Phong TPHCM sáng lập và được tổ chức lần đầu tiên vào năm 1995 với mục đích phát hiện, bồi dưỡng những học sinh có năng khiếu thuộc các khối lớp 10 và 11, chuẩn bị đội ngũ cho kỳ thi học sinh giỏi quốc gia, tạo điều kiện cho việc giao lưu học hỏi giữa các học sinh giỏi và trao đổi chuyên môn giữa các thầy cô dạy lớp chuyên của các tỉnh phía Nam.[^1]

### Kỳ thi chọn Học sinh sinh giỏi khu vực Duyên Hải và đồng bằng Bắc Bộ (môn Tin học)

Kỳ thi do Hội các trường THPT chuyên khu vực duyên hải và đồng bằng Bắc Bộ tổ chức hằng năm. 
Kỳ thi là dịp phát hiện học sinh giỏi, học sinh xuất sắc các bộ môn để các trường THPT chuyên có kế hoạch lựa chọn, bồi dưỡng các em tham gia các kỳ thi học sinh giỏi quốc gia, khu vực và quốc tế. Đồng thời là dịp để đội ngũ cán bộ quản lý và giáo viên các trường THPT chuyên trao đổi, chia sẻ kinh nghiệm, nâng cao trình độ chuyên môn bồi dưỡng môn chuyên và học sinh giỏi.[^2].
### Kì thi chọn Học sinh giỏi Quốc gia (môn Tin học)

**Kỳ thi chọn học sinh giỏi quốc gia trung học phổ thông** (viết tắt là Kỳ thi HSGQG) là kỳ thi chọn học sinh giỏi cấp quốc gia dành cho học sinh bậc trung học phổ thông do Bộ Giáo dục và Đào tạo tổ chức vào khoảng từ tháng 12 đến tháng 1 hằng năm. Những học sinh đạt điểm cao nhất trong kỳ thi này ở một vài bộ môn được Bộ Giáo dục và Đào tạo triệu tập tại Hà Nội, Việt Nam để tham gia kỳ thi chọn các học sinh vào đội tuyển Quốc gia Việt Nam tham dự các cuộc thi Olympic khu vực và quốc tế.[^3].

Ở bộ môn tin học, cuộc thi có tên gọi không chính thức là **VOI - Vietnamese Olympiad in Informatics**.

### Hội thi Tin học trẻ các cấp

**Hội thi Tin học trẻ** là kì thi tin học thường niên dành cho các học sinh các cấp. Đây là sân chơi uy tín trong lĩnh vực tin học, do Trung ương Đoàn, Bộ Khoa học và Công nghệ, Bộ Giáo dục và Đào tạo, Bộ Thông tin và Truyền thông và Hội Tin học Việt Nam phối hợp tổ chức thường niên từ năm 1995.

### Olympic Tin học Quốc tế (IOI)

**Olympic Tin học Quốc tế** (**International Olympiad in Informatics - IOI**) là một cuộc thi quốc tế lập trình thi đấu thường niên dành cho học sinh trung học (cấp 2 và 3). Cuộc thi đầu tiên được tổ chức vào năm 1989 tại Bulgaria.

### ICPC

**International Collegiate Programming Contest**, hay **ICPC**, là một cuộc thi lập trình dành cho sinh viên. Đây là cuộc thi lập trình lâu đời nhất, lớn nhất và danh tiếng nhất thế giới. Hằng năm, cuộc thi thu hút hơn 50000 thí sinh từ hơn 3000 trường đại học khác nhau trên toàn thế giới. [^4]

## Các trang web lập trình thi đấu

Ngoài các cuộc thi lập trình thi đấu, nhiều trang web được tạo ra nhằm hỗ trợ và cung cấp nhiều điều bổ ích cho các thí sinh trên toàn thế giới. Các trang như [VNOJ](https://oj.vnoi.info/), [Codeforces](https://codeforces.com/), [Atcoder](https://atcoder.jp/),... là một trong những ví dụ điển hình. Các trang này tổ chức các cuộc thi online, có nhiều dạng bài phong phú, một số trang còn hỗ trợ tìm kiếm việc làm liên quan đến lập trình!

--- 

[^1]: <http://www.thpt-lehongphong-tphcm.edu.vn/vi/content/ky-thi-olympic-truyen-thong-304-lan-thu-xxvi-nam-2021>

[^2]: <https://baohaiduong.vn/gan-2-000-hoc-sinh-khu-vuc-duyen-hai-va-dong-bang-bac-bo-thi-chon-hoc-sinh-gioi-tai-tp-hai-duong-387551.html>

[^3]: <https://vi.wikipedia.org/wiki/Kỳ_thi_chọn_học_sinh_giỏi_quốc_gia_trung_học_phổ_thông>

[^4]: <https://icpc.global/>