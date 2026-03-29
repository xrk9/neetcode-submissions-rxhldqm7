class Solution {
private:
    bool is(string s, int i){
        if((s[i] == '%') && (s[i+1] == '+') && (s[i+2] == '%')) return true;
        return false;
    }
public:

    string encode(vector<string>& strs) {
        string output = "";
        string adder = "%+%";
        for(string const& s:strs){
            output += s;
            output += adder;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int size = s.length();
        int i = 0;
        string str = "";

        while(i<size){
            if(is(s,i)){
                output.push_back(str);
                str = "";
                i+=3;
            }else{
                str += s[i];
                i++;
            }
        }
        return output;
    }
};












