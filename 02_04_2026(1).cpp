class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        long long INF = 1e16;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0]; 
            dp[0][0][1] = 0;           
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int k = 0; k < 3; ++k) {
                    if (dp[r][c][k] == -INF) continue;

                    int dr[] = {0, 1};
                    int dc[] = {1, 0};

                    for (int i = 0; i < 2; ++i) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if (nr < m && nc < n) {
                            int val = coins[nr][nc];
                            
                            if (val >= 0) {
                                dp[nr][nc][k] = max(dp[nr][nc][k], dp[r][c][k] + val);
                            } else {
                                dp[nr][nc][k] = max(dp[nr][nc][k], dp[r][c][k] + val);
                                
                                if (k + 1 < 3) {
                                    dp[nr][nc][k + 1] = max(dp[nr][nc][k + 1], dp[r][c][k]);
                                }
                            }
                        }
                    }
                }
            }
        }

        long long ans = -INF;
        for (int k = 0; k < 3; ++k) {
            ans = max(ans, dp[m - 1][n - 1][k]);
        }
        
        return (int)ans;
    }
};
