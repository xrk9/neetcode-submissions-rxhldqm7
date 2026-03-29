class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int i = 0, j = size-1;
        while(i<j){
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;j--;
        }
    }
};