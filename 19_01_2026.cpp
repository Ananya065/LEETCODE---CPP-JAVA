/*
 * LOGIC EXPLANATION:
 * 1. 2D Prefix Sum: We create a 'pref' matrix where pref[i][j] stores the sum of 
 * all elements from grid[0][0] to grid[i-1][j-1]. This allows us to calculate 
 * the sum of any square in O(1) time.
 * 2. Square Sum Formula: The sum of a square with top-left (r1, c1) and 
 * bottom-right (r2, c2) is: pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1].
 * 3. Binary Search: Since the side length 'k' is monotonic (if a square of size 
 * k works, size k-1 also works), we binary search for the largest 'k'.
 * 4. Optimization: Instead of Binary Search, we can also use a sliding window 
 * style increase of 'k' because we only care if a larger 'k' exists.
 *
 * DATA TYPES USED:
 * - std::vector<std::vector<int>>: For the grid and prefix sum matrix.
 * - int: For coordinates, side length, and the threshold.
 */

class Solution {
public:
    int maxSideLength(std::vector<std::vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<std::vector<int>> pref(m + 1, std::vector<int>(n + 1, 0));

        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        
        auto getSum = [&](int r, int c, int k) {
            return pref[r + k][c + k] - pref[r][c + k] - pref[r + k][c] + pref[r][c];
        };

        
        int low = 1, high = std::min(m, n), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool found = false;
            
            for (int i = 0; i <= m - mid; ++i) {
                for (int j = 0; j <= n - mid; ++j) {
                    if (getSum(i, j, mid) <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(M * N * log(min(M, N))) due to 2D prefix sum and binary search.
 * - Space Complexity: O(M * N) to store the prefix sum matrix.
 */
