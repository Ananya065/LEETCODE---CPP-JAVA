/*
 * LOGIC EXPLANATION:
 * 1. Sorting: To minimize the difference between the max and min of k elements, 
 * those elements should be as close to each other as possible in value. 
 * Sorting the array brings close values together.
 * 2. Sliding Window: Once sorted, any k contiguous elements represent a 
 * potential selection. The difference is simply (nums[i + k - 1] - nums[i]).
 * 3. Comparison: We slide a window of size k across the sorted array and 
 * keep track of the minimum difference found.
 */

class Solution {
public:
    int minimumDifference(std::vector<int>& nums, int k) {
        if (k == 1) return 0;

        
        std::sort(nums.begin(), nums.end());

        int min_diff = 1e9; 

        for (int i = 0; i <= (int)nums.size() - k; ++i) {
            int current_diff = nums[i + k - 1] - nums[i];
            min_diff = std::min(min_diff, current_diff);
        }

        return min_diff;
    }
};
