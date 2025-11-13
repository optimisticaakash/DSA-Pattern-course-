class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;

        for(int i = 0; i < nums.size(); i++){
            int element = target-nums[i];

            if(hashmap.find(element) != hashmap.end()){
                return{hashmap[element], i};
            }

            hashmap[nums[i]] = i;
        }

        return {};
    }
};
//T.C : O(N)
//S.c : O(N)
