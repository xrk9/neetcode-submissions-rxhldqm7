class Solution {
public:
    int uniquePaths(int m, int n) {
        // factorial(m+n-2) / factorial(m-1) * factorial(n-1)
        // (a+b)! / a! b!
        // (b+1) * (b+2) * ... (b+a) / a * (a-1) * (a-2) * 1
        // (b+1)/1 * (b+2)/2 * ... (b+a)/a
        long nPath = 1;
        --m; --n;
        if(m<n) swap(m,n);
        for(int i = 1; i<=n; i++){
            nPath*=(m+i);
            nPath/=i;
        }
        return static_cast<int>(nPath);
    }
};
