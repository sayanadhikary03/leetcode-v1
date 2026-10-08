class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        int cnt1= 0, cnt2 = 0;
        int el1 = 0, el2 = 0;

        for(int num : nums){
            if(cnt1 == 0 && num != el2){
                cnt1 = 1;
                el1 = num;
            }
            else if(cnt2 == 0 && num != el1){
                cnt2 = 1;
                el2 = num;
            }
            else if(num == el1){
                cnt1++;
            }
            else if(num == el2){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {
            if (num == el1)
                cnt1++;
            else if (num == el2)
                cnt2++;
        }

        // Add valid candidates
        if (cnt1 > n / 3)
            ans.push_back(el1);

        if (cnt2 > n / 3 && el2 != el1)
            ans.push_back(el2);

        return ans;
    }
};