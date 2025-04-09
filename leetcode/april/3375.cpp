#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        
        if (minValue < k)
            return -1;
        if (minValue > k)
            return numsSet.size();
        return numsSet.size() - 1;
    }
};
