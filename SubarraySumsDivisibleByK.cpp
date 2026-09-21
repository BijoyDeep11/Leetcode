class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;

        int prefixSum = 0;
        int count = 0;

        remainderCount[0] = 1;

        for(int num : nums){
            prefixSum += num;

            int rem = ((prefixSum % k) + k) % k;

            count += remainderCount[rem];

            remainderCount[rem]++;
            
        }

        return count;
    }
};