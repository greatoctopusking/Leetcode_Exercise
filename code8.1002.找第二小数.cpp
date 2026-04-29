#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int m, n;
	vector<int> nums(1010, 0);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		int a = 0x3f3f3f3f, b = 0x3f3f3f3f, temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp <= a) {
				b = a; a = temp;
			}
			else if (a < temp && temp < b) {
				b = temp;
			}
		}
		printf("%d\n", b);
	}
	return 0;
}