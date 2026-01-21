/*
 * LOGIC EXPLANATION:
 * 1. Bitwise Pattern: The operation x | (x + 1) changes the rightmost 0-bit 
 * to a 1. To find the minimum 'x' that results in 'nums[i]', we must flip 
 * one of the trailing 1-bits in 'nums[i]' back to 0.
 * 2. Minimization: To make 'x' as small as possible, we flip the most 
 * significant bit of the rightmost block of contiguous 1s.
 * 3. Even Numbers: If nums[i] is even, no such 'x' exists because x | (x + 1) 
 * is always odd. Since nums[i] are primes, this only applies to 2.
 * 4. Algorithm: Find the first 0-bit after the rightmost block of 1s and 
 * flip the 1-bit immediately to its right.
 */

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);

        for (int i = 0; i < n; i++) {
           
            if (nums[i] == 2) {
                ans[i] = -1;
                continue;
            }

           
            for (int b = 0; b < 31; b++) {
               
                if (((nums[i] >> b) & 1) && !((nums[i] >> (b + 1)) & 1)) {
                    ans[i] = nums[i] ^ (1 << b);
                    break;
                }
            }
        }

        return ans;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(n * 31) ≈ O(n), where n is the length of nums.
 * - Space Complexity: O(1) auxiliary space (excluding the output array).
 */
