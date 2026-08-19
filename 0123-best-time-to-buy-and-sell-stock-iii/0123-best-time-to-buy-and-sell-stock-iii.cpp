class Solution {
public:
    //RECURSION
    int stock(int i, int buy, vector<int>& prices,
          vector<vector<vector<int>>>& dp, int cap){

        if (i == prices.size() || cap == 0) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;

        if(buy){
            profit = max(-prices[i] + stock(i+1, 0, prices, dp, cap),
                            0 + stock(i+1, 1, prices, dp, cap));
        }
        else{
            profit = max(prices[i] + stock(i+1, 1, prices, dp, cap-1),
                            0 + stock(i+1, 0, prices, dp, cap));
        }
        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int cap = 2;
        int n = prices.size();
        // i    → current day
        // buy  → can buy or need to sell
        // cap  → transactions remaining

        // dp[i][buy][cap]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return stock(0, 1, prices, dp, 2);
    }
};