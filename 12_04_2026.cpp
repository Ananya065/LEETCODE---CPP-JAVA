class Solution {
    int memo[301][27]; 
    int getDist(int a, int b) {
        if (a == 26) return 0; 
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int idx, int other, const string& word) {
        if (idx == word.length()) return 0;
        if (memo[idx][other] != -1) return memo[idx][other];

        int curr = word[idx] - 'A';
        int prev = word[idx - 1] - 'A';


        int moveSame = solve(idx + 1, other, word) + getDist(prev, curr);

        int moveOther = solve(idx + 1, prev, word) + getDist(other, curr);

        return memo[idx][other] = min(moveSame, moveOther);
    }

public:
    int minimumDistance(string word) {
        memset(memo, -1, sizeof(memo));
    
        return solve(1, 26, word);
    }
};
