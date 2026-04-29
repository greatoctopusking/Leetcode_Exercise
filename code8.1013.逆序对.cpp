#include<iostream>
#include<vector>
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
			j++;
			res += mid - i + 1;
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
	int m, n, res;
	vector<int> nums(50010, 0);
	scanf("%d", &m);
	while (m--) {
		res = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		cal(nums, res, 0, n - 1);
		printf("%d\n", res);
	}
	return 0;
}