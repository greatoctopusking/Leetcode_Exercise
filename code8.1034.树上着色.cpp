#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal(vector<vector<int>>& adj, int root, vector<vector<int>>& dp, int exclude, bool white) {
	if (white) {
		int res = 0;
		for (int son : adj[root]) {
			if (son == exclude)continue;
			if (dp[son][0] < 0)dp[son][0] = cal(adj, son, dp, root, true);
			if (dp[son][1] < 0)dp[son][1] = cal(adj, son, dp, root, false);
			res += max(dp[son][0], dp[son][1]);
		}
		return res;
	}
	else {
		if (dp[root][1] >= 0)return dp[root][1];
		int res = 1;
		for (int son : adj[root]) {
			if (son == exclude)continue;
			if (dp[son][0] < 0)dp[son][0] = cal(adj, son, dp, root, true);
			res += dp[son][0];
		}
		return res;
	}
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<vector<int>> adj(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(2, -1));
		int x, y;
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		x = max(cal(adj, 1, dp, 0, true), cal(adj, 1, dp, 0, false));
		printf("%d\n", x);
	}
	return 0;
}