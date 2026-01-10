/**
 * Title: 712. Minimum ASCII Delete Sum for Two Strings
 * Link:https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10
 * Difficulty: Medium
 * Time Complexity: O(N * M)
 * Space Complexity: O(M)
 */

class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[] prev = new int[m + 1];

        
        for (int j = 1; j <= m; j++) {
            prev[j] = prev[j - 1] + s2.charAt(j - 1);
        }

        for (int i = 1; i <= n; i++) {
            int[] curr = new int[m + 1];
            curr[0] = prev[0] + s1.charAt(i - 1); 
            for (int j = 1; j <= m; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                   
                    curr[j] = prev[j - 1];
                } else {
                  
                    curr[j] = Math.min(prev[j] + s1.charAt(i - 1), 
                                       curr[j - 1] + s2.charAt(j - 1));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
}

/*
problem statement:
I have two strings. To make them equal, I have to delete characters. Each character has a "price" (its ASCII value). I want to find the lowest possible total price to pay to make the strings match.

how i approached this problem:
I treated this like a cost-analysis problem. If the characters at the current position match, the cost is 0. If they don't, I have to decide whether it's cheaper to pay the "ASCII tax" for the character in string 1 or string 2. I used an array instead of a full grid to save memory, just like in the C++ version.



SUMMARY:

data structure: 
1D int arrays (prev and curr) representing rows of a DP table.

optimization:
Space Complexity reduced to O(M). By only keeping the current and previous rows, we save a lot of memory compared to a full O(N*M) matrix.

concept use:
Dynamic Programming (Tabulation). We calculate the minimum cost for smaller substrings and use those results to build up to the final answer.

*/
