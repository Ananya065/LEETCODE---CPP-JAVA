class Solution {
struct Interval {
    long long l, r, weight;
    int id;
};

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {(long long)intervals[i][0], (long long)intervals[i][1], (long long)intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });

        vector<long long> R(n);
        for (int i = 0; i < n; ++i) {
            R[i] = arr[i].r;
        }

        
        vector<vector<pair<long long, vector<int>>>> dp(5, vector<pair<long long, vector<int>>>(n + 1, {0, {}}));

        for (int k = 1; k <= 4; ++k) {
            for (int i = 1; i <= n; ++i) {
                
                dp[k][i] = dp[k][i - 1];

               
                int l_val = arr[i - 1].l;
                // Binary search for last interval with r < l_val
                int p = lower_bound(R.begin(), R.begin() + i - 1, l_val) - R.begin();

                long long cand_weight = dp[k - 1][p].first + arr[i - 1].weight;
                vector<int> cand_indices = dp[k - 1][p].second;
                cand_indices.push_back(arr[i - 1].id);
                sort(cand_indices.begin(), cand_indices.end());

                if (cand_weight > dp[k][i].first) {
                    dp[k][i] = {cand_weight, cand_indices};
                } else if (cand_weight == dp[k][i].first && !cand_indices.empty()) {
                    if (dp[k][i].second.empty() || cand_indices < dp[k][i].second) {
                        dp[k][i] = {cand_weight, cand_indices};
                    }
                }
            }
        }

        long long max_w = 0;
        vector<int> best_indices = {};

        for (int k = 1; k <= 4; ++k) {
            if (dp[k][n].first > max_w) {
                max_w = dp[k][n].first;
                best_indices = dp[k][n].second;
            } else if (dp[k][n].first == max_w && !dp[k][n].second.empty()) {
                if (best_indices.empty() || dp[k][n].second < best_indices) {
                    best_indices = dp[k][n].second;
                }
            }
        }

        return best_indices;
    }
};
