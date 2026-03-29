class Solution {
private:
    bool valid(const vector<int>& piles,const int& n, const int& h, const int& k){
        int t = 0;
        for(int i = 0; i<n; i++){ 
            t += (piles[i] + k - 1)/k;
            if(t>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(const vector<int>& piles, const int& h) {
        int n = piles.size();
        int mx = piles[0];
        for(int i = 1; i<n; i++){
            if(piles[i] > mx) mx = piles[i];
        }

        int mn = 1;
        int k = mx;
        while(mn<=mx){
            int m = mn + ((mx-mn)>>1);
            if(valid(piles, n, h, m)){
                k = m;
                mx = --m;
            }else{
                mn = ++m;
            }
        }
        return k;
    }
};
