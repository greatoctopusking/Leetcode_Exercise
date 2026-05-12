#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Point {
public:
	int x; int y;
	Point() { x = 0; y = 0; }
	Point(int xx, int yy):x(xx), y(yy){}
	double distance(const Point& p) {
		return pow(pow(x - p.x, 2) + pow(y - p.y, 2), 0.5);
	}
};

bool cmpx(const Point& a, const Point& b) {
	return a.x < b.x;
}

bool cmpy(const Point& a, const Point& b) {
	return a.y < b.y;
}

double cal(vector<Point>& points, int l, int r) {
	if (l == r)return INFINITY;
	if (r - l == 1) {
		if (!cmpy(points[l], points[r]))swap(points[l], points[r]);
		return points[l].distance(points[r]);
	}

	int mid = l + r >> 1;
	double midx = points[mid].x;
	double d1 = cal(points, l, mid);
	double d2 = cal(points, mid + 1, r);

	vector<Point> temp;
	int i1 = l, i2 = mid + 1;
	while (i1 <= mid && i2 <= r) {
		if (cmpy(points[i1], points[i2])) {
			temp.push_back(points[i1]); i1++;
		}
		else {
			temp.push_back(points[i2]); i2++;
		}
	}
	while (i1 <= mid) {
		temp.push_back(points[i1]); i1++;
	}
	while (i2 <= r) {
		temp.push_back(points[i2]); i2++;
	}
	copy(temp.begin(), temp.end(), points.begin() + l);

	double d = min(d1, d2);
	vector<Point> midpoints;
	for (int i = l; i <= r; i++) {
		if (points[i].x >= midx - d && points[i].x <= midx + d)
			midpoints.push_back(points[i]);
	}
	if (midpoints.size() > 1) {
		double mindis = midpoints[0].distance(midpoints[1]);
		for (int i = 0; i < midpoints.size() - 1; i++) {
			for (int j = 1; j <= 6; j++) {
				if (i + j >= midpoints.size())break;
				if (midpoints[i + j].y - midpoints[i].y > d) break;
				mindis = min(mindis, midpoints[i].distance(midpoints[i + j]));
			}
		}
		d = min(d, mindis);
	}
	return d;
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<Point> points(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &points[i].x, &points[i].y);
		}
		sort(points.begin(), points.end(), cmpx);
		double dis = cal(points, 0, n - 1);
		printf("%.2f\n", dis);
	}
	return 0;
}