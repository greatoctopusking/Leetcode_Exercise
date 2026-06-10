#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void quicksort(vector<int>& arr, int level, int l, int r) {
	if (l >= r)return;

	int x = arr[l];
	int p = l;
	for (int i = l + 1; i <= r; i++) {
		if (arr[i] < x) {
			swap(arr[++p], arr[i]);
		}
	}
	swap(arr[l], arr[p]);

	if (level == 2) {
		for (int i = l; i <= r; i++) {
			printf("%d ", arr[i]);
		}
		return;
	}

	quicksort(arr, level + 1, l, p);
	quicksort(arr, level + 1, p + 1, r);
	if (level == 1)printf("\n");
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> arr(n);
		for (int& a : arr) {
			scanf("%d", &a);
		}
		quicksort(arr, 1, 0, n - 1);
	}
	return 0;
}