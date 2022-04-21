#include <bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
       int rev = 0;
        bool neg = false;
        neg = x < 0 ? true : false;
        if(neg)
        {
            if(x > (INT_MIN))
            {
                 x = x * -1;
            }
           
            else
            {
                return 0;
            }
        }
        int temp = x;
        while(temp)
        {
            int ld = temp % 10;
            if(rev > ((INT_MAX)/10))
            {
                return 0;
            }
            else
            {
                rev = rev * 10 + ld;
                temp = temp / 10;
            }            
        }
        
        if(neg)
        {
            return rev * -1;
        }
        else
        {
            return rev;
        }
        
    
    }
};