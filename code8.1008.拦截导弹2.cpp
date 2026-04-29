#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int cal(vector<int>& a, int& n) {
	vector<pair<int, int>> dp(n, pair<int, int>(1, 0));
	for (int i = 1; i < n; i++) {
		dp[i].second = i;
		for (int j = 0; j < i; j++) {
			if (a[j] >= a[i] && dp[j].first + 1 > dp[i].first) {
				dp[i].first = dp[j].first + 1;
				dp[i].second = j;
			}
		}
	}
	auto p = max_element(dp.begin(), dp.end(), cmp);
	int i = (*p).second, j = distance(dp.begin(), p);
	while (i != j) {
		a.erase(a.begin() + j);
		j = i;
		i = dp[i].second;
		n--;
	}
	a.erase(a.begin() + j);
	n--;
	return(*p).first;
}

pair<int, int> cal2(vector<int>& a, int& n) {
	int res1 = cal(a, n);
	int res2 = 1;
	while (n > 0) {
		cal(a, n);
		res2++;
	}
	return pair<int, int>(res1, res2);
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
		pair<int, int> res = cal2(nums, n);
		printf("%d %d\n", res.first, res.second);
	}
	return 0;
}