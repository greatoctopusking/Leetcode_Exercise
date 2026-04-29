#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool search(vector<int>& a, int n, int x) {
	unordered_set<int> checked;
	for (int i = 0; i < n; i++) {
		if (checked.count(a[i]))return true;
		checked.insert(x - a[i]);
	}
	return false;
}

int main() {
	vector<int> nums(50010, 0);
	int n, m, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		if (search(nums, n, x))printf("yes\n");
		else printf("no\n");
	}
}