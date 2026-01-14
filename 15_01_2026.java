/**
 * Title: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Time Complexity: O(n)
 * Space Complexity: O(1) - Fixed size array (128 for ASCII)
 */

import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLength = 0;
        int[] lastIndex = new int[128];
        Arrays.fill(lastIndex, -1);
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            char curr = s.charAt(right);
            
            if (lastIndex[curr] >= left) {
                left = lastIndex[curr] + 1;
            }
            
            lastIndex[curr] = right;
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}

/*
SUMMARY:
- Logic: Used a Sliding Window with two pointers (left and right).
- Optimization: Replaced HashMap with an int[128] array to map ASCII 
  characters to their last seen index, significantly reducing overhead.
- Complexity: O(n) time as each character is visited once; O(1) space.
*/
