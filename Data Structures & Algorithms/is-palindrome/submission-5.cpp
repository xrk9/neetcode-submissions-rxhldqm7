class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r){
            while(!isalnum(s[l])) l++;
            while(!isalnum(s[r])) r--;
            if(l<r && tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
