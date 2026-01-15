/**
 * Title: Two Sum
 * Difficulty: Easy
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            
            map.put(nums[i], i);
        }
        
        return new int[] {};
    }
}

/*
SUMMARY:
- Strategy: One-pass Hash Map.
- Efficiency: Reduces time complexity from O(n^2) to O(n) by 
  trading space for speed.
- Requirement: Finds two indices that sum to the target value 
  without using the same element twice.
*/
