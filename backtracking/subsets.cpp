class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
        if(nums.size() == i){
            ans.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        helper(i+1,nums,current,ans);

        current.pop_back();
        helper(i+1,nums,current,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ans;

        helper(0,nums,current,ans);
        return ans;
    }
};