class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);

        vector<int> min_prime(max_val + 1, 0);
        for (int i = 2; i <= max_val; ++i) {
            if (min_prime[i] == 0) {
                for (int j = i; j <= max_val; j += i) {
                    if (min_prime[j] == 0) min_prime[j] = i;
                }
            }
        }

        vector<vector<int>> val_to_idx(max_val + 1);
        for (int i = 0; i < n; ++i) {
            val_to_idx[nums[i]].push_back(i);
        }

        vector<vector<int>> prime_to_indices(max_val + 1);
        for (int v = 1; v <= max_val; ++v) {
            if (val_to_idx[v].empty()) continue;
            int temp = v;
            while (temp > 1) {
                int p = min_prime[temp];
                prime_to_indices[p].push_back(v);
                while (temp % p == 0) temp /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> prime_used(max_val + 1, false);
        vector<bool> val_used(max_val + 1, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return dist[curr];

            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }

            int val = nums[curr];
            bool is_prime = (val > 1 && min_prime[val] == val);

            if (is_prime && !prime_used[val]) {
                prime_used[val] = true;
                for (int multiple = val; multiple <= max_val; multiple += val) {
                    if (!val_used[multiple]) {
                        val_used[multiple] = true;
                        for (int idx : val_to_idx[multiple]) {
                            if (dist[idx] == -1) {
                                dist[idx] = dist[curr] + 1;
                                q.push(idx);
                            }
                        }
                    }
                }
            }
            
            int temp = val;
            while (temp > 1) {
                int p = min_prime[temp];
                if (!prime_used[p]) {
          }
                while (temp % p == 0) temp /= p;
            }
        }

        return -1;
    }
};
