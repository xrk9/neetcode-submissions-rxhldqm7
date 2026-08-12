class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s1.size();
        int n = s2.size();
        if(n < size) return false;
        int target = 0;
        int targ_count[26] = {0};
        for(const char& c : s1){
            target += c;
            targ_count[c-'a']++;
        }
        int l = 0, r = size-1;
        int curr = 0;
        int curr_count[26] = {0};
        for(int i = 0; i<size; i++){
            curr += s2[i];
            curr_count[s2[i] - 'a']++;
        }
        while(true){
            if(target == curr){
                bool flag = true;
                for(int i = 0; i<26; i++){
                    if(curr_count[i] != targ_count[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }
            if(r == n-1) return false;
            curr_count[s2[l] - 'a']--;
            curr-=s2[l++];
            curr_count[s2[++r] - 'a']++;
            curr+=s2[r];
        }
        return false;
    }
};