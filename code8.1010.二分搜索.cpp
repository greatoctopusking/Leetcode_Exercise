#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int>& a, int l, int r, const int &x, int father, bool &success) {
	if (l > r) {
		if (a[l] == x) {
			success = true; return father;
		}
		else { success = false; return father; }
	}

	int mid = l + r >> 1;
	if (a[mid] == x) {
		success = true;
		return father;
	}
	else if (a[mid] > x) {
		return search(a, l, mid - 1, x, a[mid], success);
	}
	else {
		return search(a, mid + 1, r, x, a[mid], success);
	}
}

int main() {
	int m, n, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &n, &x);
		vector<int> nums(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		bool success = true;
		int father = search(nums, 0, n - 1, x, -1, success);
		if (success) {
			printf("success, father is %d\n", father);
		}
		else {
			printf("not found, father is %d\n", father);
		}
	}
	return 0;

}