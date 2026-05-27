#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void search(vector<vector<int>>& mat, int xoffset, int xlimit, int yoffset, int ylimit, int& target, bool& res) {
	if (xoffset == xlimit && yoffset == ylimit) {
		res = (mat[yoffset][xoffset] == target);
		return;
	}

	if (yoffset < mat.size() && xoffset <= xlimit) {
		for (int i = xoffset; i <= xlimit; i++) {
			if (mat[yoffset][i] > target) {
				xlimit = i - 1;
				break;
			}
		}
	}
	if (xlimit >= 0 && yoffset <= ylimit) {
		for (int i = ylimit; i >= yoffset; i--) {
			if (mat[i][xlimit] < target) {
				yoffset = i + 1;
				break;
			}
		}
	}
	if (ylimit >= 0 && xoffset <= xlimit) {
		for (int i = xlimit; i >= xoffset; i--) {
			if (mat[ylimit][i] < target) {
				xoffset = i + 1;
				break;
			}
		}
	}
	if (xoffset < mat[0].size() && yoffset <= ylimit) {
		for (int i = yoffset; i <= ylimit; i++) {
			if (mat[i][xoffset] > target) {
				ylimit = i - 1;
				break;
			}
		}
	}
	if (xoffset <= xlimit && yoffset <= ylimit)search(mat, xoffset, xlimit, yoffset, ylimit, target, res);
}

int main() {
	int nums, m, n, tar;
	scanf("%d", &nums);
	while (nums--) {
		scanf("%d%d%d", &m, &n, &tar);
		vector<vector<int>> matrix(m, vector<int>(n, 0));
		for (vector<int>& row : matrix) {
			for (int& ele : row) {
				scanf("%d", &ele);
			}
		}
		bool res = false;
		search(matrix, 0, n - 1, 0, m - 1, tar, res);
		if (res)printf("true\n");
		else printf("false\n");
	}
	return 0;
}