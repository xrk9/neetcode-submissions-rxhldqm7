class Solution {
public:
    int maxArea(vector<int>& H) {
        int n = H.size();
        int l = 0, r = n-1;
        int M = 0;
        while(l<r){
            int height = min(H[l], H[r]);
            int water = height * (r-l);
            if(water > M) M = water;
            H[l] > H[r] ? r-- : l++;
        }
        return M;
    }
};
