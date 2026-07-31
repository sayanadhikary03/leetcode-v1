class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++){
            int compliment = target - nums[i];

            if(map.find(compliment) != map.end()){
                return {map[compliment], i};
            }

            //if not found in the map store it
            map[nums[i]] = i;

        }
        return {};
    }
};