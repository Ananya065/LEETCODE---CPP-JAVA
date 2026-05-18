class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

       
        unordered_map<int, vector<int>> val_to_indices;
        for (int i = 0; i < n; ++i) {
            val_to_indices[arr[i]].push_back(i);
        }

     
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        int steps = 0;

       
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) return steps;

               
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                
                int val = arr[curr];
                if (val_to_indices.count(val)) {
                    for (int next_idx : val_to_indices[val]) {
                        if (!visited[next_idx]) {
                            visited[next_idx] = true;
                            q.push(next_idx);
                        }
                    }
      
                    val_to_indices.erase(val);
                }
            }
            steps++;
        }

        return -1;
    }
};
