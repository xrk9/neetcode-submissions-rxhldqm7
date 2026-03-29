#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> a;
        for(int n:nums){
            for(int b:a){
                if( b == n ){
                    return true;
                }
            }
            a.push_back(n);
        }
        return false;
    }
};