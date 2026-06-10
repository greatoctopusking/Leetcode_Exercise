#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& size, vector<int>& value, int cap) {
	vector<int> dp(cap + 1, 0);
	for (int i = 0; i < size.size(); i++) {
		for (int j = cap; j >= size[i]; j--) {
			dp[j] = max(dp[j], dp[j - size[i]] + value[i]);
		}
	}
	int res = *max_element(dp.begin(), dp.end());
	return res;
}

int main() {
	int m, n, c;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &n, &c);
		vector<int> s(n), v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &s[i], &v[i]);
		}
		int res = solve(s, v, c);
		printf("%d\n", res);
	}
	return 0;
}