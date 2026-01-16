/*
 * LOGIC EXPLANATION :
 * 1. Boundary Inclusion: Sabse pehle field ki boundaries (1, m aur 1, n) ko fences 
 * ki list mein daalna hoga, kyunki unhe hata nahi sakte.
 * 2. Possible Gaps: Do horizontal fences ke beech ka har possible distance 
 * nikal kar ek HashSet mein store kar lo.
 * 3. Square Search: Ab vertical fences ke beech ka distance nikalo. Agar wahi 
 * distance horizontal set mein bhi mil gaya, toh woh ek valid square side hai.
 * 4. Maximize: Sabse badi side ka area calculate karo aur modulo apply karo.
 *
 * DATA TYPES USED:
 * - std::unordered_set<int>: Horizontal distances ko store karne ke liye (fast lookup).
 * - long long: Calculation ke waqt overflow se bachne ke liye side aur area ko long long rakha.
 * - int: Final result return karne ke liye.
 */

class Solution {
public:
    int maximizeSquareArea(int m, int n, std::vector<int>& hFences, std::vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        std::sort(hFences.begin(), hFences.end());
        std::sort(vFences.begin(), vFences.end());

        std::unordered_set<int> hGaps;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                int gap = vFences[j] - vFences[i];
                if (hGaps.find(gap) != hGaps.end()) {
                    maxSide = std::max(maxSide, (long long)gap);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % 1000000007;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(H^2 + V^2) - Jahan H aur V fences ki count hai. 
 * Hum saare pairs check kar rahe hain.
 * - Space Complexity: O(H^2) - Saare horizontal distances ko set mein rakhne ke liye.
 *
 * Note: Agar constraints bahut zyada hote, toh hum isse aur optimize karte, 
 * par current constraints ke liye O(N^2) approach ekdum fine hai.
 */
