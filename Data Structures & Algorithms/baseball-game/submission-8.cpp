class Solution {

private:
    int s2i(string s){
        int output = 0;
        int n = s.size();
        int i = 0;
        bool mask = 0;
        if(s[0] == '-'){
            mask = 1;
            i = 1;
        }
        for(;i<n; i++){
            output=10*output + s[i] - '0';
        }
        return (mask?-output:output);
    }

public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int arr[n];
        int q = -1;
        for(int i = 0; i<n; i++){
            char c = operations[i][0];
            switch(c){
                case '+':
                    arr[++q] = arr[q] + arr[q-1];
                    break;
                case 'D':
                    arr[++q] = arr[q]<<1;
                    break;
                case 'C':
                    --q;
                    break;
                default :
                    arr[++q] = s2i(operations[i]);
                    break;
            }

        }
        int s = 0;
        for(int k = 0; k<=q; k++){
            s+=arr[k];
        }
        return s;
    }
};