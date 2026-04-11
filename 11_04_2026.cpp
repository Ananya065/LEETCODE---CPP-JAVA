class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        long long min_dist = -1;

        for (auto const& [val, indices] : pos) {
            if (indices.size() < 3) continue;

            for (int i = 0; i <= (int)indices.size() - 3; ++i) {
                long long current_dist = 2LL * (indices[i + 2] - indices[i]);
                
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
        }

        return (int)min_dist;
    }
};
