// ============================================================
// 4. SPACE OPTIMIZATION
//
// State:
// after[tranNo] → dp[i+1][tranNo]
// cur[tranNo]   → dp[i][tranNo]
//
// Time: O(n * k)
// Space: O(k)
// ============================================================

class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        // after = dp[i+1]
        vector<int> after(2 * k + 1, 0);

        // cur = dp[i]
        vector<int> cur(2 * k + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            for(int tranNo = 2 * k - 1;
                tranNo >= 0;
                tranNo--) {

                int profit = 0;

                if(tranNo % 2 == 0) {

                    // BUY or SKIP
                    profit = max(
                        -prices[i] + after[tranNo + 1],
                        0 + after[tranNo]
                    );

                }
                else {

                    // SELL or SKIP
                    profit = max(
                        prices[i] + after[tranNo + 1],
                        0 + after[tranNo]
                    );
                }

                cur[tranNo] = profit;
            }

            // Current row becomes next row
            after = cur;
        }

        return after[0];
    }
};

//                  STOCK IV
//                     │
//                     ↓
//           State = (i, tranNo)
//                     │
//         ┌───────────┴───────────┐
//         ↓                       ↓
//    tranNo even             tranNo odd
//         ↓                       ↓
//       BUY                     SELL
//         │                       │
//         └───────────┬───────────┘
//                     ↓
//                tranNo + 1

// ┌─────────────────┬────────────┬──────────────┐
// │ Approach        │ Time       │ Space        │
// ├─────────────────┼────────────┼──────────────┤
// │ Recursion       │ Exponential│ O(n) stack   │
// │ Memoization     │ O(n × k)   │ O(n × k)     │
// │ Tabulation      │ O(n × k)   │ O(n × k)     │
// │ Space Optimized │ O(n × k)   │ O(k)         │
// └─────────────────┴────────────┴──────────────┘