#include <bits/stdc++.h>
using namespace std; 

class Solution {
    public:
        class FenwickTree {
        public:
            vector<int> tree;
            int n;
    
            FenwickTree(int size) : n(size) {
                tree.resize(n + 1, 0);
            }
    
            void update(int index, int delta) {
                for (++index; index <= n; index += index & -index)
                    tree[index] += delta;
            }
    
            int query(int index) {
                int res = 0;
                for (++index; index > 0; index -= index & -index)
                    res += tree[index];
                return res;
            }
        };
    
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            vector<int> pos(n);
            for (int i = 0; i < n; ++i)
                pos[nums2[i]] = i;
    
            vector<int> mapped(n);
            for (int i = 0; i < n; ++i)
                mapped[i] = pos[nums1[i]];
    
            FenwickTree left(n), right(n);
    
            for (int i = 0; i < n; ++i)
                right.update(mapped[i], 1);
    
            long long count = 0;
            for (int i = 0; i < n; ++i) {
                right.update(mapped[i], -1);
                int lessLeft = left.query(mapped[i] - 1);
                int greaterRight = right.query(n - 1) - right.query(mapped[i]);
                count += 1LL * lessLeft * greaterRight;
                left.update(mapped[i], 1);
            }
    
            return count;
        }
    };
    