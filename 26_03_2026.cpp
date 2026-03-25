class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        vector<long long> rowSums(m, 0);
        vector<long long> colSums(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
                totalSum += grid[i][j];
            }
        }

        if (totalSum % 2 != 0) return false;
        long long target = totalSum / 2;

        long long currentHorizontalSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            currentHorizontalSum += rowSums[i];
            if (currentHorizontalSum == target) return true;
        }

        long long currentVerticalSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            currentVerticalSum += colSums[j];
            if (currentVerticalSum == target) return true;
        }

        return false;
    }
};
