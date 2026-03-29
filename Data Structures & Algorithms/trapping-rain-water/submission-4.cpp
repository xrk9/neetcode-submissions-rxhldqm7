class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0 or n==1 or n==2) return 0;
        int vol = 0;
        vector<int> s;
        s.reserve(n);
        int i = 0;
        while(i<n && height[i] == 0) ++i;
        s.push_back(i++);
        while(i<n){
            if(height[i] == 0){
                ++i;
                continue;
            }
            if(height[i] < height[s.back()]){
                vol += height[i]*(i-s.back()-1);
            }else{
                int lh = 0;
                while(!s.empty() && height[i] >= height[s.back()]){
                    vol += (height[s.back()] - lh) * (i-s.back() -1);
                    lh = height[s.back()];
                    s.pop_back();
                }
                if(!s.empty()){
                    vol += (height[i] - lh) * (i - s.back() - 1);
                }
            }
            s.push_back(i++);
        }
        return vol;

    }
};
