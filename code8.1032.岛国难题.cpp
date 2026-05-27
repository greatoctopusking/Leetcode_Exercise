#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		double res = 1;
		for (int i = 1; i < n; i++) {
			int p;
			scanf("%d", &p);
			res += (double)p / 100;
		}
		printf("%.6f\n", res);
	}
	return 0;
}