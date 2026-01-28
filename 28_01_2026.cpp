class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const long long INF = 1e15;

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k + 1, INF)));
        dp[0][0][0] = 0;

        for (int p = 0; p <= k; ++p) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) dp[i][j][p] = min(dp[i][j][p], dp[i-1][j][p] + grid[i][j]);
                    if (j > 0) dp[i][j][p] = min(dp[i][j][p], dp[i][j-1][p] + grid[i][j]);
                }
            }

            if (p < k) {
                vector<long long> minCostForVal(10001, INF);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[i][j][p] != INF) {
                            minCostForVal[grid[i][j]] = min(minCostForVal[grid[i][j]], dp[i][j][p]);
                        }
                    }
                }

                vector<long long> bestMin(10002, INF);
                for (int v = 10000; v >= 0; --v) {
                    bestMin[v] = min(bestMin[v + 1], minCostForVal[v]);
                }

                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        dp[i][j][p+1] = min(dp[i][j][p+1], bestMin[grid[i][j]]);
                    }
                }
            }
        }

        long long result = INF;
        for (int p = 0; p <= k; ++p) {
            result = min(result, dp[m-1][n-1][p]);
        }

        return (result >= INF) ? -1 : (int)result;
    }
};
