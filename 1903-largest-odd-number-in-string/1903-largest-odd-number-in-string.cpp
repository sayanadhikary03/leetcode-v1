class Solution {
public:
    string largestOddNumber(string num) {
        
        int ind = -1;

        // Find the rightmost odd digit
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }

        // No odd digit found
        if (ind == -1) {
            return "";
        }

        // Remove leading zeroes
        // Skipping any leading zeroes
        int i = 0;
        while(i <= ind && num[i] == '0') i++;
        
        // Return the largest odd number substring
        return num.substr(i, ind - i + 1);
    }
};