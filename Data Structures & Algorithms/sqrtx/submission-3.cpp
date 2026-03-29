class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int digits[] = {1,10,100,1000,10000,100000};
        int d = 0;
        long tmp = x;
        while(tmp){
            tmp/=10;
            ++d;
        }
        d = (d-1)/2;
        int i = digits[d], j = digits[d+1];
        while(i<=j){
            int m = (i+j)>>1;
            tmp = (long)m * (long)m;
            if( x < tmp){
                j = --m;
            } else if ( x > tmp){
                i = ++m;
            } else {
                return m;
            }

        }
        return j;
    }
};