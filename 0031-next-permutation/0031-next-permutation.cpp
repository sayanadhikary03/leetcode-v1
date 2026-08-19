class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;


        for(int i=n-2; i >= 0; i--){

            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
            if(pivot == -1){
                reverse(nums.begin(), nums.end());
                return;
            } 
            // Step 2: Find rightmost element just greater than pivot element
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        // Step 4: Reverse the suffix elements to the right of the pivot
        reverse(nums.begin() + pivot + 1, nums.end());
        }
};