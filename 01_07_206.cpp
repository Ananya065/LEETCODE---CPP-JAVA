class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        priority_queue<pair<int, pair<int, int>>> max_heap;
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));
        
        max_heap.push({dist[0][0], {0, 0}});
        max_safeness[0][0] = dist[0][0];
        
        while (!max_heap.empty()) {
            auto [current_safeness, cell] = max_heap.top();
            auto [r, c] = cell;
            max_heap.pop();
            
            if (r == n - 1 && c == n - 1) {
                return current_safeness;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int path_safeness = min(current_safeness, dist[nr][nc]);
                    
                    if (path_safeness > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = path_safeness;
                        max_heap.push({path_safeness, {nr, nc}});
                    }
                }
            }
        }
        
        return 0;
    }
};
