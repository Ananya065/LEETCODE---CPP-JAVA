class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        
        int n = grid.size();
        int m = grid[0].size();
        int k = n * m;
        
        vector<long long> arr;
        arr.reserve(k);
        
        for (auto &row : grid) {
            for (auto &x : row) {
                arr.push_back(x % MOD);
            }
        }
        
        vector<long long> prefix(k, 1), suffix(k, 1);
        
        for (int i = 1; i < k; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;
        }
        
        for (int i = k - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;
        }
        
        vector<vector<int>> result(n, vector<int>(m));
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = (prefix[idx] * suffix[idx]) % MOD;
                idx++;
            }
        }
        
        return result;
    }
};
