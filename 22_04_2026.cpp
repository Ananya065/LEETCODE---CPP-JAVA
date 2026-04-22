class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (const string& q : queries) {
            bool found = false;
            for (const string& d : dictionary) {
                int edits = 0;
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        edits++;
                    }
                    if (edits > 2) break;
                }

                if (edits <= 2) {
                    found = true;
                    break;
                }
            }
            if (found) {
                result.push_back(q);
            }
        }

        return result;
    }
};
