class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> has_u(2048, false);
        vector<int> u;
        for (int x : nums) {
            if (!has_u[x]) {
                has_u[x] = true;
                u.push_back(x);
            }
        }

        vector<bool> has_s2(2048, false);
        vector<int> s2;
        for (int i = 0; i < u.size(); ++i) {
            for (int j = i; j < u.size(); ++j) {
                int val = u[i] ^ u[j];
                if (!has_s2[val]) {
                    has_s2[val] = true;
                    s2.push_back(val);
                }
            }
        }

        vector<bool> has_s3(2048, false);
        int ans = 0;
        for (int s : s2) {
            for (int c : u) {
                int val = s ^ c;
                if (!has_s3[val]) {
                    has_s3[val] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};