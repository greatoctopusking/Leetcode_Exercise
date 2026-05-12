#include<iostream>
#include<algorithm>
using namespace std;
const int N = 50010;

int main() {
	int n, m, a[N], x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		scanf("%d", &a[0]);
		for (int i = 1; i < n; i++) {
			scanf("%d", &x);
			if (a[i - 1] <= 0)a[i] = x;
			else a[i] = a[i - 1] + x;
		}
		x = *max_element(a, a + n);
		printf("%d\n", x);
	}
	return 0;
}