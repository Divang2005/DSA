#include<bits/stdc++.h>
using namespace std; 

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            return calculateXOR(nums, 0, 0); 
        }
    
        int calculateXOR(vector<int>& nums, int index, int currentXOR) {
            if (index == nums.size()){
                return currentXOR;
            }
    
            int include = calculateXOR(nums, index + 1, currentXOR ^ nums[index]); 
            int exclude = calculateXOR(nums, index + 1, currentXOR);
    
            return include + exclude; 
        }
    };