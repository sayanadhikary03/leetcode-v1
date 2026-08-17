class Solution {
public:
    int rob(vector<int>& nums) {

        //Tabulation(with space optimization)
        //To reduce the space from O(n) to O(1)

        int n = nums.size();

        int next1 = 0; //[i+1]
        int next2 = 0; //[i+2]

        for(int i = n-1; i >= 0; i--){

            int rob = nums[i] + next2;
            int skip = next1;

            int current = max(rob, skip);

            next2 = next1;
            next1 = current;
        }

        return next1;
    }
};