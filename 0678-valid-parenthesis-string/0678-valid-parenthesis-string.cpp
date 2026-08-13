class Solution {
public:
    bool checkValidString(string s) {

        // low  = minimum possible balance
        // high = maximum possible balance
        //
        // Balance means:
        // '(' -> +1
        // ')' -> -1
        //
        // '*' can be:
        // '('  -> +1
        // ')'  -> -1
        // ""   ->  0
        //
        // Example: s = "(*)"
        //
        // After '(':
        // low = 1, high = 1
        //
        // After '*':
        // '*' can be ')' -> balance 0
        // '*' can be ""  -> balance 1
        // '*' can be '(' -> balance 2
        //
        // Therefore:
        // low = 0, high = 2
        //
        // We only store the minimum and maximum,
        // not every possible balance.

        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {

                // '(' must increase balance
                low++;
                high++;
            }

            else if (c == ')') {

                // ')' must decrease balance
                low--;
                high--;
            }

            else { // c == '*'

                // For MINIMUM balance:
                // Assume '*' = ')'
                low--;

                // For MAXIMUM balance:
                // Assume '*' = '('
                high++;

                // '*' = "" is automatically somewhere
                // between low and high.
            }

            // If even the MAXIMUM possible balance
            // is negative, there is NO possible way
            // to make the string valid.
            //
            // Example: ")"
            //
            // low  = -1
            // high = -1
            //
            // Even the best possibility is negative.
            if (high < 0)
                return false;

            // Negative LOW does NOT necessarily mean invalid.
            //
            // It only means the minimum possibility is bad.
            // There may still be valid possibilities.
            //
            // Example: "(*)"
            // At the end we may get:
            // low = -1, high = 1
            //
            // We throw away the impossible negative balance
            // and keep low = 0.
            if (low < 0)
                low = 0;
        }

        // At the end, we need at least one possibility
        // with balance = 0.
        //
        // low represents the smallest possible balance.
        // Since low can never be negative here,
        // low == 0 means balance 0 is possible.
        //
        // Example:
        //
        // "(*))"
        //
        // One valid interpretation:
        // '*' = '('
        //
        // "(*))"
        //   ↓
        // "(())"
        //
        // So the answer is true.
        return low == 0;
    }
};