#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> c(n, 0), y(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	int idx = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (c[idx] + i - idx >= c[i]) {
			idx = i;
		}
		res += y[i] * (c[idx] + i - idx);
	}
	cout << res;
	return 0;
}