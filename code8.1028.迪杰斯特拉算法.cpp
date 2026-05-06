#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int m, n, e, s, t;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d%d%d", &n, &e, &s, &t);
		if (s == t) {
			printf("0\n");
			continue;
		}
		vector<long long> list(n + 1, 0x3f3f3f3f3f3f3f3fLL);
		list[s] = 0;
		vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));
		for (int i = 1; i <= n; i++)adj[i][i] = 0;
		vector<bool> isInPath(n + 1, false);
		isInPath[s] = true;
		int u, v, w;
		while (e--) {
			scanf("%d%d%d", &u, &v, &w);
			if (adj[u][v] >= 0)adj[u][v] = min(w, adj[u][v]);
			else adj[u][v] = w;
			adj[v][u] = adj[u][v];
		}
		u = s; 
		long long res = -1;
		while (1) {
			for (int i = 1; i <= n; i++) {
				if(adj[u][i] > 0)list[i] = min(list[i], list[u] + (long long)adj[u][i]);
			}
			long long temp = 0x3f3f3f3f3f3f3f3fLL;
			for (int i = 1; i <= n; i++) {
				if (!isInPath[i] && temp > list[i]) {
					temp = list[i];
					u = i;
				}
			}
			if (temp == 0x3f3f3f3f3f3f3f3fLL)break;
			isInPath[u] = true;

			if (u == t) {
				res = temp;
				break;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}