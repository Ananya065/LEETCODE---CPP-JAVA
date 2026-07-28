class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half = n / 2;
        
        string left_half = s.substr(0, half);
        sort(left_half.begin(), left_half.end());
        
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        if (n % 2 == 1) {
            return left_half + s[half] + right_half;
        } else {
            return left_half + right_half;
        }
    }
};