class Solution {
public:
    int numberOfSubstrings(std::string s) {
        std::vector<int> last_pos(3, -1);
        int count = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            last_pos[s[i] - 'a'] = i;
            if (last_pos[0] != -1 && last_pos[1] != -1 && last_pos[2] != -1) {
                count += std::min({last_pos[0], last_pos[1], last_pos[2]}) + 1;
            }
        }
        
        return count;
    }
};
