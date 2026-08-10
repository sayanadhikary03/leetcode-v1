class Solution {
public:
    // We add an extra parameter 'endIndex' to control the range
    int fun(vector<int>& nums, int i, int endIndex, vector<int>& dp) {
        // Base case: check against our custom boundary instead of nums.size()
        if (i > endIndex) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        // Pass endIndex down the recursive chain
        int rob = nums[i] + fun(nums, i + 2, endIndex, dp);
        int skip = fun(nums, i + 1, endIndex, dp);
        
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Start at 0, must stop at n-2
        vector<int> dp1(n, -1);
        int choice1 = fun(nums, 0, n - 2, dp1);

        // Case 2: Start at 1, can go up to n-1
        vector<int> dp2(n, -1);
        int choice2 = fun(nums, 1, n - 1, dp2);

        return max(choice1, choice2);
    }
};
