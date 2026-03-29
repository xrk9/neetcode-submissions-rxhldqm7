class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if ( n != t.size()) return false;
        vector<int> frequency(26);
        for(int i = 0; i<n; i++){
            frequency[s[i] - 97]++;
            frequency[t[i] - 97]--;
        }
        for(int i = 0; i<26; i++){
            if(frequency[i] != 0) return false;
        }
        return true;
    }
};
