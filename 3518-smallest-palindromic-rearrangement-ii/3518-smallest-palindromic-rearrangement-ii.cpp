class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int half_len = n / 2;
        
        vector<int> half_freq(26, 0);
        for (int i = 0; i < half_len; ++i) {
            half_freq[s[i] - 'a']++;
        }
        
        char mid_char = 0;
        if (n % 2 == 1) {
            mid_char = s[half_len];
        }
        
        long long INF = k + 7;
        
        auto countMultisetPermutations = [&](const vector<int>& f, int len) -> long long {
            long long res = 1;
            int rem = len;
            for (int c = 0; c < 26; ++c) {
                int cnt = f[c];
                if (cnt > 0) {
                    if (cnt > rem) return 0;
                    
                    int k_val = min(cnt, rem - cnt);
                    long long comb = 1;
                    for (int i = 1; i <= k_val; ++i) {
                        comb = comb * (rem - i + 1) / i;
                        if (comb > INF) {
                            comb = INF;
                            break;
                        }
                    }
                    
                    if (comb == 0) return 0;
                    if (res > INF / comb) return INF;
                    res = min(INF, res * comb);
                    rem -= cnt;
                }
            }
            return res;
        };
        
        long long total_perms = countMultisetPermutations(half_freq, half_len);
        if ((long long)k > total_perms) return "";
        
        string left_half = "";
        int rem_len = half_len;
        long long target_k = k;
        
        for (int pos = 0; pos < half_len; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] > 0) {
                    half_freq[c]--;
                    long long count = countMultisetPermutations(half_freq, rem_len - 1);
                    
                    if (target_k <= count) {
                        left_half += (char)('a' + c);
                        rem_len--;
                        break;
                    } else {
                        target_k -= count;
                        half_freq[c]++;
                    }
                }
            }
        }
        
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        if (mid_char != 0) {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};