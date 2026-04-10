class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        bool found = false;

        for (auto const& [val, idxs] : positions) {
            if (idxs.size() < 3) continue;

            for (int i = 0; i <= (int)idxs.size() - 3; ++i) {
                int current_dist = 2 * (idxs[i + 2] - idxs[i]);
                if (current_dist < ans) {
                    ans = current_dist;
                    found = true;
                }
            }
        }

        return found ? ans : -1;
    }
};
