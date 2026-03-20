class Solution {
public:
    vector<vector<int>> minAbsoluteDifference(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            map<int, int> window;
            
        
            for (int r = i; r < i + k; ++r) {
                for (int c = 0; c < k; ++c) {
                    window[grid[r][c]]++;
                }
            }
            ans[i][0] = calculateMinDiff(window);

     
            for (int j = 1; j <= n - k; ++j) {
                // Remove leftmost column of previous window
                for (int r = i; r < i + k; ++r) {
                    if (--window[grid[r][j - 1]] == 0) {
                        window.erase(grid[r][j - 1]);
                    }
                }
       
                for (int r = i; r < i + k; ++r) {
                    window[grid[r][j + k - 1]]++;
                }
                ans[i][j] = calculateMinDiff(window);
            }
        }
        return ans;
    }

private:
    int calculateMinDiff(const map<int, int>& window) {
        if (window.size() < 2) return 0; // All elements same or only one element

        int minDiff = 2000000000; // Infinity
        auto it = window.begin();
        int prev = it->first;
        it++;

        for (; it != window.end(); ++it) {
            minDiff = min(minDiff, it->first - prev);
            if (minDiff == 1) return 1; // Early exit for smallest possible diff
            prev = it->first;
        }

        return minDiff;
    }
};
