class Solution {
public:
    string decodeString(const string& s) {
        int n = s.size();
        string output = "";
        int i = 0;

        while(i < n){
            while(i < n && s[i] > 96){
                output += s[i++];
            }
            if(i == n) return output;

            string number = "";
            while(i < n && s[i] < 58){
                number += s[i++];
            }
            int num = number.empty() ? 1 : stoi(number);

            int c = 1;
            int j = i;
            while(++j){
                if(s[j] == '[') ++c;
                else if(s[j] == ']') --c;
                if(c == 0) break;
            }

            string sub = decodeString(s.substr(i + 1, j - i - 1));
            
            while(num--) {
                output += sub;
            }
            i = j + 1;
        }
        return output;
    }
};