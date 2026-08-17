class Solution {
public:

    vector<int>dp;

    int findingMax(vector<int>& nums, int i){
        //Base Case
        if(i >= nums.size()){
            return 0;
        };

        // Already calculated
        if(dp[i] != -1){
            return dp[i];
        }

        // Option 1: Rob current house
        // So we must jump to i+2
        int rob = nums[i] + findingMax(nums,i+2);

        // Option 2: Skip current house
        // So we move to i+1
        int skip = findingMax(nums, i+1);

        // Store the best answer for this index
        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        // Initially nothing is calculated
        dp.resize(nums.size(), -1);
        
        // Start from house 0
        return findingMax(nums,0);
    }
};