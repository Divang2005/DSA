#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r)
        {
            const int m = (l + r) / 2;
            if (numOperations(nums, m) <= maxOperations)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }

private:
    int numOperations(const vector<int> &nums, int m)
    {
        int operations = 0;
        for (const int num : nums)
            operations += (num - 1) / m;
        return operations;
    }
};