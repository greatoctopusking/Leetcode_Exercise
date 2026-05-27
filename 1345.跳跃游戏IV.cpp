#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1)return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            if (!mp.count(arr[i]))mp.emplace(arr[i], vector<int>(0));
            mp[arr[i]].push_back(i);
        }

        queue<int> que;

        vector<bool> checked(arr.size(), false);
        checked[0] = true;

        int step = 0;
        int idx = 0;
        que.push(0);
        que.push(-1);
        while (idx != arr.size() - 1) {
            if (idx == -1) {
                que.pop();
                que.push(-1);
                idx = que.front();
                step++;
                continue;
            }
            checked[idx] = true;

            if (idx - 1 >= 0 && !checked[idx - 1]) {
                que.push(idx - 1); checked[idx - 1] = true;
            }
            if (!checked[idx + 1]) {
                que.push(idx + 1); checked[idx + 1] = true;
            }
            for (int i : mp[arr[idx]]) {
                if (i == idx)continue;
                if (!checked[i]) { que.push(i); checked[i] = true; }
            }
            mp.erase(arr[idx]);
            que.pop();
            idx = que.front();
        }
        return step;
    }
};

int main() {
    Solution s;
    vector<int> arr = { 100,-23,-23,404,100,23,23,23,3,404 };
    cout << s.minJumps(arr) << endl;
    return 0;
}