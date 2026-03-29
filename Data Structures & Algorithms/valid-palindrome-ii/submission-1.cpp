class Solution {
private:
        bool isPal(string s, int i, int j){
                while(i<j){
                    if(s[i++] != s[j--]) return false;
                }
                return true;
        }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i<j && s[i] == s[j]){
            i++; j--;
        }
        if(i<j){
            return (isPal(s,++i,j) || isPal(s,--i, --j));
        }
    }
};