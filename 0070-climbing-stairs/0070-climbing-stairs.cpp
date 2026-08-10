// class Solution {
// public:

//     int fun(int i, int n, vector<int>& dp){

//         // Base case: reached the top
//         if (i == n) return 1;
//         // Base case: overstepped the top
//         if (i > n) return 0;

//         // Use dp[i] to check if current step 'i' is already calculated
//         if(dp[i] != -1) return dp[i];

//         return dp[i] = fun(i+1, n, dp) + fun(i+2, n, dp);
//     }

//     int climbStairs(int n) {
//         vector<int>dp;
//         dp.resize(n+1, -1);
//         return fun(0,n, dp);
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        // Handle edge case where no stairs or 1 stair exists
        if (n <= 1) return 1;

        // dp[i] will store the number of ways to reach step i
        vector<int> dp(n + 1);

        // Base cases
        dp[0] = 1; // 1 way to stay at the ground floor (do nothing)
        dp[1] = 1; // 1 way to reach the 1st step (1-step jump)

        // Fill the table iteratively from step 2 to n
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
