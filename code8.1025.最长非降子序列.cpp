#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal(vector<int>& a, int n) {
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i])dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int m, n;
	vector<int> nums(10010, 0);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		int res = cal(nums, n);
		printf("%d\n", res);
	}
	return 0;
}