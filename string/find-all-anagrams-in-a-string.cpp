class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window;
        unordered_map<char, int> freqP;
        vector<int> ans;

        for(auto ch : p){
            freqP[ch]++;
        }

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            window[s[right]]++;
            if(right - left + 1 > p.size()){
                window[s[left]]--;
                if(window[s[left]] == 0) window.erase(s[left]);
                left++;
            }

            if (window == freqP) ans.push_back(left);
        }
        return ans;
    }
};