class Solution {
private:
    int getNew(int n){
        int sum = 0;
        while(n){
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int> seen;
        while(true){
            seen.emplace(n);
            n = getNew(n);
            if(n==1) return true;
            else if(seen.contains(n)) return false;
        }
    }
};
