#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<long long> c(n, 0), y(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &c[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &y[i]);
		}

		int idx = 0;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (c[idx] + i - idx >= c[i]) {
				idx = i;
			}
			res += y[i] * (c[idx] + i - idx);
		}
		printf("%lld\n", res);
	}
	
	return 0;
}