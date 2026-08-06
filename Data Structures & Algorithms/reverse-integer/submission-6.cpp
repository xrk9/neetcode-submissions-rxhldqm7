class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool neg = x<0;
        int mod = 0;
        while(x){
            mod = x%10;
            res = res*10 + mod;
            x/=10;
        }
        if(mod != res%10) return 0;

        return res;
    }
};