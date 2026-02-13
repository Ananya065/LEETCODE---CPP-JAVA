#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

a
struct pair_hash {
    inline size_t operator()(const pair<int, int> & v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        vector<string> subsets = {"a", "b", "c", "ab", "ac", "bc", "abc"};

        for (const string& sub : subsets) {
            unordered_map<pair<int, int>, int, pair_hash> lookup;
            lookup[{0, 0}] = -1; 

            int counts[3] = {0, 0, 0};
            int last_invalid = -1;
            
            for (int i = 0; i < n; ++i) {
                if (sub.find(s[i]) == string::npos) {
                    lookup.clear();
                    lookup[{0, 0}] = i;
                    counts[0] = counts[1] = counts[2] = 0;
                    continue;
                }

                counts[s[i] - 'a']++;

                pair<int, int> state = {0, 0};
                if (sub.length() == 2) {
                    state.first = counts[sub[0] - 'a'] - counts[sub[1] - 'a'];
                } else if (sub.length() == 3) {
                    state.first = counts[0] - counts[1];
                    state.second = counts[1] - counts[2];
                }

                if (lookup.count(state)) {
                    max_len = max(max_len, i - lookup[state]);
                } else {
                    lookup[state] = i;
                }
            }
        }
        return max_len;
    }
};
