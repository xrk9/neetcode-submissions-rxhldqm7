class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int a_ = target[0],
            b_ = target[1],
            c_ = target[2];
            
        int a = 0, b = 0, c = 0;
        
        for(int i = 0; i < n; i++) {
            int _a = triplets[i][0];
            int _b = triplets[i][1];
            int _c = triplets[i][2];
            
            if(_a > a_ || _b > b_ || _c > c_) continue;
            
            a = max(a, _a);
            b = max(b, _b);
            c = max(c, _c);
            
            if(a_ == a && b_ == b && c_ == c) return true;
        }
        return false;
    }
};