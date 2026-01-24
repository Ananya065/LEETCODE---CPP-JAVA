/*
 * LOGIC EXPLANATION:
 * 1. Greedy Strategy: To minimize the maximum sum, we must balance the pairs. 
 * This is best achieved by pairing the smallest available number with the 
 * largest available number.
 * 2. Sorting: We sort the array first to easily access the extremes.
 * 3. Two-Pointer Technique: We use one pointer at the start (smallest) and 
 * one at the end (largest), moving toward the center.
 * 4. Result: The answer is the maximum sum encountered among all these pairs.
 */

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int max_sum = 0;

        
        for (int i = 0; i < n / 2; ++i) {
            int current_pair_sum = nums[i] + nums[n - 1 - i];
            max_sum = std::max(max_sum, current_pair_sum);
        }

        return max_sum;
    }
};
