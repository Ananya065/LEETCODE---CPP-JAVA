class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, sum = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                curr++;
            } else {
                sum += std::min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        return sum + std::min(prev, curr);
    }
};
