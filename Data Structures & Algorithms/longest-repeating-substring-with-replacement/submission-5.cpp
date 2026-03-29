class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(n<k+2) return n;
        unordered_map<char,int> count;
        int result = k+1;
        int maxf = 0;
        int i = 0;
        for(int j = 0; j<n; j++){
            maxf = max(maxf,++count[s[j]]);
            if((j-i+1 - maxf) <= k){
                result = max(result,(j-i+1));
            }else{
                --count[s[i++]];
            }
        }
        return result;
    }
};
