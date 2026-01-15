/*
 * LOGIC EXPLANATION :
 * 1. Stack ka Use: Hum brackets ko stack mein dalte hain. Jab koi closing bracket 
 * milta hai, toh hum check karte hain ki stack ke top par uska matching opening 
 * bracket hai ya nahi.
 * 2. Push & Pop:
 * - Agar '(', '{', ya '[' mile toh stack mein push kar do.
 * - Agar ')', '}', ya ']' mile toh check karo: kya stack khali hai? Ya top 
 * par galat bracket hai? Agar haan, toh false!
 * 3. Final Check: Saare characters ke baad agar stack khali hai, matlab sab 
 * brackets sahi se match ho gaye.
 *
 * DATA TYPES USED:
 * - std::stack<char>: Brackets ko temporary store karne ke liye (LIFO order).
 * - char: Individual characters ko process karne ke liye.
 */

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(n) - Humne puri string ko sirf ek baar scan kiya hai.
 * - Space Complexity: O(n) - Worst case mein (jaise "((((("), saare brackets 
 * stack mein store honge.
 *
 * Note: Map ka use karke code ko aur chota (clean) banaya ja sakta hai, 
 * par basic if-else approach performance mein thodi fast hoti hai.
 */
