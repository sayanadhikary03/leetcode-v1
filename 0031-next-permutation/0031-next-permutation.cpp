class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        
        // Step 2: If no such element is found, the array is sorted in descending order.
        // Reverse it to get the lowest possible permutation (ascending order) and return.
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return; // <-- CRITICAL FIX: Stop execution here
        }
        
        // Step 3: Find the next larger element than nums[idx] from the right
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        
        // Step 4: Reverse the elements to the right of idx to get the next smallest permutation
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
