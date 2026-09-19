class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.size() != t.size()) return false;

       unordered_map<char, char> sToT;
       unordered_map<char, char> tToS;

       for(int i = 0; i < s.size(); i++){
        if(sToT.count(s[i]) && sToT[s[i]] != t[i]) return false;
        if(tToS.count(t[i]) && tToS[t[i]] != s[i]) return false;

        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
       }

       return true; 
    }
};