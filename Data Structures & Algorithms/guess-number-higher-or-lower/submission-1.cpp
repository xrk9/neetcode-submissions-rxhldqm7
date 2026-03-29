/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        while(i<=n){
            int m = i + (n-i)/2;
            int res = guess(m);
            if(res == 0){
                return m;
            } else if (res > 0) {
                i = m + 1;
            } else {
                n = m - 1;
            }
        }
    }
};