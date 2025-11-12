//problem link  : https://neetcode.io/problems/valid-word-abbreviation?list=neetcode250

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;

        while(i < word.size() && j < abbr.size()){
            char wordchar = word[i];
            char abbrchar = abbr[j];

            if(isdigit(abbrchar)){
                if(abbrchar == '0') return false;

                int curr = 0;

                while( j < abbr.size() && isdigit(abbr[j])){
                    curr = curr * 10 + (abbr[j] - '0');
                    j++;
                }
                i=i+curr;
            }else{
                if(wordchar != abbrchar){
                    return false;
                }

                i++;
                j++;
            } 
        }

        return i == word.size() && j == abbr.size();
    }
};
//T.C : O(N) min of (word, abbr)
//S.C : O(1)
