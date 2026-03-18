class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

      
        vector<vector<long long>> prefixSum(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long current = grid[i][j];
                
                if (i > 0) current += prefixSum[i - 1][j];
                if (j > 0) current += prefixSum[i][j - 1];
                if (i > 0 && j > 0) current -= prefixSum[i - 1][j - 1];

                prefixSum[i][j] = current;

                if (current <= k) {
                    count++;
                }
            }
        }

        return count;
    }
};
