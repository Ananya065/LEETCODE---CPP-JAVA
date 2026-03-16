class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> uniqueSums;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                uniqueSums.insert(grid[r][c]);

                for (int s = 1; r - s >= 0 && r + s < m && c - s >= 0 && c + s < n; ++s) {
                    int currentSum = 0;
                    
                    currentSum += grid[r - s][c];
                    currentSum += grid[r + s][c];
                    currentSum += grid[r][c - s];
                    currentSum += grid[r][c + s];

                    for (int i = 1; i < s; ++i) {
                        currentSum += grid[r - s + i][c + i]; 
                        currentSum += grid[r + i][c + s - i]; 
                        currentSum += grid[r + s - i][c - i]; 
                        currentSum += grid[r - i][c - s + i]; 
                    }
                    
                    uniqueSums.insert(currentSum);
                    if (uniqueSums.size() > 3) {
                        auto it = uniqueSums.begin();
                        if (uniqueSums.size() > 3) uniqueSums.erase(uniqueSums.begin());
                    }
                }
            }
        }

        vector<int> result(uniqueSums.rbegin(), uniqueSums.rend());
        if (result.size() > 3) result.resize(3);
        return result;
    }
};
