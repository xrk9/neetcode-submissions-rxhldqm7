class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int m = nums[0];
        int nJ = 1;
        int newmax = m;
        
        for(int i = 1; i < n; i++){
            if(m >= n - 1) return nJ;
            newmax = max(newmax, i + nums[i]);
            if(i == m){
                nJ++;
                m = newmax;
            }
        }
        return nJ;
    }
};