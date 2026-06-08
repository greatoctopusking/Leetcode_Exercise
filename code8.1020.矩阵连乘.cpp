#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal(vector<int>& rows, vector<int>& cols) {
	int n = rows.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			int temp = 0x3f3f3f3f;
			for (int k = j; k < i; k++) {
				temp = min(temp, dp[j][k] + dp[k + 1][i] + rows[j] * cols[k] * cols[i]);
			}
			dp[j][i] = temp;
		}
	}
	return dp[0][n - 1];
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> r(n), c(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &r[i], &c[i]);
		}
		int res = cal(r, c);
		printf("%d\n", res);
	}
	return 0;
}