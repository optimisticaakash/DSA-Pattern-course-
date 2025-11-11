class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            char left = s[i];
            char right = s[j];

            if(!isalpha(left) && !isdigit(left)){
                i++;
                continue;
            }

            if(!isalpha(right) && !isdigit(right)){
                j--;
                continue;
            }


            if(tolower(left) != tolower(right)){
                return false;
            }
            i++;
            j--;
        }

        return true;
        
    }
};
