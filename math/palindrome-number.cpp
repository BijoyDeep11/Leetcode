class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string original = to_string(x);
        string reverse = "";
        do{
            int rem = x % 10;
            char res = rem + '0';
            reverse.push_back(res);
            x /= 10;
        }while(x != 0);
        return original == reverse;
    }
};