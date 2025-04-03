#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long long max_value = 0;
    int max_left = nums[0];
    int max_diff = INT_MIN;

    for (int j = 1; j < nums.size() - 1; j++) {
        max_diff = max(max_diff, max_left - nums[j]);
        max_value = max(max_value, (long long)max_diff * nums[j + 1]);
        max_left = max(max_left, nums[j]);
    }

    return max_value;
}

int main() {
    vector<int> nums = {3, 7, 1, 5, 2};
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;
    return 0;
}
