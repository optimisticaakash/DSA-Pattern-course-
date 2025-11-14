class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int k = 0; 
        int j = n-1;

        while(j >= k){
            if(nums[k] == 1){
                k++;
            }else if(nums[k] == 2){
                int temp = nums[j];
                nums[j]= nums[k];
                nums[k] = temp;
                j--;
            }else{
                int temp = nums[i];
                nums[i]= nums[k];
                nums[k] = temp;
                k++;
                i++;
            }
        }
    }
};

//T.C : O(n) 
//S.c : O(N)
