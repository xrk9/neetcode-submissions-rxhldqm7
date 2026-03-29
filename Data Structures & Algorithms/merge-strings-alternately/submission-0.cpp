class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.empty()) return word2;
        if(word2.empty()) return word1;
        int a = word1.size(), b = word2.size(), i = 0, j = 0;
        string s = "";
        s.reserve(a+b);
        while(i<a || j<b){
            if( i<a ) s+= word1[i++];
            if( j<b ) s+= word2[j++];
        }
        return s;
    }
};