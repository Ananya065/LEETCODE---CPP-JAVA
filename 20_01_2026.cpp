/*
 * LOGIC EXPLANATION:
 * 1. Bitwise Pattern: The operation x | (x + 1) fills the rightmost 0-bit of x 
 * with a 1. To get nums[i], x must be nums[i] but with one of its 1-bits 
 * flipped to 0.
 * 2. Minimization: To minimize x, we find the highest bit in the rightmost 
 * block of 1s and flip it to 0.
 * 3. Strategy: We search for the first bit 'b' where the bit at 'b' is 1 
 * and the bit at 'b+1' is 0. This is the "top" of the rightmost 1-sequence.
 * 4. Even Numbers: Even numbers cannot satisfy the condition because x | (x+1) 
 * always results in an odd number.
 */

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[i] = -1;
            } else {
                for (int b = 0; b < 31; b++) {
                    if (((nums[i] >> b) & 1) && !((nums[i] >> (b + 1)) & 1)) {
                        ans[i] = nums[i] ^ (1 << b);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
