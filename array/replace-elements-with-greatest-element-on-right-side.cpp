class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight = -1;
        vector<int> ans(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            ans[i] = maxRight;

            if (arr[i] > maxRight) {
                maxRight = arr[i];
            }
        }

        return ans;
    }
};