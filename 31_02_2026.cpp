class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int totalLen = n + m - 1;
        string word(totalLen, '?');

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != '?' && word[i + j] != str2[j]) return "";
                    word[i + j] = str2[j];
                }
            }
        }

        for (int i = 0; i < totalLen; ++i) {
            if (word[i] == '?') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    bool ok = true;
                    for (int start = max(0, i - m + 1); start <= min(i, n - 1); ++start) {
                        if (str1[start] == 'F') {
                            bool full = true;
                            bool match = true;
                            for (int j = 0; j < m; ++j) {
                                if (word[start + j] == '?') {
                                    full = false;
                                    break;
                                }
                                if (word[start + j] != str2[j]) {
                                    match = false;
                                    break;
                                }
                            }
                            if (full && match) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) break;
                    if (c == 'z') return ""; 
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }
            if (str1[i] == 'T' && !match) return "";
            if (str1[i] == 'F' && match) return "";
        }

        return word;
    }
};
