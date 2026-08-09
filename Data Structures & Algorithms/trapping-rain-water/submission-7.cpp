class Solution {
public:
    int trap(vector<int>& H) {
        int n = H.size();
        if(n<2) return 0;
        int l = 1, r = n-2;
        int lm = H[0], rm = H[n-1];
        int water = 0;
        while(l <= r){
            if(lm < rm){
                if(H[l] >= lm) lm = H[l];
                else{
                    int w = lm-H[l];
                    water += (w > 0) ? w : 0;
                }
                l++;
            }else{
                if(H[r] >= rm) rm = H[r];
                else{
                    int w = rm - H[r];
                    water+= (w>0) ? w : 0;
                }
                r--;
            }
        }
        return water;
    }
};
