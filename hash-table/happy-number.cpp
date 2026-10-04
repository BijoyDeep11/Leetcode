class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int sum = 0;
        while(true){
            if (n == 1) return true;
            if(st.count(n) != 0) return false;
            st.insert(n);
            while( n != 0){
                int rem = n % 10;
                sum += rem * rem;
                n /= 10;
            }
            n = sum;
            sum = 0;
        }
    }
};