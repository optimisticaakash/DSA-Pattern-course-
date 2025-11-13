class Solution {
public:
    void threeSumhelper(int f ,vector<int>& nums,vector<vector<int>>&answer){
        int i = f+1;
        int j = nums.size()-1;

        while(i < j){
            int sum = nums[f]+nums[i]+nums[j];

            if(sum > 0){
                j--;
            }else if(sum < 0){
                i++;
            }else{
                //triplet is found
                answer.push_back({nums[f],nums[i],nums[j]});
                i++;
                j--;

                while(i < j && nums[i] == nums[i-1]){
                    i++;
                }

                while(i < j && nums[j] == nums[j+1]){
                    j--;
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        //sort the array
        sort(begin(nums) , end(nums));

        for(int f = 0; f < nums.size(); f++){
            if(nums[f] > 0){
                break;
            }

            if(f == 0 || nums[f] != nums[f-1]){
                threeSumhelper(f,nums,answer);
            }
        }

        return answer;
    }
};
//T.C : O(NlogN + N^2)
//S.C : O(LOgN)
