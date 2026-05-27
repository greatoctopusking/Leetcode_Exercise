#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int cal(vector<int>& starttime, vector<int>& endtime, vector<int>& weight) {
	vector<int> time;
	time.push_back(0);
	time.insert(time.end(), starttime.begin(), starttime.end());
	time.insert(time.end(), endtime.begin(), endtime.end());
	sort(time.begin(), time.end());
	auto last = unique(time.begin(), time.end());
	time.erase(last, time.end());

	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < endtime.size(); i++) {
		if (!mp.count(endtime[i]))mp.emplace(endtime[i], vector<int>(0));
		mp[endtime[i]].push_back(i);
	}

	int n = time.size();
	vector<int> dp(n, 0);
	for (int t = 1; t <= n - 1; t++) {
		if (!mp.count(time[t])) { dp[t] = dp[t - 1]; continue; }
		int temp = dp[t - 1];
		for (int task : mp[time[t]]) {
			auto it = lower_bound(time.begin(), time.end(), starttime[task]);
			temp = max(temp, dp[it - time.begin()] + weight[task]);
		}
		dp[t] = temp;
	}
	return dp[n - 1];
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> st(n), ed(n), w(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &st[i], &ed[i], &w[i]);
		}
		int res = cal(st, ed, w);
		printf("%d\n", res);
	}
	return 0;
}