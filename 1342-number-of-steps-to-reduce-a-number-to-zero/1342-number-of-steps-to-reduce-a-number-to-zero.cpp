class Solution {
public:
    int numberOfSteps(int num) {
        
        int c = 0;
        
        while(num != 0)
        {
            num = num % 2 ? num -1 : num / 2;
            c += 1;
        }
        
        return c;
    }
};