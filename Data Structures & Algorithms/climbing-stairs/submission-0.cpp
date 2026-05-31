class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int nWays[46] = {0};
        nWays[1] = 1; nWays[2] = 2;
        for(int i = 3; i<=n; i++){
            nWays[i] = nWays[i-1] + nWays[i-2];
        }
        return nWays[n];
    }
};
