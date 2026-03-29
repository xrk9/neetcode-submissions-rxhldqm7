class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0 or n==1 or n==2) return 0;
        int vol = 0;
        stack <int> s;
        int i = 0;
        while(i<n && height[i] == 0) ++i;
        s.push(i++);
        while(i<n){
            if(height[i] == 0){
                ++i;
                continue;
            }
            if(height[i] < height[s.top()]){
                vol += height[i]*(i-s.top()-1);
            }else{
                int lh = 0;
                while(!s.empty() && height[i] >= height[s.top()]){
                    vol += (height[s.top()] - lh) * (i-s.top() -1);
                    lh = height[s.top()];
                    s.pop();
                }
                if(!s.empty()){
                    vol += (height[i] - lh) * (i - s.top() - 1);
                }
            }
            s.push(i++);
        }
        return vol;

    }
};
