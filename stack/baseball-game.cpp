class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int count = 0;
        for(auto ch : operations){
            if(ch != "+" && ch != "D" && ch != "C"){
                int x = stoi(ch);
                st.push(x);
            }else if(ch == "D"){
                int a = st.top();
                int doubled = a * 2;
                st.push(doubled);
            }else if(ch == "C"){
                st.pop();
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                int sum = a + b;
                st.push(a);
                st.push(sum);
            }
        }
        while(!st.empty()){
            count += st.top();
            st.pop();
        }
        return count;
    }
};