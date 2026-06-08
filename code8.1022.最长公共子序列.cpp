#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLength(string& a, string& b) {
	int alen = a.length(), blen = b.length();
	vector<vector<int>> dp(alen + 1, vector<int>(blen + 1, 0));
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[alen][blen];
}

int main() {
	int m;
	scanf("%d", &m);
	while (m--) {
		string a, b;
		cin >> a >> b;
		int res = maxLength(a, b);
		printf("%d\n", res);
	}
	return 0;
}