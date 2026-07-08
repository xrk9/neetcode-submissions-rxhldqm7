class Solution {
public:
    bool checkValidString(string s) {
        int leftmin = 0, leftmax = 0;
        for(const char& c : s){
            switch (c){
                case ')':
                    leftmax--;
                    leftmin--;
                    break;
                case '(':
                    leftmax++;
                    leftmin++;
                    break;
                default:
                    leftmax++;
                    leftmin--;
            }
            if(leftmin < 0) leftmin=0;
            if(leftmax < 0) return false;
        }
        if(leftmin > 0) return false;
        return true;
    }
};
