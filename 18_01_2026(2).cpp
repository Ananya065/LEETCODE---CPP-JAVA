/*
 * LOGIC EXPLANATION:
 * 1. Prefix Sums: To quickly calculate the sum of any row or column segment, 
 * we precompute 2D prefix sums for rows and columns.
 * 2. Search Strategy: We try every possible side length 'k' starting from the 
 * largest possible value (min(m, n)) down to 2.
 * 3. Sliding Window: For a fixed 'k', we slide a k x k window over the grid.
 * 4. Validation: For each window, we check:
 * - If all row sums equal the first row's sum.
 * - If all column sums equal that same sum.
 * - If both main and anti-diagonals equal that same sum.
 * 5. Return: The first 'k' that satisfies all conditions is the largest.
 */

class Solution {
public:
    int largestMagicSquare(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
       
        std::vector<std::vector<int>> rowSum(m, std::vector<int>(n + 1, 0));
        std::vector<std::vector<int>> colSum(n, std::vector<int>(m + 1, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[j][i + 1] = colSum[j][i] + grid[i][j];
            }
        }
        
        auto check = [&](int r, int c, int k) {
            int target = rowSum[r][c + k] - rowSum[r][c];
            
           
            for (int i = r + 1; i < r + k; ++i) {
                if (rowSum[i][c + k] - rowSum[i][c] != target) return false;
            }
        
            for (int j = c; j < c + k; ++j) {
                if (colSum[j][r + k] - colSum[j][r] != target) return false;
            }
      
            int diag1 = 0;
            for (int i = 0; i < k; ++i) diag1 += grid[r + i][c + i];
            if (diag1 != target) return false;
            
        
            int diag2 = 0;
            for (int i = 0; i < k; ++i) diag2 += grid[r + i][c + k - 1 - i];
            return diag2 == target;
        };

        for (int k = std::min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    if (check(i, j, k)) return k;
                }
            }
        }
        
        return 1;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(m * n * min(m, n)^2) - We check windows of various sizes.
 * - Space Complexity: O(m * n) - For storing row and column prefix sums.
 */
