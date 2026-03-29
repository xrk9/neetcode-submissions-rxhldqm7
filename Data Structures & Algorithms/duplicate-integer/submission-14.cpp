class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int num: nums){
            auto it = find(s.begin(), s.end(), num);
            if(it != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};