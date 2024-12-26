// target sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // Calculate the total sum of nums
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If the target is not reachable, return 0
        if (abs(target) > sum || (sum + target) % 2 != 0)
        {
            return 0;
        }

        // Calculate the subset sum we need to find
        int subsetSum = (sum + target) / 2;

        // Use dynamic programming to count subsets that sum to subsetSum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // Base case: There's one way to get a sum of 0 (by taking no elements)

        for (int num : nums)
        {
            for (int j = subsetSum; j >= num; --j)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};
