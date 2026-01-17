/*
 * LOGIC EXPLANATION :
 * 1. Intersection Nikalo: Do rectangles (A aur B) ka overlap nikalne ke liye hum:
 * - Left boundary: max(A_left, B_left)
 * - Right boundary: min(A_right, B_right)
 * - Bottom boundary: max(A_bottom, B_bottom)
 * - Top boundary: min(A_top, B_top)
 * 2. Width aur Height: Agar (Right > Left) aur (Top > Bottom), tabhi intersection hoga.
 * 3. Square ki Side: Intersection ke andar jo sabse bada square banega, uski side 
 * hogi: min(width, height).
 * 4. Maximize: Hum har pair ko check karenge aur jo sabse bada square milega 
 * uska area (side * side) return kar denge.
 *
 * DATA TYPES USED:
 * - long long: Area bada ho sakta hai isliye calculations long long mein ki hain.
 * - std::vector<std::vector<int>>: Coordinates store karne ke liye.
 */

class Solution {
public:
    long long largestSquareArea(std::vector<std::vector<int>>& bottomLeft, std::vector<std::vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
           
                long long x_left = std::max(bottomLeft[i][0], bottomLeft[j][0]);
                int x_right = std::min(topRight[i][0], topRight[j][0]);
                int y_bottom = std::max(bottomLeft[i][1], bottomLeft[j][1]);
                int y_top = std::min(topRight[i][1], topRight[j][1]);

                if (x_left < x_right && y_bottom < y_top) {
                    long long width = x_right - x_left;
                    long long height = y_top - y_bottom;
                    
                    long long side = std::min(width, height);
                    maxSide = std::max(maxSide, side);
                }
            }
        }

        return maxSide * maxSide;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(n^2) - Saare rectangle pairs compare ho rahe hain.
 * - Space Complexity: O(1) - Sirf variables use kiye hain, koi extra storage nahi.
 */
