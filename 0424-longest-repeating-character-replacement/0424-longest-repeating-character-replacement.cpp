class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        // Frequency array for all ASCII characters
        vector<int> f(256, 0);

        int low = 0;        // Left pointer of window
        int maxcnt = 0;     // Maximum frequency of any character in window
        int res = 0;        // Answer

        // Right pointer moves forward
        for (int high = 0; high < n; high++) {

            // Add current character to the window
            f[s[high]]++;

            // Update maximum frequency
            maxcnt = max(maxcnt, f[s[high]]);

            // Current window length
            int windowLen = high - low + 1;

            // Characters to replace
            int changesNeeded = windowLen - maxcnt;

            // If more than k changes needed, shrink window
            while (changesNeeded > k) {
                f[s[low]]--;
                low++;

                windowLen = high - low + 1;
                changesNeeded = windowLen - maxcnt;
            }

            // Update result
            res = max(res, windowLen);
        }

        return res;
    }
};