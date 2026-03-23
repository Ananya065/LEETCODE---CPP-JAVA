#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMin[i][0] = dpMax[i - 1][0] * grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
                    dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
                } else {
                    dpMax[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) * grid[i][j];
                    dpMin[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) * grid[i][j];
                }
            }
        }

        long long res = dpMax[m - 1][n - 1];
        return res < 0 ? -1 : res % MOD;
    }
};
