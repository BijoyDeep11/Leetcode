class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if (strs[j].size() <= i)
                    return ans;

                if (strs[j][i] != strs[0][i])
                    return ans;
            }
                ans.push_back(strs[0][i]);    
        }
        return ans;
    }
};