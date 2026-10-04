class Solution {
public:
    bool isPalindrome(string s) {
       string t = "";
       for(char i : s){
        if(isalnum(i)) t.push_back(tolower(i));
       } 
    string rev = t;
    reverse(rev.begin(), rev.end());
    return rev == t;
    }
};