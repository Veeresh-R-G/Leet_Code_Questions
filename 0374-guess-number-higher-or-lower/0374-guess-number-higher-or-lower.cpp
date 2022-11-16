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
        
      
        int s = 1;
        int e = n ;
        /*
            s / 2 + e / 2 + s / 2 - s / 2;
            
            ==> (e - s) / 2 + s
        */
        while(s <= e)
        {
            int mid = ((e - s) / 2) + s;
            
            if(guess(mid) == 0)
            {
                return mid;
            }
            
            else if(guess(mid) == -1)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            
        }
        return n;
    }
};