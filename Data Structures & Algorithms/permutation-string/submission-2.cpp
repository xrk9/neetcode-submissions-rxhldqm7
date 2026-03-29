class Solution {
public:
    bool isZero(const int a[]){
        for(int i = 0; i<26; i++){
            if(a[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        int count[26] = {0};
        for(int i = 0; i<n1; i++){
            ++count[s1[i]-'a'];
        }
        int i = 0;
        int j = 0;
        for(; j<n1; j++){
            --count[s2[j]-'a'];
        }
        if(isZero(count)) return true;

        while(j<n2){
            --count[s2[j++]-'a'];
            ++count[s2[i++]-'a'];
            if(isZero(count)) return true;
        }
        return false;
    }
};
