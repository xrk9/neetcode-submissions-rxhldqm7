class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(const auto& str : strs){
            res+=str;
            res+=(char)(1);
        }
        return res;

    }

    vector<string> decode(string s) {
        vector<string> res;
        string str = "";
        for(const char& c : s){
            if(c != (char)1) {
                str+=c;
                continue;
            }
            res.emplace_back(str);
            str.clear();
        }
        return res;
    }
};
