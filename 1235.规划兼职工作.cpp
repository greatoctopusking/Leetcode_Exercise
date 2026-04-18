#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<random>

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> time;
        time.push_back(0);
        time.insert(time.end(), startTime.begin(), startTime.end());
        time.insert(time.end(), endTime.begin(), endTime.end());

        sort(time.begin(), time.end());

        auto last = unique(time.begin(), time.end());

        time.erase(last, time.end());

        int n = time.size();
        vector<int> dp(n + 1, 0);
        unordered_multimap<int, int> mp;
        for (int i = 0; i < endTime.size(); i++) {
            mp.insert({ endTime[i], i });
        }
        for (int i = 1; i <= n; i++) {
            int temp = dp[i - 1];
            vector<int> ls;
            auto range = mp.equal_range(time[i]);
            for (auto it = range.first; it != range.second; it++) {
                ls.push_back(it->second);
            }
            for (int idx : ls) {
                auto it = lower_bound(time.begin(), time.end(), startTime[idx]);
                temp = max(temp, dp[it - time.begin()] + profit[idx]);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};

int main() {
    Solution S;
    vector<int> st, et;
    for (int i = 1; i < 50000; i++) { st.push_back(i); }
    for (int i = 99999; i > 50000; i--) { et.push_back(i); }
    
    mt19937 rng(42);
    vector<int> pro;
    pro.reserve(49999);
    for (int i = 0; i < 49999; i++) {
        pro.push_back(rng() % 10000 + 1);
    }
    
    cout << S.jobScheduling(st, et, pro);
}