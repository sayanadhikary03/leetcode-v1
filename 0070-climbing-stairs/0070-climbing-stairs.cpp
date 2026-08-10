class Solution {
public:

    int fun(int i, int n, vector<int>& dp){

         // Base case: reached the top
        if (i == n) return 1;
        // Base case: overstepped the top
        if (i > n) return 0;

        // Use dp[i] to check if current step 'i' is already calculated
        if(dp[i] != -1) return dp[i];

        return dp[i] = fun(i+1, n, dp) + fun(i+2, n, dp);
    }

    int climbStairs(int n) {
        vector<int>dp;
        dp.resize(n+1, -1);
        return fun(0,n, dp);
    }
};