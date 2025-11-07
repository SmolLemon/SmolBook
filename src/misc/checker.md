# Trình chấm bài

Trong các cuộc thi như kì thi [VOI](../introduction/index.md#kì-thi-chọn-học-sinh-giỏi-quốc-gia-môn-tin-học), nơi mà ta chỉ được nộp chương trình **đúng \\(1\\) lần** cho mỗi bài toán, mặc dù ta nghĩ rằng bài nộp của ta đã đúng, thế nhưng khi kết quả được trả về thì nó lại thấp hơn so với mong đợi. Đấy là vì có sẽ có những trường hợp mà ta nghĩ rằng chương trình chạy đúng thế nhưng thực tế lại sai. Để tránh những trường hợp không đáng có trong kì thi VOI và các kì thi tương tự, ta được khuyến khích phải tự viết trình chấm bài. Việc có trình chấm sẽ giúp ta tìm ra khắc phục những lỗi sai kể trên, đồng thời giúp ta cải thiện bài nộp của ta để nâng cao điểm số.

## Các thành phần cơ bản

Trình chấm bài của ta sẽ có \\(4\\) hàm khác nhau, thực hiện các nhiệm vụ:
- **Sinh số ngẫu nhiên**: Hàm này sẽ thực hiện sinh số ngẫu nhiên trên một khoảng nhất định.
- **Sinh test**: Sử dụng hàm sinh số ngẫu nhiên ở trên, ta xây dụng một bộ test cho chương trình cần kiểm tra.
- **Kiểm tra đúng sai**: Với bộ test đã được xây dựng, ta cho chương trình của ta chạy với dữ liệu nhập là bộ test, sau đó đối chiếu kết quả với chương trình chuẩn.
- **Stress test**: Với bộ test đã được xây dựng, ta cho chương trình của ta chạy với dữ liệu nhập là bộ test, sau đó kiểm tra thời gian chạy.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NUM_TEST_CHECKER = 100; // số lần kiểm tra đúng sai
const int NUM_TEST_STRESS = 100; // số lần stress test
const string NAME = "main"; // Tên file chương trình, dữ liệu nhâp, dữ liệu xuất
mt19937 rd(time(NULL)); // hàm sinh số ngẫu nhiên

int rand(int l, int r); // Hàm sinh số ngẫu nhiên trên khoảng [l, r]
void genTest(); // Hàm sinh test
void checker(); // Hàm kiểm tra đúng sai
void stressTest(double second); // Hàm stress test

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Kiểm tra đúng sai
	for(int t = 1; t <= NUM_TEST_CHECKER; ++t) {
		genTest();
		checker();
	}
	// Stress test
	for(int t = 1; t <= NUM_TEST_STRESS; ++t) {
		genTest();
		stressTest(1.0L);
	}

	return 0;
}
```

### Sinh số ngẫu nhiên, sinh test

Để sinh số ngẫu nhiên, ta sử dụng hàm `mt19937` để sinh các số trong khoảng giá trị của kiểu dữ liệu `int` hoặc `mt19937_64` để sinh trong khoảng của `long long`. 

```C++
mt19937 rd([seed]);
```

Nếu ta muốn sinh số siêu ngẫu nhiên, ta có thể cho `seed` là một số bất kì, ví dụ như hàm `time(NULL)`, hoặc ta có thể gán cho `seed` một giá trị cụ thể để kiểm tra khi ta gặp các bộ test được xây dựng mà chương trình ta chạy sai. 

Từ hàm sinh số này, ta có thể sinh số ngẫu nhiên trong khoảng \\([l, r]\\) bằng công thức: \\[randNum = l + (rd() \bmod (r - l + 1))\\].

```C++
int rand(int l, int r){
	return l + (rd() % (r - l + 1));
}
```

Để sinh test, ta sử dụng hàm sinh số ở trên để xây dựng test. Tuỳ theo yêu cầu của bài mà ta sinh test theo yêu cầu đó. Ta sẽ ghi bộ test mà ta đã tạo vào một file nhập có đuôi `.INP`. Ở ví dụ dưới đây, ta sinh hai số \\(a\\) và \\(b\\) cho bài toán [A cộng B](https://oj.vnoi.info/problem/post).

```C++
void genTest(){
	// Hàm ofstream ghi test vào file
	ofstream inp((NAME + ".INP").c_str());
	inp << rand(1, 100) << ' ' << rand(1, 100) << '\n';
	inp.close();
}
```

### Kiểm tra đúng sai

Để xây dựng hàm kiểm tra đúng sai, ta cần viết hai chương trình ở bên ngoài: một chương trình cần kiểm tra, có file nhập là đuôi `.INP`, file xuất là `.OUT`, chương trình còn lại là chương trình "chuẩn", có file nhập là đuôi `.INP`, file xuất là `.ANS`.

Chương trình chuẩn không nhất thiết phải tối ưu, nhưng file xuất ra phải đảm bảo có kết quả chính xác để có thể có thể đối chiếu với file xuất của chương trình cần kiểm tra. 

```C++
void checker(){
	// - Chạy hai chương trình
	// - Các chương trình cần được biên dịch trước khi chạy trình chấm
	// - Đuôi file có thể thay đổi tuỳ thuộc vào hệ điều hành
	system((NAME + ".exe").c_str()); // chương trình cần kiểm tra
	system((NAME + "_trau.exe").c_str()); // chương trình "chuẩn"

	// - Hàm `fc` ở Windows so sánh hai file xuất
	// - Tuỳ thuộc vào hệ điều hành mà tên chương trình kiểm tra hai file có thể khác nhau
	if (system(("fc " + NAME + ".OUT" + NAME + ".ANS").c_str()) != 0) {
		cout << "WRONG ANSWER (WA)" << endl;
		return ;
	}
	cout << "ACCEPTED (AC)" << endl;
}
```

### Stress test

Hàm stress test sẽ chạy chương trình cần kiểm tra và đo thời gian chạy của nó.  
 
```C++
void stressTest(double second){
	int nanoSecond = second * 1'000'000; // chuyển đổi từ giây sang micro giây

	// Bắt đầu chương trình
	auto a = chrono::high_resolution_clock::now();
	system((NAME + ".exe").c_str());
	// Kết thúc chương trình
	auto b = chrono::high_resolution_clock::now();
	
	// Thời gian chạy chương trình (micro giây)
	auto duration = chrono::duration_cast<microseconds>(b - a);
	int execTime = duration.count();

	if(execTime > second) {
		cout << "TIME LIMIT EXCEEDED (TLE)" << endl;
		return; 
	}
	cout << "ACCEPTED (AC)" << endl;
}
```

<br>

Đây là tổng hợp chương trình chấm bài của ta với các hàm ở trên.

```C++
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NUM_TEST_CHECKER = 100;
const int NUM_TEST_STRESS = 100;
const string NAME = "main";
mt19937 rd(time(NULL));

