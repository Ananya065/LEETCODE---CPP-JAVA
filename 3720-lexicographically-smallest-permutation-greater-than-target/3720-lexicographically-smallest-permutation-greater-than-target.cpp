class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; --i) {
            vector<int> current_count = count;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                if (--current_count[target[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (current_count[c] > 0) {
                    string res = target.substr(0, i);
                    res += (char)('a' + c);
                    current_count[c]--;

                    for (int ch = 0; ch < 26; ++ch) {
                        while (current_count[ch] > 0) {
                            res += (char)('a' + ch);
                            current_count[ch]--;
                        }
                    }
                    return res;
                }
            }
        }

        return "";
    }
};