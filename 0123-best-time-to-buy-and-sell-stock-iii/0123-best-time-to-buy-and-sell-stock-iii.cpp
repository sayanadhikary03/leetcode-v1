class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // For cap = 2
        int aheadBuy2 = 0;
        int aheadNotBuy2 = 0;

        // For cap = 1
        int aheadBuy1 = 0;
        int aheadNotBuy1 = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {

            // Current values for cap = 2
            int curBuy2 = max(
                -prices[i] + aheadNotBuy2,
                aheadBuy2
            );

            int curNotBuy2 = max(
                prices[i] + aheadBuy1,
                aheadNotBuy2
            );

            // Current values for cap = 1
            int curBuy1 = max(
                -prices[i] + aheadNotBuy1,
                aheadBuy1
            );

            int curNotBuy1 = max(
                prices[i] + 0,
                aheadNotBuy1
            );

            // Move current → ahead
            aheadBuy2 = curBuy2;
            aheadNotBuy2 = curNotBuy2;

            aheadBuy1 = curBuy1;
            aheadNotBuy1 = curNotBuy1;
        }

        return aheadBuy2;
    }
};

