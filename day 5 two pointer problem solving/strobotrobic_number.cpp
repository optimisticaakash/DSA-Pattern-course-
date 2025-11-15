#include <bits/stdc++.h>
using namespace std;

bool isStrobotrobic(string &s ,unordered_map<char,char> &mp){

    int n = s.size();
    int i = 0;
    int j = n-1;

    while( i <= j){
        char left = s[i];
        char right = s[j];

        if(mp.find(left) != mp.end()){
            if(mp[left] != right){
                return false;
            }
            i++;
            j--;
        }else{
            return false;
        }
    }

    return true;
}
int main(){
    unordered_map<char , char>mp={
        {'0','0'},
        {'1' ,'1'},
        {'8','8'},
        {'6','9'},
        {'9','6'}
        };
    string s = "128821";

    cout<<(isStrobotrobic(s ,mp)? "true":"false");
    return 0;
}
