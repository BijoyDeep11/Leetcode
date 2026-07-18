class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<pair<int, int>> v;
        vector<int> ans;
        for(int i : nums){
            freq[i]++;
        }
        for(auto num : freq){
            v.push_back({num.first, num.second});
        }
        sort(v.begin(), v.end(), cmp);

        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};