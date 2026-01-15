/*
 * LOGIC EXPLANATION:
 * 1. Piche se shuru: Hum '%' operator use karke number ka aakhri digit nikalte hain.
 * 2. Reverse build: Naya number banane ke liye purane 'rev' ko 10 se multiply 
 * karke naya digit jod dete hain (rev * 10 + pop).
 * 3. Boundary Check: 32-bit int ki limit (2147483647) cross na ho, isliye hum 
 * har step pe check karte hain ki 'rev' limit ke bahar toh nahi ja raha.
 *
 * DATA TYPES USED:
 * - int: Sirf 32-bit signed integer use kiya hai as per constraints.
 * - INT_MAX/INT_MIN: Boundary check karne ke liye standard C++ constants.
 */

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(log10(x)) - Loop utni baar chalta hai jitne digits hain.
 * - Space Complexity: O(1) - Humne koi extra memory ya strings use nahi ki.
 *
 * Note: Agar hume long long use karne ki permission hoti, toh code aur chota 
 * ho jata, par interview mein aksar 32-bit constraint di jati hai.
 */
