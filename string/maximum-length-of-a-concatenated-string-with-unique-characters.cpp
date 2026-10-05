class Solution {
public:
    int helper(int i, vector<string>& arr, unordered_set<char>& st) {
        if (i == arr.size())
            return 0;

        bool isValid = true;
        bool seen[26] = {};

        // Check whether the current string can be selected
        for (auto ch : arr[i]) {
            if (st.count(ch) || seen[ch - 'a']) {
                isValid = false;
                break;
            }

            seen[ch - 'a'] = true;
        }

        int pick = 0;

        if (isValid) {
            // Pick current string
            for (auto ch : arr[i])
                st.insert(ch);

            pick = arr[i].size() + helper(i + 1, arr, st);

            // Backtrack
            for (auto ch : arr[i])
                st.erase(ch);
        }

        // Don't pick current string
        int notPick = helper(i + 1, arr, st);

        return max(pick, notPick);
    }

    int maxLength(vector<string>& arr) {
        unordered_set<char> st;
        return helper(0, arr, st);
    }
};