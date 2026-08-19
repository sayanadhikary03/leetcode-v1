class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //dp[n][2]
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        
        for(int i = n-1; i >= 0; i--){
            for(int buy =0; buy <= 1; buy++){
                int profit = 0;

                if(buy){
                    //BUY OR sKIP
                    profit = max(
                        -prices[i] + dp[i+1][0],
                        0 + dp[i+1][1]);
                }
                else{
                    //SELL OR SKIP
                    profit = max(prices[i] - fee + dp[i+1][1] ,
                                        0 + dp[i+1][0]) ;
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};