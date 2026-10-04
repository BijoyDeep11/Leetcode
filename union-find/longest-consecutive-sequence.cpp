class Solution {
public:

    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();

            return splitmix64(x + FIXED_RANDOM);
        }
    };

    int longestConsecutive(vector<int>& nums) {

        unordered_set<int, custom_hash> numsSet;

        for (int x : nums) {
            numsSet.insert(x);
        }

        int ans = 0;

        for (int x : numsSet) {

            if (numsSet.count(x - 1))
                continue;

            int current = x;
            int length = 1;

            while (numsSet.count(current + 1)) {
                current++;
                length++;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};