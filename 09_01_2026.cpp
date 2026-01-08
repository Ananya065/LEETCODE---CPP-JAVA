/**
 * Title: 1458. Max Dot Product of Two Subsequences
 * Link:https://leetcode.com/problems/max-dot-product-of-two-subsequences/?envType=daily-question&envId=2026-01-08
 * Difficulty: Hard
 * Time Complexity: O(N*M)
 * Space Complexity: O(min(N, M))
 */

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
      
        if (n < m) return maxDotProduct(nums2, nums1);

       
        vector<int> prev(m + 1, -1e9);
        vector<int> curr(m + 1, -1e9);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int combo = nums1[i-1] * nums2[j-1];
                
              
                curr[j] = max({
                    combo, 
                    combo + prev[j-1], 
                    prev[j], 
                    curr[j-1]
                });
            }
            
            prev = curr;
        }
        return prev[m];
    }
};

/*
problem statement:
I have two lists of numbers. I need to pick equal-length subsequences from both and multiply the pairs together to get a "dot product" sum. The goal is to make that sum as big as possible. I can skip numbers if they don't help, but I can't change the order of the numbers I pick. Also, I have to pick at least one pair—no leaving with an empty hand!

how i approached this problem:
I realized that if I use a 2D table, I only ever look at the values from the row right above me. Keeping the whole table is like keeping an entire notebook when you only need the last page you wrote on. By just swapping two rows (prev and curr), I get the exact same answer but use way less memory. I also used -1e9 because if the arrays are full of negatives and positives that result in a negative product, I need a starting value that is even lower so the "best" negative number still wins.

SUMMARY:

data structure: 
Two 1D Vectors (prev and curr). They act as a rolling window of our DP table.

optimization:
Space Complexity. We moved from O(N * M) memory down to O(min(N, M)). This is the most efficient way to solve it.

concept use:
Space-Optimized Dynamic Programming (Tabulation). It’s the "final boss" version of DP where you save only what you absolutely need.

*/
