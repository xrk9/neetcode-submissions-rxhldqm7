class Solution {
public:
    string simplifyPath(string path) {
        path+="/";
        int n = path.size();
        vector<string> st;
        int dir = -1;
        for(int i = 0; i<n; i++){
            if(path[i] == '/'){
                if(i-1 != dir){
                    string s = path.substr(dir+1,i-dir-1);
                    if(s == ".."){
                        if(!st.empty()){
                            st.pop_back();
                        }
                    } else if(s == "."){
                    } else {
                        st.push_back(s);
                    }
                } dir = i;
            }
        }
        if(st.empty()) return "/";
        string output = "";
        for(const string& s: st){
            output += '/';
            output+=s;
        }
        return output;

    }
};