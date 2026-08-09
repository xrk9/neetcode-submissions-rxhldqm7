#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int seenAt[128]; 
        
        std::fill(std::begin(seenAt), std::end(seenAt), -1);
        
        int len = 0;
        int start = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            char c = s[i];
            
            if(seenAt[c] >= start) {
                start = seenAt[c] + 1; 
            }
            
            seenAt[c] = i;
            
            len = std::max(len, i - start + 1);
        }
        
        return len;
    }
};