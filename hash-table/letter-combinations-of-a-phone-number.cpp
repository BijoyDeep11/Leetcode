class Solution {
public:
    void helper(int i, string digits, string current,
                vector<string>& mapping, vector<string>& ans) {

        if (i == digits.size()) {
            ans.push_back(current);
            return;
        }

        for (auto x : mapping[digits[i] - '0']) {
            current.push_back(x);

            helper(i + 1, digits, current, mapping, ans);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current;
        vector<string> ans;

        helper(0, digits, current, mapping, ans);

        return ans;
    }
};