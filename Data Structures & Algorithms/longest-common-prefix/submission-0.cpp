class Solution {
public:
    string cmp(string pre, string  str){
        int len = pre.size() > str.size() ? str.size() : pre.size();
        string prefix = "";
        for(int i = 0; i < len; i++){
            if( pre[i] != str[i] ) break;
            prefix += ( pre[i] );
        }
        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(string str:strs){
            prefix = cmp(prefix,str);
        }
        return prefix;
    }
};