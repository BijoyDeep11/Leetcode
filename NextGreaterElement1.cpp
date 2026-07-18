class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> nextGreater;
       stack<int> st;
       vector<int> v;
       int n = nums2.size();
       for(int i=n-1;i >= 0;i--){
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
        if(st.empty()){
            nextGreater[nums2[i]] = -1;
        }else{
            nextGreater[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
       }
       for(auto num : nums1){
            v.push_back(nextGreater[num]);
       }
       return v; 
    }
};