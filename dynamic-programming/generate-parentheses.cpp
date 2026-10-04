class Solution {
public:
    void helper(int n, string current, int open, int closed, vector<string>& ans){
        if(current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        if(open < n){
            current.push_back('(');
            helper(n,current,open+1,closed,ans);
            current.pop_back();
        }

        if(closed < open){
            current.push_back(')');
            helper(n,current,open,closed+1,ans);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> ans;

        helper(n,current,0,0,ans);
        return ans;
    }
};