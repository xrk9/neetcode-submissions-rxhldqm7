auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int arr[n];
        int pointer = -1;
        for(int i = 0; i<n; i++){
            char c = tokens[i][tokens[i].size() - 1];
            switch(c){
                case '+':
                    arr[--pointer] = arr[pointer - 1] + arr[pointer];
                    break;
                case '*':
                    arr[--pointer] = arr[pointer - 1] * arr[pointer];
                    break;
                case '-':
                    arr[--pointer] = arr[pointer - 1] - arr[pointer];;
                    break;
                case '/':
                    arr[--pointer] = arr[pointer - 1] / arr[pointer];
                    break;
                default:
                    arr[++pointer] = stoi(tokens[i]);
                    break;

            }
        }
        return arr[0];
    }
};
