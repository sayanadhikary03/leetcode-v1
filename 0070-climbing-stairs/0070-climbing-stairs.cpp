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

// ## 1. In Recursion (Looking Forward): We use `i + 1` and `i + 2`

// When you write the recursive **(Top-Down)** solution, you start at the **ground floor (step 0)** and look *forward* toward the top.

// * You ask yourself: **"If I am standing on step `i`, what are my next choices?"**
// * Your choices are to step forward to `i + 1` or `i + 2`.
// * Therefore, the code looks ahead:

// ```cpp
// fun(i + 1) + fun(i + 2)
// ```

// ---

// ## 2. In Tabulation (Looking Backward): We use `i - 1` and `i - 2`

// When you write the iterative **(Bottom-Up)** loop, the code runs from `2` up to `n`. You are building a history table.

// When the loop reaches a step, let's say `i = 4`, you are already calculating the value for step `4`.

// You look *backward* at the history you already calculated and ask:

// **"How did I get here?"**

// * You could only have arrived here from **step 3** (`i - 1`) or **step 2** (`i - 2`).
// * Since the loop calculates smaller steps first, `dp[i - 1]` and `dp[i - 2]` already have their answers.
// * You cannot use `dp[i + 1]` or `dp[i + 2]` because the loop hasn't reached those future steps yet—they are still empty.

// Therefore:

// ```cpp
// dp[i] = dp[i - 1] + dp[i - 2];
// ```

// ---

// ## 💡 Summary

// | Approach                   | Where do you start?     | Direction                                          | Formula                   |
// | -------------------------- | ----------------------- | -------------------------------------------------- | ------------------------- |
// | **Top-Down (Recursion)**   | Start at `0`, go to `n` | **Forward** — looking at what choices you can make | `fun(i + 1) + fun(i + 2)` |
// | **Bottom-Up (Tabulation)** | Start at `2`, go to `n` | **Backward** — looking at where you came from      | `dp[i - 1] + dp[i - 2]`   |
