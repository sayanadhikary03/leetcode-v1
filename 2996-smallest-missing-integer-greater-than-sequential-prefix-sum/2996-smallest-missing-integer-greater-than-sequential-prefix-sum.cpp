class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Identify the longest sequential prefix
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            i++;
        }
        
        // Step 2: Sum the elements of this sequential prefix
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += nums[j];
        }
        
        // Step 3: Put all elements into a hash set for O(1) lookups
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step 4: Find the smallest missing integer >= sum
        while (num_set.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};
