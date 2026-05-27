#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int nums, k, n;
	scanf("%d", &nums);
	while (nums--) {
		scanf("%d%d", &k, &n);
		vector<int> dp(k + 1, 0);
		int i = 0, res = -1;
		while (res < 0) {
			i++;
			for (int j = k; j >= 1; j--) {
				dp[j] = dp[j] + dp[j - 1] + 1;
				if (dp[j] >= n) {
					res = i;
					break;
				}
			}
		}
		printf("%d\n", res);
	}
}