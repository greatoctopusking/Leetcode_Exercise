#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector<int>& a, vector<int>& b, int ast, int bst, int k);

double findmid(vector<int>& a, vector<int>& b) {
	int n = a.size() + b.size();
	if (n % 2 == 1) {
		return (double)find(a, b, 0, 0, n / 2 + 1);
	}
	else {
		return (double)(find(a, b, 0, 0, n / 2) + (double)find(a, b, 0, 0, n / 2 + 1)) / 2;
	}
}

int find(vector<int>& a, vector<int>& b, int ast, int bst, int k) {
	if (ast == a.size())return b[bst + k - 1];
	if (bst == b.size())return a[ast + k - 1];

	if (k <= 1) {
		return min(a[ast], b[bst]);
	}

	int amid, bmid, akill, bkill;
	if (ast + k / 2 - 1 < a.size()) {
		amid = a[ast + k / 2 - 1];
		akill = k / 2;
	}
	else {
		amid = a[a.size() - 1];
		akill = a.size() - ast;
	}

	if (bst + k / 2 - 1 < b.size()) {
		bmid = b[bst + k / 2 - 1];
		bkill = k / 2;
	}
	else {
		bmid = b[b.size() - 1];
		bkill = b.size() - bst;
	}

	if (amid >= bmid) {
		return find(a, b, ast, bst + bkill, k - bkill);
	}
	else {
		return find(a, b, ast + akill, bst, k - akill);
	}
}

int main() {
	int nums, n, m;
	scanf("%d", &nums);
	while (nums--) {
		scanf("%d%d", &n, &m);
		vector<int> a(n), b(m);
		for (int& x : a) {
			scanf("%d", &x);
		}
		for (int& x : b) {
			scanf("%d", &x);
		}
		double res = findmid(a, b);
		printf("%.5f\n", res);
	}
	return 0;
}