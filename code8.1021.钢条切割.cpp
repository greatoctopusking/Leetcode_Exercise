#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int cut(int n, unordered_map<int, int>& v) {
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int temp = dp[i - 1];
		for (const auto& [len, val] : v) {
			if (len <= i) {
				temp = max(temp, val + dp[i - len]);
			}
		}
		dp[i] = temp;
	}
	return dp[n];
}

int main() {
	int m, n, k;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &n, &k);
		unordered_map<int, int> v;
		int l, p;
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &l, &p);
			v.emplace(l, p);
		}
		int res = cut(n, v);
		printf("%d\n", res);
	}
	return 0;
}