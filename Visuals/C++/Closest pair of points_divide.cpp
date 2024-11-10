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

void printline(point x, int height, int radius){
 printf("<line x1=\"%lf\" y1=\"%d\" x2=\"%lf\" y2=\"%d\" style=\"stroke:orange;stroke-width:2\"/>\n", x.first, 0, x.first, height);
 printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" style=\"fill:orange\"/>\n", x.first, x.second, radius);
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	int height, width, numPoints;
	tie(height, width, numPoints) = tuple<int, int, int>(300, 300, 21);	
	int radius(5);

	vector<point> p;
	while(true){
		int closest_a = 0, closest_b = 1;
		p.clear();
		for(int i = 0; i < numPoints; ++i){
			p.emplace_back(randDouble(radius, height - radius), randDouble(radius, width - radius));
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
	int mid = (numPoints / 2);
	sort(p.begin(), p.end());
	int closest_a = 0, closest_b = 1;
	for(int i = 0; i <= mid; ++i){
		for(int j = i + 1; j <= mid; ++j){
			if(euclid(p[i], p[j]) < euclid(p[closest_a], p[closest_b])) tie(closest_a, closest_b) = tuple<int, int>(i, j);
		}
	}
	int closest_c = mid + 1, closest_d = mid + 2;
	for(int i = mid + 1; i < numPoints; ++i){
		for(int j = i + 1; j < numPoints; ++j){
			if(euclid(p[i], p[j]) < euclid(p[closest_c], p[closest_d])) tie(closest_c, closest_d) = tuple<int, int>(i, j);
		}
	}
	printf("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n\
<svg viewBox=\"0.00 0.00 %d.00 %d.00\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" width=\"%d\" height=\"%d\">\"\n", width, height, width, height);
	for(int i = 0; i < numPoints; ++i){
		if(i == numPoints / 2) printline(p[i], height, radius);
		else printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" style=\"fill:%s\"/>\n", p[i].first, p[i].second, radius, color[(i == closest_a || i == closest_b || i == closest_c || i == closest_d)]);
	}
	printf("</svg>\n");
	return 0;
}