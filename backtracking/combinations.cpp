class Solution {
public:
    void helper(int start,int n, vector<int>& current, int k, vector<vector<int>>& ans){
        if(current.size() == k){
            ans.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++){
            current.push_back(i);

            helper(i+1,n,current,k,ans);

            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> ans;

        helper(1,n,current,k,ans);
        return ans;
    }
};