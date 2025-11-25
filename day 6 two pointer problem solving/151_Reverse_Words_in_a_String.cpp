//approach : without stl

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
    string reverseWords(string s) {
        int n = s.length();

        // 1.trim spaces from left and right
        int l  = 0 , r = n-1;
        while(l < n && s[l] == ' ')l++;
        while(r >= 0 && s[r] == ' ')r--;

        //2. Remove multiple spaces and build clean string
        string temp = "";
        while(l <= r){
            if(s[l] != ' ') temp.push_back(s[l]);
            else if(temp.back() != ' ') temp.push_back(' ');
            l++;
        }

        //3. Reverse the whole cleaned string
        ReverseStr(temp , 0 , temp.length()-1);

        //4. Reverse each individual word
        int start = 0;
        int len = temp.length();
        while(start < len){
            int end = start;
            while(end < len && temp[end] != ' ') end++;
            ReverseStr(temp,start,end-1);
            start = end+1;
        }

        return temp;
    }
};

//T.C : O(N)
//S.C : O(N)

//Approach1: using stl 
//code1:
class Solution {
public:
    string reverseWords(string s) {
       
        stringstream ss(s);
        string token ;

        vector<string> words;

        while(getline(ss,token,' ')){
            if(!token.empty())
            words.push_back(token);
        }

        int n = words.size();

        for(int i = 0; i <n/2; i++){
            swap(words[i] , words[n-i-1]);
        }
        string result = "";
        for(int i = 0; i < n; i++){
            result += words[i];
            if(i != n-1) result += " ";
        }
        return result;
    }
};
//T.C : O(N)

//Code 2:
class Solution {
public:
    string reverseWords(string s) {
       
        istringstream iss(s);
        string token ;

        vector<string> words;

        while(iss >> token){
            
            words.push_back(token);
        }

        int n = words.size();

        for(int i = 0; i <n/2; i++){
            swap(words[i] , words[n-i-1]);
        }
        string result = "";
        for(int i = 0; i < n; i++){
            result += words[i];
            if(i != n-1) result += " ";
        }
        return result;
    }
};

//Code 3:
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stringstream ss(s);
        string token="";
        string result="";

        while(ss >> token){//by default space ke baisis pr todega word ko 
            result = token +" "+result;
        }

        if(!result.empty() && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};
