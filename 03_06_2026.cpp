class Solution {
private:
    int solveOrder(const vector<int>& startA, const vector<int>& durA, const vector<int>& startB, const vector<int>& durB) {
        int minFinishA = INT_MAX;
        for (size_t i = 0; i < startA.size(); ++i) {
            minFinishA = min(minFinishA, startA[i] + durA[i]);
        }

        int minFinishB = INT_MAX;
        for (size_t j = 0; j < startB.size(); ++j) {
            int finishB = max(startB[j], minFinishA) + durB[j];
            minFinishB = min(minFinishB, finishB);
        }

        return minFinishB;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1 = solveOrder(landStartTime, landDuration, waterStartTime, waterDuration);
        int ans2 = solveOrder(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(ans1, ans2);
    }
};
