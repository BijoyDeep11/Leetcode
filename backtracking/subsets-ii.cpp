class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& current,
                vector<vector<int>>& ans) {

        ans.push_back(current);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;

            current.push_back(nums[j]);

            helper(j + 1, nums, current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        vector<vector<int>> ans;

        helper(0, nums, current, ans);

        return ans;
    }
};