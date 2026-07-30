class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; 

        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end());
        
        int diff = num1.size() - num2.size();
        
        if(diff >= 0) {
            while(diff--) num2 += '0';
        } else {
            diff = -diff; 
            while(diff--) num1 += '0';
        }
        
        int carry = 0;
        string res;
        int n = num1.size();
        
        for(int i = 0; i < 2 * n - 1; i++){
            int start = max(0, i - n + 1);
            int end = min(i, n - 1);
            
            for(int j = start; j <= end; j++){
                carry += ((num1[j]-'0') * (num2[i-j]-'0'));
            }
            res += ('0' + carry % 10);
            carry /= 10;
        }
        
        while(carry){
            res += ('0' + (carry % 10));
            carry /= 10;
        }
        
        while(res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};