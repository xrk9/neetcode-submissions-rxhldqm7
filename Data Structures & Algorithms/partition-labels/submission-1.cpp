class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0}; 
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i; 
        }
        
        vector<int> res;
        int start = 0, end = 0;
        
        for(int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);
            
            if(i == end) {
                res.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return res;
    }
};