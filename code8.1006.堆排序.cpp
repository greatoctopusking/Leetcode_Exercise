#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void siftDown(vector<int>& heap, int i) {
	int n = heap.size();
	while (1) {
		int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
		if (left < n && heap[left] < heap[smallest]) smallest = left;
		if (right < n && heap[right] < heap[smallest]) smallest = right;
		if (smallest == i) break;
		swap(heap[i], heap[smallest]);
		i = smallest;
	}
}

int main() {
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		vector<int> heap(n);
		for (int& x : heap) {
			scanf("%d", &x);
		}
		for (int i = n / 2 - 1; i >= 0; i--) {
			siftDown(heap, i);
		}
		for (int x : heap)printf("%d ", x);
		printf("\n");
	}
	return 0;
}