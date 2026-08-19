class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Vector version              Variable version

        // next[1]       ─────────→    aheadBuy
        // next[0]       ─────────→    aheadNotBuy

        // current[1]    ─────────→    curBuy
        // current[0]    ─────────→    curNotBuy

        int aheadBuy = 0;
        int aheadNotBuy = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {

            int curBuy = max(
                -prices[i] + aheadNotBuy,
                aheadBuy
            );

            int curNotBuy = max(
                prices[i] + aheadBuy,
                aheadNotBuy
            );

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }

        return aheadBuy;
    }
};

// Recursion       → O(2^n) time, O(n) stack
// Memoization     → O(n) time, O(n) DP + stack
// Tabulation      → O(n) time, O(n) DP
// Space optimized → O(n) time, O(1) space