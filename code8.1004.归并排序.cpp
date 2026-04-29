#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void mergesort(vector<int>& a, int l, int r, int level) {
	level++;
	if (l >= r)return;

	int mid = l + r >> 1;
	mergesort(a, l, mid, level);
	mergesort(a, mid + 1, r, level);

	if (level <= 3)return;

	vector<int> temp;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(a[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(a[i]);
		i++;
	}
	while (j <= r) {
		temp.push_back(a[j]);
		j++;
	}

	copy(temp.begin(), temp.end(), a.begin() + l);
}

int main() {
	int m, n;
	vector<int> a(1010, 0);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		mergesort(a, 0, n - 1, 1);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}