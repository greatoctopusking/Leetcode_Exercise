#include<iostream>
#include<vector>
using namespace std;
const int N = 22;
int a[N];
int sum[N];
long long dp[N][N];

int main() {
    int m, n, k;
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0)sum[i] = a[i] + sum[i - 1];
            else sum[i] = a[i];
        }
        for (int i = 0; i < n - k; i++) {
            dp[i][0] = sum[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = max(1, k - n + i + 1); j <= min(k, i); j++) {
                long long temp = 0;
                for (int p = j - 1; p <= i - 1; p++) {
                    temp = max(temp, dp[p][j - 1] * (sum[i] - sum[p]));
                }
                dp[i][j] = temp;
            }
        }
        printf("%lld\n", dp[n - 1][k]);
    }
    
    return 0;
}