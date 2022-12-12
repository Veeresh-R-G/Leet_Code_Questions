class Solution {
public:
    
    
    int f(int n , vector<int>& v)
    {
        if(n == 1 || n == 0)
        {
            return 1;
        }
        if(n < 0) return 0;
        
        if(v[n] != -1) return v[n];
        
        return v[n] = f(n - 1 , v) + f(n - 2,v);
    }
    
    int climbStairs(int n) {
        
        vector<int> v(n + 1 , -1);
        return f(n , v);
    }
};