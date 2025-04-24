#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int countCompleteSubarrays(std::vector<int>& nums) {
        int totalDistinct = std::unordered_set<int>(nums.begin(), nums.end()).size();
        std::unordered_map<int, int> freq;
        int left = 0, result = 0;
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            while (freq.size() == totalDistinct) {
                result += nums.size() - right;
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }
        return result;
    }
};
