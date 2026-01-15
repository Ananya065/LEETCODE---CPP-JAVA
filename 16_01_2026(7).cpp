/*
 * LOGIC EXPLANATION :
 * 1. Sorting ka Khel: Pehle array ko alphabetical order mein sort kar lo. 
 * Isse sabse alag dikhne waale strings ends par aa jayenge.
 * 2. Sirf Do Ko Dekho: Ab sirf pehle (first) aur aakhri (last) string ko compare 
 * karo. Jo in dono mein common hoga, wahi poore group ka common prefix hoga.
 * 3. Match Karo: Ek-ek character check karo, jahan mismatch mila wahi ruk jao.
 *
 * DATA TYPES USED:
 * - vector<string>: Strings ka collection store karne ke liye.
 * - string: Result (prefix) banane ke liye.
 */

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
       
        std::sort(strs.begin(), strs.end());
        
        std::string first = strs[0];
        std::string last = strs[strs.size() - 1];
        std::string result = "";
        
        
        for (int i = 0; i < std::min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                return result;
            }
            result += first[i];
        }
        
        return result;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(N * L * logN) - Jahan N strings hain aur L length hai (sorting ki wajah se).
 * - Space Complexity: O(1) ya O(L) - Agar result string ki space count karein toh.
 *
 * Alternative: Hum "Vertical Scanning" bhi kar sakte hain (pehle character ko sabhi strings 
 * mein check karo), wo O(N * L) leta hai bina sorting ke.
 */
