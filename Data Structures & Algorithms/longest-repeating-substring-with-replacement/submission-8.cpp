class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if(k+1 >= n) return n;
        int count[26] = {0};
        int max_len = 0;
        int max_f = 0;
        int l = 0, r = -1;
        while(r<n-1){
            r++;
            count[s[r] - 'A']++;
            if(count[s[r] - 'A'] > max_f) max_f = count[s[r] - 'A'];
            if(r-l+1 - max_f <= k){
                max_len = r-l+1;
            }
            else{
                count[s[l] - 'A']--;
                l++;
                int mm = 0;
                for(int i = 0; i<26; i++){
                    mm = max(mm, count[i]);
                }
                max_f = mm;
            }
        }
        return max_len;
    }
};
