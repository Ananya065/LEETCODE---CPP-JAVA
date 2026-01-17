/*
 * LOGIC EXPLANATION:
 * 1. Dual Pointer Strategy: We use two pointers, 'i' (the Slow Pointer) and 'j' (the Fast Explorer).
 * 2. Identifying Uniqueness: Since the array is sorted, duplicates are always adjacent. 
 * We only care when nums[j] is different from nums[i].
 * 3. In-Place Overwriting: Whenever a new unique element is found at 'j', we move 
 * the 'i' pointer forward and overwrite the value at that position with nums[j].
 * 4. Result: The first 'i + 1' elements will now consist of only unique values 
 * in their original sorted order.
 *
 * DATA TYPES USED:
 * - int: For indexing and returning the count 'k'.
 * - std::vector<int>&: Passed by reference to modify the original array in-place.
 */

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(n) because we iterate through the array exactly once.
 * - Space Complexity: O(1) as we perform the operation in-place without 
 * using extra data structures like sets or temporary arrays.
 */
