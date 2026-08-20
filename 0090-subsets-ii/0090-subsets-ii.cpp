class Solution {
public:
    void solve(int ind, vector<vector<int>>& ans,vector<int> temp, vector<int>& nums){
        int n = nums.size();

        ans.push_back(temp);

        for(int i=ind; i <n; i++){

            if(i > ind && nums[i] == nums[i-1] ){
            continue;
        }
        //TAKE
        temp.push_back(nums[i]);
        solve(i+1, ans, temp, nums);

        temp.pop_back();

        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        solve(0, ans, temp, nums);

        return ans;
    }
};