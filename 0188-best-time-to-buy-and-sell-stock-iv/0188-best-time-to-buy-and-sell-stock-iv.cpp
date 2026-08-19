// ============================================================
// 2. MEMOIZATION
//
// State:
// dp[i][tranNo]
//
// Time: O(n * k)
// Space: O(n * k) DP + O(n) recursion stack
//       = O(n * k)
// ============================================================

class Solution {
public:

    int stock(int i, int tranNo,
              vector<int>& prices,
              int k,
              vector<vector<int>>& dp) {

        // Base case
        if(i == prices.size() || tranNo == 2 * k)
            return 0;

        // Already calculated
        if(dp[i][tranNo] != -1)
            return dp[i][tranNo];

        int profit = 0;

        if(tranNo % 2 == 0) {

            // BUY or SKIP
            profit = max(-prices[i] + stock(i + 1, tranNo + 1, prices, k, dp),
                                0 + stock(i + 1,tranNo,prices,k,dp));

        }
        else {

            // SELL or SKIP
            profit = max(prices[i] + stock(i + 1,tranNo + 1,prices,k,dp),
                                0 + stock(i + 1,tranNo,prices,k,dp));
        }

        return dp[i][tranNo] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // dp[i][tranNo]
        vector<vector<int>> dp(
            n,
            vector<int>(2 * k, -1)
        );

        return stock(0, 0, prices, k, dp);
    }
};

//              tranNo
//           0    1    2    3
//        ┌────┬────┬────┬────┐
// day 0  │ -1 │ -1 │ -1 │ -1 │
//        ├────┼────┼────┼────┤
// day 1  │ -1 │ -1 │ -1 │ -1 │
//        ├────┼────┼────┼────┤
// day 2  │ -1 │ -1 │ -1 │ -1 │
//        ├────┼────┼────┼────┤
// day 3  │ -1 │ -1 │ -1 │ -1 │
//        ├────┼────┼────┼────┤
// day 4  │ -1 │ -1 │ -1 │ -1 │
//        └────┴────┴────┴────┘

//         ↓    ↓    ↓    ↓
//        BUY  SELL BUY  SELL