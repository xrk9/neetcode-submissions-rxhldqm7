class Solution {
public:
    int reverse(int x) {
        bool neg = x<0?true:false;
        if(neg)
            x = -1*x;
        long res = 0;
        while(x>0)
        {
            int mod = x%10;
            res = 10*res + mod;
            x/=10;
        }
        if(res  < numeric_limits<int>::min() || res > numeric_limits<int>::max())
            return 0;
        return neg?-1*res:res;
    }
};