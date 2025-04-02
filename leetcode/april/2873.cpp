#include <vector>
#include <algorithm>

using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long long max_prefix = 0, max_diff = 0, max_value = 0;

    for (int num : nums) {
        max_value = max(max_value, max_diff * static_cast<long long>(num));
        max_diff = max(max_diff, max_prefix - num);
        max_prefix = max(max_prefix, static_cast<long long>(num));
    }

    return max_value;
}
