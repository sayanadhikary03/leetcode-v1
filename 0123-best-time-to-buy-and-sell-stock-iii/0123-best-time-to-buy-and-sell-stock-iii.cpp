class Solution {
public:
    //TABULATION 
    // Time: O(n × 2 × 2) → O(n)
    // Space: O(n × 2 × 3) → O(n)
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        //dp[n][buy][cap]
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap =1; cap <=2; cap++){

                    int profit = 0;

                    if(buy){
                        // BUY or SKIP
                        profit = max(-prices[i] + dp[i+1][0][cap],
                                        0 + dp[i+1][1][cap]);
                    }
                    else{
                        // SELL or SKIP
                        profit = max(prices[i] + dp[i+1][1][cap-1],
                                        0 + dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

