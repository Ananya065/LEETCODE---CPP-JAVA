#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct DSU {
        vector<int> parent;
        int count;
        DSU(int n) : count(n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                count--;
                return true;
            }
            return false;
        }
    };

public:
    bool check(int n, vector<vector<int>>& edges, int k, int mid) {
        DSU dsu(n);
        int edgesCount = 0;
        int mustCount = 0;
        int totalMust = 0;

        // 1. First, validate and add ALL must-include edges
        for (const auto& e : edges) {
            if (e[3] == 1) {
                totalMust++;
                if (e[2] < mid) return false; // Must edge fails stability
                if (dsu.unite(e[0], e[1])) {
                    mustCount++;
                }
            }
        }
        
     
        if (mustCount != totalMust || mustCount > n - 1) return false;

        // 2. Add optional edges that don't need upgrades
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    mustCount++;
                }
            }
        }

   
        int upgradesUsed = 0;
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && e[2] * 2 >= mid) {
                if (upgradesUsed < k && dsu.find(e[0]) != dsu.find(e[1])) {
                    dsu.unite(e[0], e[1]);
                    mustCount++;
                    upgradesUsed++;
                }
            }
        }

        return dsu.count == 1 && mustCount == n - 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 0, high = 2000000000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
