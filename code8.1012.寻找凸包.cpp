#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

class Point {
public:
	int x; int y;
	Point(int xx, int yy):x(xx),y(yy){}
	Point() { x = 0; y = 0; }
	double distance(const Point& a, const Point& b) {
		return abs((b.x - a.x) * (y - a.y) - (b.y - a.y) * (x - a.x)) / hypot(b.x - a.x, b.y - a.y);
	}
	bool isRight(const Point& a, const Point& b) {
		double res = (b.x - a.x) * (y - a.y) - (b.y - a.y) * (x - a.x);
		return res < 0;
	}
};

bool cmp(const Point& a, const Point& b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

void search(vector<Point>& part, vector<Point>& res, const Point& A, const Point& B) {
	if (part.size() == 0) {
		res.push_back(B);
		return;
	}
	Point temp; double dis = 0;
	for (Point p : part) {
		if (p.distance(A, B) > dis) {
			dis = p.distance(A, B);
			temp = p;
		}
	}
	vector<Point> part1, part2;
	for(Point p : part){
		if (p.isRight(A, temp))part1.push_back(p);
		else if (p.isRight(temp, B))part2.push_back(p);
	}
	search(part1, res, A, temp);
	search(part2, res, temp, B);
}

vector<Point> solve(vector<Point>& graph) {
	vector<Point> res;
	if (graph.size() == 0)return res;
	if (graph.size() == 1) {
		res.push_back(graph[0]);
		return res;
	}
	sort(graph.begin(), graph.end(), cmp);
	Point A = graph[0];
	Point B = graph[graph.size() - 1];
	vector<Point> part1, part2;
	for (Point p : graph) {
		if (p.isRight(A, B))part1.push_back(p);
		else if (p.isRight(B, A))part2.push_back(p);
	}
	res.push_back(A);
	search(part1, res, A, B);
	search(part2, res, B, A);
	res.pop_back();
	return res;
}

int main() {
	int m, n, x, y, idx = 1;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<Point> graph;
		while (n--) {
			scanf("%d%d", &x, &y);
			graph.push_back(Point(x, y));
		}
		vector<Point> res = solve(graph);
		printf("case %d:\n", idx);
		for (Point p : res) {
			printf("%d %d\n", p.x, p.y);
		}
		idx++;
	}
}