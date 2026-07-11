class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        std::vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertexCount = 0;
                int totalDegree = 0;
                std::queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    vertexCount++;
                    totalDegree += degree[curr];

                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                if (totalDegree == vertexCount * (vertexCount - 1)) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};