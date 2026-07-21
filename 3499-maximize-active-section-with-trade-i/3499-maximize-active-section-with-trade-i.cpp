class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int m = t.length();
        
        int base_ones = 0;
        for (char c : s) {
            if (c == '1') base_ones++;
        }
        
        vector<pair<int, int>> ones;
        vector<pair<int, int>> zeros;
        
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            if (t[i] == '1') {
                ones.push_back({i, j - 1});
            } else {
                zeros.push_back({i, j - 1});
            }
            i = j;
        }
        
        int max_gain = 0;
        for (size_t i = 1; i + 1 < ones.size(); ++i) {
            int z_left = zeros[i - 1].second - zeros[i - 1].first + 1;
            int z_right = zeros[i].second - zeros[i].first + 1;
            max_gain = max(max_gain, z_left + z_right);
        }
        
        return base_ones + max_gain;
    }
};