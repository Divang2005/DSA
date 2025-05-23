#include <string>
using namespace std; 

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for (int num = low; num <= high; ++num) {
                std::string s = std::to_string(num);
                int n = s.size();
                if (n % 2 != 0) continue; 
                int half = n / 2;
                int sum1 = 0, sum2 = 0;
                for (int i = 0; i < half; ++i) {
                    sum1 += s[i] - '0';
                    sum2 += s[i + half] - '0';
                }
                if (sum1 == sum2) ++count;
            }
            return count;
        }
    };

int main() {

};
    