// ============================================================
// 3. TABULATION
//
// State:
// dp[i][tranNo]
//
// Time: O(n * k)
// Space: O(n * k)
// ============================================================

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // dp[i][tranNo]
        vector<vector<int>> dp(
            n + 1,
            vector<int>(2 * k + 1, 0)
        );

        // dp[n][...] = 0
        // Already initialized to 0.
        //
        // tranNo = 2*k is also 0.
        
        for(int i = n - 1; i >= 0; i--) {

            for(int tranNo = 2 * k - 1;
                tranNo >= 0;
                tranNo--) {

                int profit = 0;

                if(tranNo % 2 == 0) {

                    // BUY or SKIP
                    profit = max(
                        -prices[i] + dp[i + 1][tranNo + 1],
                        0 + dp[i + 1][tranNo]
                    );

                }
                else {

                    // SELL or SKIP
                    profit = max(
                        prices[i] + dp[i + 1][tranNo + 1],
                        0 + dp[i + 1][tranNo]
                    );
                }

                dp[i][tranNo] = profit;
            }
        }

        return dp[0][0];
    }
};