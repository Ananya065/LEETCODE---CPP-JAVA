/*
 * LOGIC EXPLANATION :
 * 1. Map ka Use: Pehle humne har Roman symbol ki value ek map mein store kar li.
 * 2. Reverse Reading: Hum string ko piche se (right to left) check karte hain.
 * 3. Add ya Subtract: 
 * - Agar current symbol ki value pichle waale se choti hai (jaise IV mein I, V se 
 * chota hai), toh use subtract kar do.
 * - Agar barabar ya badi hai, toh simply add kar do.
 *
 * DATA TYPES USED:
 * - unordered_map<char, int>: Roman characters aur unki values store karne ke liye.
 * - int: Total sum calculate karne ke liye.
 */

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int prevValue = 0;
        
  
        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = roman[s[i]];
            
            if (currValue < prevValue) {
                total -= currValue;
            } else {
                total += currValue;
            }
            
            prevValue = currValue;
        }
        
        return total;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(n) - Hum string ke har character ko ek baar visit karte hain.
 * - Space Complexity: O(1) - Map ka size fixed hai (sirf 7 symbols), toh space constant hai.
 *
 * Optimization Hint: Map ki jagah switch-case use karke performance thodi aur 
 * fast ki ja sakti hai kyunki map ka overhead nahi rahega.
 */
