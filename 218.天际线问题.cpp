#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return merge(buildings, 0, buildings.size() - 1);
    }

    vector<vector<int>> merge(vector<vector<int>>& buildings, int l, int r) {
        if (l == r)return{ {buildings[l][0], buildings[l][2]}, {buildings[l][1], 0} };

        vector<vector<int>> a = merge(buildings, l, (l + r) >> 1);
        vector<vector<int>> b = merge(buildings, ((l + r) >> 1) + 1, r);

        vector<vector<int>> res;
        int i = 0, j = 0, h = 0, p = 0, q = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i][0] < b[j][0]) {
                h = a[i][1];
                if (h > q)res.push_back(a[i]);
                else if (h <= q && p > q)res.push_back({ a[i][0], q });
                p = h;
                i++;
            }
            else if (a[i][0] > b[j][0]) {
                h = b[j][1];
                if (h > p)res.push_back(b[j]);
                else if (h <= p && q > p)res.push_back({ b[j][0], p });
                q = h;
                j++;
            }
            else {
                h = max(a[i][1], b[j][1]);
                if (h != max(p, q)) {
                    res.push_back({ a[i][0], h });
                }
                p = a[i][1];
                q = b[j][1];
                i++; j++;
            }
        }
        while (i < a.size()) {
            res.push_back(a[i++]);
        }
        while (j < b.size()) {
            res.push_back(b[j++]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> input = { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
    Solution s;
    vector<vector<int>> output = s.getSkyline(input);

    for (auto line : output) {
        cout << '{'<<' ';
        for (auto ele : line) {
            cout << ele<<' ';
        }
        cout << '}' << ' ';
    }
}