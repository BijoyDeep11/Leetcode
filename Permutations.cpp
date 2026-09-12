class Solution {
public:
    void helper(vector<int>& nums, vector<int>& current,unordered_set<int>& used, vector<vector<int>>& ans){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }
        for(auto x : nums){

            if(used.count(x)) continue;

            current.push_back(x);
            used.insert(x);

            helper(nums,current,used,ans);

            current.pop_back();
            used.erase(x);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     vector<int> current;
     unordered_set<int> used;
     vector<vector<int>> ans;

     helper(nums,current,used,ans);
     return ans;   
    }
};