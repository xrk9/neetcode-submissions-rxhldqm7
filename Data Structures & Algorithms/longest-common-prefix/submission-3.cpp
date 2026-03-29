class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        string last = strs[0];
        for(string str:strs){
            if(first < str) first = str;
            if(last > str) last = str;
        }

        int len = first.size() < last.size() ? first.size() : last.size();
        int i = 0;
        while(i < len && first[i] == last[i]) i++;
        return first.substr(0,i);
    }
};