class Solution {
public:
    void ReverseStr(string &s , int left , int right){
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;

        while(i < n){
            int j = i;
            //move until find space
            while( j <= k) j++;

            //reverse that word
            ReverseStr(s,i,j-1);

            //move to next word
            i = j+1;
        }

        return s;
    }
};
