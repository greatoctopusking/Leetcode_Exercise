#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int m, n;
	vector<int> cost(3, 0);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> days(n, 0);
		for (int& x : days) {
			scanf("%d", &x);
		}
		days.push_back(400);
		for (int& x : cost) {
			scanf("%d", &x);
		}
		int next_idx = 0;
		vector<int> dp(366, 0);
		for (int i = 1; i <= 365; i++) {
			if (i < days[next_idx]) {
				dp[i] = dp[i - 1]; continue;
			}
			dp[i] = dp[i - 1] + cost[0];
			dp[i] = min(dp[i], dp[max(0, i - 7)] + cost[1]);
			dp[i] = min(dp[i], dp[max(0, i - 30)] + cost[2]);
			next_idx++;
		}
		printf("%d\n", dp[365]);
	}
}