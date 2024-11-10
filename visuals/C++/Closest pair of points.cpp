#include <bits/stdc++.h>
#define point pair<double, double>
using namespace std;
static char *color[] = {"#000", "#f00"};

double randDouble(double low, double high){
	return low + (high - low) * (random() % 100000) / 100000;
}
double euclid(point a, point b){
	a.first -= b.first;
	a.second -= b.second;
	return sqrtl(a.first * a.first + a.second * a.second);
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int height, width, numPoints;
	tie(height, width, numPoints) = tuple<int, int, int>(256, 256, 16);	
	int radius(5);

	vector<point> p;
	int closest_a = 0, closest_b = 1;
	while(true){
		closest_a = 0, closest_b = 1;
		p.clear();
		for(int i = 0; i < numPoints; ++i){
			p.emplace_back(randDouble(0, height), randDouble(0, width));
		}
		sort(p.begin(), p.end());
		for(int i = 0; i < numPoints; ++i){
			for(int j = i + 1; j < numPoints; ++j){
				if(euclid(p[i], p[j]) < euclid(p[closest_a], p[closest_b])) tie(closest_a, closest_b) = tuple<int, int>(i, j);
			}
		}
		if(euclid(p[closest_a], p[closest_b]) <= radius * 2) {
			printf("Error when building image, try again\n");
		}else break;
	}
	printf("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n\
<svg viewBox=\"0.00 0.00 256.00 256.00\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" width=\"%d\" height=\"%d\">\"\n", width, height);
	for(int i = 0; i < numPoints; ++i){
		printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" style=\"fill:%s\"/>\n", p[i].first, p[i].second, radius, color[(i == closest_a || i == closest_b)]);
	}
	printf("</svg>\n");
	return 0;
}