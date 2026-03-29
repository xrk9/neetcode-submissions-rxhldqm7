class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        
        int seen[128] = {0}; 
        int output = 0; 
        int start = 0;
        
        for(int i = 0; i < n; ++i) {
            if(seen[s[i]] > start) {
                start = seen[s[i]];
            }
            
            seen[s[i]] = i + 1;
            output = max(output, i - start + 1);
        }
        return output;
    }
};