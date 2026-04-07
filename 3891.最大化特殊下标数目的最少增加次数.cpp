#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        if (nums.size() % 2 == 1) {
            long long res = 0;
            for (int i = 1; i < nums.size(); i += 2) {
                if (nums[i] <= max(nums[i - 1], nums[i + 1])) {
                    res += max(nums[i - 1], nums[i + 1]) - nums[i] + 1;
                }
            }
            return res;
        }
        else {
            long long res = 0x3f3f3f3f;
            int size = nums.size();
            long long temp = 0;
            for (int j = 2; j <= size; j += 2) {
                for (int i = 1; i + 1 < j; i += 2) {
                    if (nums[i] <= max(nums[i - 1], nums[i + 1])) {
                        temp += max(nums[i - 1], nums[i + 1]) - nums[i] + 1;
                    }
                }
                for (int k = j; k < size; k += 2) {
                    if (nums[k] <= max(nums[k - 1], nums[k + 1])) {
                        temp += max(nums[k - 1], nums[k + 1]) - nums[k] + 1;
                    }
                }
                res = min(res, temp);
                temp = 0;
            }
            return res;
        }
    }
};