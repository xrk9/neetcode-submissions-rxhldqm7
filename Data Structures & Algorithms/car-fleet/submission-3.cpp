class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n==0 || n==1) return n;

        pair<int,float>* ps = new pair<int,float>[n];

        for(int i = 0; i<n; i++){
            int rem = target - position[i];
            ps[i].first = rem;
            ps[i].second = (float)rem / speed[i];
        }

        sort(ps, ps+n);

        int fleet = 0;
        float lastTime  = -1.0d;
        for(int i = 0; i<n; i++){
            if(ps[i].second > lastTime){
                lastTime = ps[i].second;
                ++fleet;
            }
        }
        delete[] ps;
        return fleet;
    }
};