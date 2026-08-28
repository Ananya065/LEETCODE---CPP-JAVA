class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_cnt = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                odd_char = i;
            }
        }

        if (odd_cnt > 1) return "";

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int half_len = n / 2;
        string target_half = target.substr(0, half_len);

        vector<int> cur_cnt = half_count;
        bool valid_exact = true;
        for (int j = 0; j < half_len; ++j) {
            if (--cur_cnt[target_half[j] - 'a'] < 0) {
                valid_exact = false;
                break;
            }
        }

        if (valid_exact) {
            string exact_pal = target_half;
            if (n % 2 != 0) {
                exact_pal += (char)('a' + odd_char);
            }
            string rev = target_half;
            reverse(rev.begin(), rev.end());
            exact_pal += rev;

            if (exact_pal > target) {
                return exact_pal;
            }
        }

        for (int i = half_len - 1; i >= 0; --i) {
            cur_cnt = half_count;
            bool possible = true;

            for (int j = 0; j < i; ++j) {
                if (--cur_cnt[target_half[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            for (int c = target_half[i] - 'a' + 1; c < 26; ++c) {
                if (cur_cnt[c] > 0) {
                    string res_half = target_half.substr(0, i);
                    res_half += (char)('a' + c);
                    cur_cnt[c]--;

                    for (int ch = 0; ch < 26; ++ch) {
                        while (cur_cnt[ch] > 0) {
                            res_half += (char)('a' + ch);
                            cur_cnt[ch]--;
                        }
                    }

                    string full_res = res_half;
                    if (n % 2 != 0) {
                        full_res += (char)('a' + odd_char);
                    }
                    string rev = res_half;
                    reverse(rev.begin(), rev.end());
                    full_res += rev;

                    return full_res;
                }
            }
        }

        return "";
    }
};