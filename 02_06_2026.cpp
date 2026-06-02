class Solution {
public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, 
                           std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart1 = std::max(landFinish, waterStartTime[j]);
                int totalTime1 = waterStart1 + waterDuration[j];
                
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart2 = std::max(waterFinish, landStartTime[i]);
                int totalTime2 = landStart2 + landDuration[i];
                
                minFinishTime = std::min({minFinishTime, totalTime1, totalTime2});
            }
        }
        
        return minFinishTime;
    }
};
