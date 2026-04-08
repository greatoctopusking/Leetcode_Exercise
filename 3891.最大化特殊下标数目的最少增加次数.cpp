#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        vector<long long> b(n + 1);
        a[1] = max(max(nums[0], nums[2]) - nums[1] + 1, 0);
        for (int i = 3; i <= n - 2; i += 2) {
            a[i] = max(max(nums[i - 1], nums[i + 1]) - nums[i] + 1, 0) + a[i - 2];
        }
        if (n % 2 == 1)return a[n - 2];

        for (int i = n - 2; i >= 1; i -= 2) {
            b[i] = max(max(nums[i - 1], nums[i + 1]) - nums[i] + 1, 0) + b[i + 2];
        }

        long long res = b[2];
        for (int i = 1; i <= n - 3; i += 2) {
            res = min(res, a[i] + b[i + 3]);
        }
        return res;
    }
};