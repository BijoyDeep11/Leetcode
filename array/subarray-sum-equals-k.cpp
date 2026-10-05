class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> prefixCount;
      
      prefixCount[0] = 1;

      int prefixSum = 0;
      int count = 0;
      
      for(auto i : nums){
        prefixSum += i;
        int needed = prefixSum - k;

        if(prefixCount.find(needed) != prefixCount.end()){

            count += prefixCount[needed];

        }
        prefixCount[prefixSum]++;
      }

      return count;
    }
};