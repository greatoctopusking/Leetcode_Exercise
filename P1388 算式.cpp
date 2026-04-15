#include<iostream>
#include<vector>
using namespace std;
const int N = 20;
int n, k;
int a[N];
int sum[N];
int dp[N][N];

int main() {
    cin >> n >> k;
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
            int temp = 0;
            for (int p = j - 1; p <= i - 1; p++) {
                temp = max(temp, dp[p][j - 1] * (sum[i] - sum[p]));
            }
            dp[i][j] = temp;
        }
    }
    cout << dp[n - 1][k];
}