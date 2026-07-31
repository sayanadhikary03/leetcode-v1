class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int resultSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(resultSum - target);

        for(int i=0; i<n - 2; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                int diff = abs(sum - target);

                if(diff < minDiff){
                    minDiff = diff;
                    resultSum = sum;
                }

                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else return sum;
            }
        }
        return resultSum;
    }
};