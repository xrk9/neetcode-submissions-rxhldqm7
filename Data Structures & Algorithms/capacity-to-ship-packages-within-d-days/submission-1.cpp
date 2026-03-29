class Solution {
private:
    bool valid(const vector<int>& weights, const int& n, const int& days, const int& w){
        int d = 1, i = 0, mx = w;
        while(i<n){
            if(weights[i] < mx){
                mx -= weights[i++];
            }
            else {
                mx = w;
                ++d;
            }
            if(d>days) return false;
        }
        return true;
    }
public:
    int shipWithinDays(const vector<int>& weights, const int& days) {
        int n = weights.size();
        int mn = weights[0];
        int mx = weights[0];
        for(int i = 0; i<n; i++){
            mx+=weights[i];
            if(weights[i] > mn) mn = weights[i];
        }
        int w = mx;
        while(mn <= mx){
            int m = mn + ((mx-mn)>>1);
            if(valid(weights,n,days,m)){
                w = m;
                mx = --m;
            }else{
                mn = ++m;
            }
        }
        return w-1;
    }
};