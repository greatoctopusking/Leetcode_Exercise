#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int m, n;
	vector<int> white(10010, 0), black(10010, 0);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		int p = 0, q = 0, temp;
		for (int i = 0; i < 2 * n; i++) {
			scanf("%d", &temp);
			if (temp)black[q++] = i;
			else white[p++] = i;
		}
		temp = 0;
		for (int i = 0; i < n; i++) {
			temp += abs(white[i] - black[i]);
		}
		printf("%d\n", temp);
	}
}