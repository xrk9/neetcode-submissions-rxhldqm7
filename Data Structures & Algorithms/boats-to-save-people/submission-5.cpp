class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int seen[30000] = {0};
        int n = people.size();
        for(int i = 0; i<n; i++){
            ++seen[people[i]-1];
        }
        int output = seen[limit-1];
        int i = 0, j = limit-2;
        while(j>i){
            if(seen[i] == 0){
                ++i;
                continue;
            }
            if(seen[j] == 0){
                --j;
                continue;
            }
            if((i+j+1)< limit){
                --seen[i];--seen[j];++output;
            }else{
                output+=seen[j];
                seen[j] = 0;
            }
        }
        int rem = seen[i];
        if(2*i+1 < limit ){
            while(rem>1){
                ++output;
                --rem;--rem;
            }
        }
        output+=rem;
        return output;
    }
};