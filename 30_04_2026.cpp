class Solution {
public:
   
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
       
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        dp[0][0][0] = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cellVal = grid[i][j];
                int currentScore = (cellVal == 1) ? 1 : (cellVal == 2 ? 2 : 0);
                int currentCost = (cellVal == 0) ? 0 : 1;
                
                for (int c = currentCost; c <= k; ++c) {
                    int prevMax = -1;
                    
                    if (i > 0) prevMax = max(prevMax, dp[i-1][j][c - currentCost]);
                    if (j > 0) prevMax = max(prevMax, dp[i][j-1][c - currentCost]);
                    
                    if (prevMax != -1) {
                        dp[i][j][c] = max(dp[i][j][c], prevMax + currentScore);
                    }
                }
            }
        }
        
        int result = -1;
        for (int c = 0; c <= k; ++c) {
            result = max(result, dp[m-1][n-1][c]);
        }
        
        return result;
    }
};
