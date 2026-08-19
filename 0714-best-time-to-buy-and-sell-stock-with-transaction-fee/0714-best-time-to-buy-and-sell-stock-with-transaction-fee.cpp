class Solution {
public:
//MEMOIZATION
    int stock(int i, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee){

        int n = prices.size();

        //base case
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;

        if(buy){
            //BUY OR sKIP
            profit = max(
                -prices[i] + stock(i+1, 0, prices, dp, fee),
                0 + stock(i+1, 1, prices, dp, fee));
        }
        else{
            //SELL OR SKIP
            profit = max(prices[i] - fee + stock(i+1, 1, prices, dp, fee) ,
                                0 + stock(i+1, 0, prices, dp, fee)) ;
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //dp[n][2]
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return stock(0,1,prices,dp,fee);
    }
};