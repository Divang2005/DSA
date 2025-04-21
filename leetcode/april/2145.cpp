#include <bits/stdc++.h>
using namespace std; 

class Solution {
    public:
        int countHiddenSequences(vector<int>& changes, int lower, int upper) {
            long long minPrefixSum = 0, maxPrefixSum = 0;
            long long current = 0;
            
            for (int change : changes) {
                current += change;
                minPrefixSum = min(minPrefixSum, current);
                maxPrefixSum = max(maxPrefixSum, current);
            }
            
            long long range = upper - lower + 1;
            long long validStarts = range - (maxPrefixSum - minPrefixSum);
            
            return validStarts > 0 ? validStarts : 0;
        }
    };

int main()
{
    return 0;
}

    