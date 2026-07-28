
class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count character frequencies
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string first_half = "";
        char mid = '\0';
        
        // Step 2: Build the first half in alphabetical order
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                char ch = 'a' + i;
                // If odd frequency, this character sits in the middle
                if (count[i] % 2 != 0) {
                    mid = ch;
                }
                // Append half of the characters to the first half
                first_half.append(count[i] / 2, ch);
            }
        }
        
        // Step 3: Mirror the first half to create the second half
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        // Step 4: Assemble the final palindrome
        if (mid != '\0') {
            return first_half + mid + second_half;
        }
        return first_half + second_half;
    }
};
