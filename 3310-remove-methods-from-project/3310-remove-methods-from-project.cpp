class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
   
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        vector<bool> is_suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        is_suspicious[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!is_suspicious[v]) {
                    is_suspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
      
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            
            if (!is_suspicious[u] && is_suspicious[v]) {
    
                vector<int> all_methods(n);
                iota(all_methods.begin(), all_methods.end(), 0);
                return all_methods;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!is_suspicious[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};