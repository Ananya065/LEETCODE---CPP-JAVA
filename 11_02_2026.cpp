#include <vector>
#include <algorithm>
#include <vector>

class Solution {
public:
    int longestBalanced(std::vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {

            std::vector<bool> seenEven(100001, false);
            std::vector<bool> seenOdd(100001, false);
            int distinctEven = 0;
            int distinctOdd = 0;

            for (int j = i; j < n; ++j) {
                int val = nums[j];
                if (val % 2 == 0) {
                    if (!seenEven[val]) {
                        seenEven[val] = true;
                        distinctEven++;
                    }
                } else {
                    if (!seenOdd[val]) {
                        seenOdd[val] = true;
                        distinctOdd++;
                    }
                }

        
                if (distinctEven == distinctOdd) {
                    maxLen = std::max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
