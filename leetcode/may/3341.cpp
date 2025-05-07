#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, unordered_map<int, int>> activeColors; 
        map<int, int> result;

        for (auto& q : queries) {
            int start = q[0], end = q[1], color = q[2];
            activeColors[start][color]++;
            activeColors[end + 1][color]--;
        }

        unordered_map<int, int> colorCount;
        int currentDistinct = 0;

        for (auto& [pos, colorChanges] : activeColors) {
            for (auto& [color, change] : colorChanges) {
                int& count = colorCount[color];
                if (count == 0 && change > 0) currentDistinct++;
                count += change;
                if (count == 0) currentDistinct--;
            }
            result[pos] = currentDistinct;
        }

        vector<int> answer;
        int lastValue = 0;
        auto it = result.begin();
        for (int i = 0; i < limit; ++i) {
            while (it != result.end() && it->first <= i) {
                lastValue = it->second;
                ++it;
            }
            answer.push_back(lastValue);
        }

        return answer;
    }
};
