class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int c = 0;
        while(n > 0 && (n >= i))
        {
            n = n - i;
            i = i + 1;
            c += 1;
        }
        
        return c;
    }
};