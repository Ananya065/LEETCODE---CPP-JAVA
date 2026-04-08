class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            int ki = query[2];
            long long vi = query[3];

            for (int idx = li; idx <= ri; idx += ki) {
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }

        int xorSum = 0;
        for (int val : nums) {
            xorSum ^= val;
        }

        return xorSum;
    }
};
