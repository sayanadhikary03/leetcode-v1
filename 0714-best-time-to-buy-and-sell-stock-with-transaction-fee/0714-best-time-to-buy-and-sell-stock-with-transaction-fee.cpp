class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //dp[n][2]
        vector<int>front(2,0);
        vector<int>curr(2,0);
        
        for(int i = n-1; i >= 0; i--){
             
                    //BUY OR sKIP
                    curr[1] = max(
                        -prices[i] + front[0],
                        0 + front[1]);
                
               
                    //SELL OR SKIP
                    curr[0] = max(prices[i] - fee + front[1] ,
                                        0 + front[0]) ;

                    front = curr;
            }
        return curr[1];
    }
};