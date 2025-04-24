#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std; 

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> freq;
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
