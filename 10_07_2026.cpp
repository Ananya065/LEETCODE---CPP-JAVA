#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = {nums[i], i};
        }
        sort(nodes.begin(), nodes.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nodes[i].second] = i;
        }
        
        vector<int> comp(n, 0);
        int comp_id = 0;
        for (int i = 1; i < n; ++i) {
            if (nodes[i].first - nodes[i - 1].first > maxDiff) {
                comp_id++;
            }
            comp[i] = comp_id;
        }
        
        int max_log = log2(n) + 1;
        vector<vector<int>> next_right(n, vector<int>(max_log, 0));
        
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(nodes.begin(), nodes.end(), make_pair(nodes[i].first + maxDiff, (int)2e9));
            int j = distance(nodes.begin(), it) - 1;
            next_right[i][0] = j;
        }
        
        for (int k = 1; k < max_log; ++k) {
            for (int i = 0; i < n; ++i) {
                next_right[i][k] = next_right[next_right[i][k - 1]][k - 1];
            }
        }
        
        vector<int> ans;
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (nums[u] == nums[v]) {
                ans.push_back(1);
                continue;
            }
            
            int p1 = pos[u], p2 = pos[v];
            if (p1 > p2) swap(p1, p2);
            
            if (comp[p1] != comp[p2]) {
                ans.push_back(-1);
                continue;
            }
            
            int steps = 0;
            int curr = p1;
            for (int k = max_log - 1; k >= 0; --k) {
                if (next_right[curr][k] < p2) {
                    steps += (1 << k);
                    curr = next_right[curr][k];
                }
            }
            steps += 1;
            ans.push_back(steps);
        }
        
        return ans;
    }
};
