class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> rows;

        for (auto &x : reservedSeats)
            rows[x[0]].insert(x[1]);

        long long ans = (long long)(n - rows.size()) * 2;

        for (auto &[row, seats] : rows) {
            bool left = true, middle = true, right = true;

            for (int s = 2; s <= 5; s++)
                if (seats.count(s)) left = false;

            for (int s = 4; s <= 7; s++)
                if (seats.count(s)) middle = false;

            for (int s = 6; s <= 9; s++)
                if (seats.count(s)) right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};