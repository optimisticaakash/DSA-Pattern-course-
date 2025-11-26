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
        

        for(int i = 0; i < n; i= i+2*k){
            int left = i;
            int right = min(i+k-1, n-1);
            ReverseStr(s , left, right);
        }

        return s;
    }
};
