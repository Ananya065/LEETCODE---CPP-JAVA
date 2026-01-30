#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    int strId = -1;
};

class Solution {
    TrieNode* root;
    int idCounter;
    set<int> validLengths;

    void insert(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        if (curr->strId == -1) curr->strId = idCounter++;
        validLengths.insert(s.length());
    }

    int getStrId(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c - 'a']) return -1;
            curr = curr->children[c - 'a'];
        }
        return curr->strId;
    }

public:
    long long minimumCost(string source, string target, 
                         vector<string>& original, vector<string>& changed, 
                         vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        root = new TrieNode();
        idCounter = 0;
        validLengths.clear();

        for (const auto& s : original) insert(s);
        for (const auto& s : changed) insert(s);

        int U = idCounter;
        const long long INF = 1e16;
        vector<vector<long long>> dist(U, vector<long long>(U, INF));

        for (int i = 0; i < U; ++i) dist[i][i] = 0;
        for (int i = 0; i < (int)original.size(); ++i) {
            int u = getStrId(original[i]);
            int v = getStrId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < U; ++k) {
            for (int i = 0; i < U; ++i) {
                if (dist[i][k] >= INF) continue;
                for (int j = 0; j < U; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        
        vector<int> lengths(validLengths.begin(), validLengths.end());

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int len : lengths) {
                if (i + len > n) break;
                
            
                TrieNode* nodeS = root;
                TrieNode* nodeT = root;
                bool match = true;
                for (int k = 0; k < len; ++k) {
                    nodeS = nodeS->children[source[i + k] - 'a'];
                    nodeT = nodeT->children[target[i + k] - 'a'];
                    if (!nodeS || !nodeT) {
                        match = false;
                        break;
                    }
                }

                if (match && nodeS->strId != -1 && nodeT->strId != -1) {
                    long long c = dist[nodeS->strId][nodeT->strId];
                    if (c < INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + c);
                    }
                }
            }
        }

        return (dp[n] >= INF) ? -1 : dp[n];
    }
};
