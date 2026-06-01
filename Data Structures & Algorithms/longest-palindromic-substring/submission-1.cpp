class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        s+='\0';
        int len = 1;
        int indx = 0;
        for(int i = 1; i<n; i++){
            for(int k = 0; k<2; k++){
                if(s[i+k] == s[i-1]){
                    int l = i-1, r = i+k;
                    while(l>=0 && r<n && (s[l] == s[r])){
                        --l; ++r;
                    }
                    if(r-l - 1 > len){
                        len = r-l-1;
                        indx = l+1;
                    }
                }
            }
            
        }
        return s.substr(indx, len);
    }
};
