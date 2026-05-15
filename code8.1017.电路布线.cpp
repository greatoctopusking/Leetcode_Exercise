#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void cal(vector<int>& a, int& res, int l, int r) {
	if (l >= r)return;

	int mid = l + r >> 1;
	cal(a, res, l, mid);
	cal(a, res, mid + 1, r);

	int i = l, j = mid + 1;
	vector<int> temp;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(a[j]);
			res += mid - i + 1;
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(a[i]);
		i++;
	}
	while (j <= r) {
		temp.push_back(a[j]);
		j++;
	}
	copy(temp.begin(), temp.end(), a.begin() + l);
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int res = 0;
		cal(a, res, 0, n - 1);
		printf("%d\n", res);
	}
	return 0;
}