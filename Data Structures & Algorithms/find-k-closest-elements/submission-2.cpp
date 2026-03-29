class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int id = 0;
        while(id<n && arr[id]<x){
            ++id;
        }
        if(id == n){
            return vector<int> (arr.end() -k, arr.end());
        }
        if(id == 0){
            return vector<int> (arr.begin(), arr.begin()+k);
        }
        int l = id-1, r = id;
        while(k > 0){
            if(((x - arr[l]) <= (arr[r] - x)) && l>=0){
                --l;
            }else{
                ++r;
            }
            --k;
        }while(k>0){
            --l;
        }
        return vector<int> ( arr.begin() + l + 1, arr.begin() + r);
    }
};