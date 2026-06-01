class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n==1) return 1;
        int res = n;
        for(int i = 1; i<n; i++){
            for(int k = 0; k<2; k++){
                if((i+k<n) && s[i-1] == s[i+k]){
                    int l = i-1;
                    int r = i+k;
                    while(l>=0 && r<n && s[l] == s[r]){
                        l--; r++; res++;
                    }
                }
            }
        }
        return res;
    }
};
