#include<iostream>
using namespace std;
const int N = 1010;

int main() {
	int m, n, a[N];
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i + 1 < n; i++) {
			if (a[i] > a[i + 1])swap(a[i], a[i + 1]);
			printf("%d ", a[i]);
		}
		printf("%d\n", a[n - 1]);
	}
	return 0;
}