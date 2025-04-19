#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            res += (right - left);
        }
        return res;
    }
};
