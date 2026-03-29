class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        int i = 0;
        vector<int> out;
        out.reserve(n);

        while(i<n){
            int a = ast[i];
            if(a>0 || out.empty() || out.back() < 0){
                out.push_back(a);
                ++i;
            }else{
                if(-a < out.back()){
                    ++i;
                } else if (-a == out.back()){
                    ++i;
                    out.pop_back();
                } else {
                    out.pop_back();
                }
            }
        }
        return out;
    }
};