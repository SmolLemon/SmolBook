# Cấu trúc

Sẽ có lúc ta muốn lưu thông tin về một đối tượng nào đó trong C++. Nếu không có kiểu dữ liệu nào có sẵn trong C++, ta có thể xây dựng một **cấu trúc (structure)** để lưu đối tượng ấy.

Ta có một cấu trúc lưu một điểm trên một mặt phẳng 2D.

```C++
struct Point{
	int x, y;
};
```

Bây giờ ta có thể dễ dàng lưu thông tin các điểm.

```C++
Point a;
a.x = 1;
a.y = 2;
```

Ta có thêm một **constructor** để gán giá trị khi khai báo một cấu trúc.

```C++
struct Point{
	int x, y;
	Point(int _x = 0, int _y = 0) : // nếu không gán giá trị cho các tọa độ, cho x, y bằng 0 
		x(_x), y(_y) {} // gán giá trị cho x và y
};
```

Các cấu trúc không thể có các toán tử như các kiểu dữ liệu. Ví dụ, với cấu trúc trên, ta không thể so sánh hai đỉnh `a` và `b` như  các kiểu dữ liệu được (ví dụ: `a < b`). Vì thế, ta phải tự viết các toán tử ấy trong một cấu trúc. 

```C++
struct Point{
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	bool operator<(const Point &a) const{ // toán tử so sánh nhỏ hơn 
		if (x == a.x) return y < a.y; 
		return x < a.x;
		// so sánh hai điểm điểm nào nhỏ hơn qua tọa độ x
		// nếu tọa độ x hai điểm bằng nhau thì xét tọa độ y 
	}
};
```

Các cấu trúc có thể có các hàm thực hiện một thao tác nào đó.

```C++
struct Point{
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	bool operator<(const Point &a) const{
		if (x == a.x) return y < a.y; 
		return x < a.x;
	}

	// trả về khoảng cách euclid với một điểm khác
	// gọi ngoài cấu trúc: a.euclid(x) với x là một Point
	// gọi trong cấu trúc: euclid(x)
	double euclid(Point &a){ 
		int u = x - a.x;
		int v = y - a.y;
		return sqrt(u * u + v * v);
	}
};
```

Một cấu trúc có thể ở trong một cấu trúc khác. Ta có một cấu trúc đường thằng sử dụng cấu trúc điểm và ta đã viết ở trên.

```C++
struct Line{
	Point a, b;	
};
```