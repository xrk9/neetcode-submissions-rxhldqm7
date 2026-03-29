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
        for(;;){
            int m = i + ((n-i)>>1);
            int res = guess(m);
            if(res == 1){
                i = ++m;
            } else if (res == -1) {
                n = --m;
            } else {
                return m;
            }
        }
    }
};