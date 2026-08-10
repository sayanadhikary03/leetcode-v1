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

//tabulation coz sc become o(1)
// class Solution {
// public:
//     int climbStairs(int n) {
//         // Handle edge case where no stairs or 1 stair exists
//         if (n <= 1) return 1;

//         // dp[i] will store the number of ways to reach step i
//         vector<int> dp(n + 1);

//         // Base cases
//         dp[0] = 1; // 1 way to stay at the ground floor (do nothing)
//         dp[1] = 1; // 1 way to reach the 1st step (1-step jump)

//         // Fill the table iteratively from step 2 to n
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }

//         return dp[n];
//     }
// };

//same tabulation
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int prev2 = 1; // Represents dp[i-2]
        int prev1 = 1; // Represents dp[i-1]
        int current = 0;

        for (int i = 2; i <= n; i++) {
            current = prev1 + prev2; // dp[i] = dp[i-1] + dp[i-2]
            prev2 = prev1;           // Shift dp[i-2] forward
            prev1 = current;         // Shift dp[i-1] forward
        }

        return current;
    }
};
