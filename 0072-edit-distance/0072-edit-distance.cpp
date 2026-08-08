class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // If word2 is empty
        // We need to delete all characters from word1
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // If word1 is empty
        // We need to insert all characters of word2
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(word1[i-1] == word2[j-1]) {
                    // Characters are same
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // Characters are different
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Delete
                        dp[i][j-1],     // Insert
                        dp[i-1][j-1]    // Replace
                    });
                }
            }
        }

        return dp[n][m];
    }
};