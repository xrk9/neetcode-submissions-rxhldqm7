class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // O(nlogn) Complexity
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n-1;
        int output = 0;
        while(j>i){
            if(people[i]+people[j] <= limit){
                ++output;
                ++i;--j;
            }
            else{
                ++output;
                --j;
            }

        }
        if(i==j){
            ++output;
        }
        return output;
        
    }
};