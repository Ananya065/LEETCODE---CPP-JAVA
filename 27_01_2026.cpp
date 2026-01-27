/*
 * LOGIC EXPLANATION:
 * 1. Independent Switches: The switch at node 'u' only affects the move 
 * originating FROM 'u'. Once you arrive at a new node 'v', the fact that 
 * you used a switch at 'u' does not restrict your ability to use one at 'v'.
 * 2. State Reduction: Since each switch is local and can only be used 
 * "immediately," we don't need a global bitmask. A simple dist[n] array 
 * suffices for Dijkstra.
 * 3. Immediate Traversal: If we are at 'u', we can take a normal edge 
 * u -> v (cost w) OR use the switch for an incoming edge v -> u 
 * and immediately move u -> v (cost 2w).
 */

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> rev_adj(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            rev_adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> min_dist(n, -1);

        pq.push({0, 0});
        min_dist[0] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (u == n - 1) return d;
            if (min_dist[u] != -1 && d > min_dist[u]) continue;

          
            for (auto& [v, w] : adj[u]) {
                if (min_dist[v] == -1 || d + w < min_dist[v]) {
                    min_dist[v] = d + w;
                    pq.push({min_dist[v], v});
                }
            }

            
            for (auto& [v, w] : rev_adj[u]) {
                if (min_dist[v] == -1 || d + 2LL * w < min_dist[v]) {
                    min_dist[v] = d + 2LL * w;
                    pq.push({min_dist[v], v});
                }
            }
        }

        return min_dist[n - 1];
    }
};