int rand(int l, int r);
void genTest();
void checker();
void stressTest(double second);

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int t = 1; t <= NUM_TEST_CHECKER; ++t) {
		genTest();
		checker();
	}

	for(int t = 1; t <= NUM_TEST_STRESS; ++t) {
		genTest();
		stressTest(1.0L);
	}

	return 0;
}

int rand(int l, int r){
	return l + (rd() % (r - l + 1));
}

void genTest(){
	ofstream inp((NAME + ".INP").c_str());
	inp << rand(1, 100) << ' ' << rand(1, 100) << '\n';
	inp.close();
}

void checker(){
	system((NAME + ".exe").c_str());
	system((NAME + "_trau.exe").c_str());

	if (system(("fc " + NAME + ".OUT" + NAME + ".ANS").c_str()) != 0) {
		cout << "WRONG ANSWER (WA)" << endl;
		return ;
	}
	cout << "ACCEPTED (AC)" << endl;
}

void stressTest(double second){
	int nanoSecond = second * 1'000'000;

	auto a = chrono::high_resolution_clock::now();
	system((NAME + ".exe").c_str());
	auto b = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<microseconds>(b - a);
	int execTime = duration.count();

	if(execTime > second) {
		cout << "TIME LIMIT EXCEEDED (TLE)" << endl;
		return; 
	}
	cout << "ACCEPTED (AC)" << endl;
}
```