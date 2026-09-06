class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, int sum, vector<int>& current, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(current);
            return;
        }

        if(sum > target) return;

        if(i == candidates.size()) return;

        current.push_back(candidates[i]);
        helper(i,candidates,target,sum+candidates[i],current,ans);

        current.pop_back();
        helper(i+1,candidates,target,sum,current,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<int> current;
     vector<vector<int>> ans;

     helper(0,candidates,target,0,current,ans);
     return ans;   
    }
};