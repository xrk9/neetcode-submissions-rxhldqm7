class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<2) return n;
        unordered_map<int,int> seen;
        int output = 0;
        seen.reserve(n);
        seen[s[0]] = 1;
        int start = 1;
        int i = 1;
        for(; i < n; i++){
            if(seen[s[i]] >= start){
                output = max(output, (i+1-start));
                start = seen[s[i]]+1;
                seen[s[i]] = i+1;
            } else {
                seen[s[i]] = i+1;
            }
        }
        output = max(output,(i+1-start));
        return output;
    }
};
