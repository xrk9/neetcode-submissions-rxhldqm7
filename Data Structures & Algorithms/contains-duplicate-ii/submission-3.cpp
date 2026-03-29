class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        unordered_set<int> s;
        s.reserve(k);
        s.insert(nums[0]);
        for(int i = 1; i<k; i++){
            if(s.contains(nums[i])){
                return true;
            }
            s.insert(nums[i]);
        }
        int n = nums.size();
        for(int i = 0, j = k; j<n; i++, j++){
            if(s.contains(nums[j])){
                return true;
            }
            s.erase(nums[i]);
            s.insert(nums[j]);
        }
        return false;
    }
};