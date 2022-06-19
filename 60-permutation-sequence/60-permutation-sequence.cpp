class Solution {
public:
    
    int factN_1(int n)
    {
        int f = 1;
        for(int i = 1 ; i < n ; i++)
        {
            f = f * i;
        }
        
        return f;
    }
    string getPermutation(int n, int k) {
        
        
        int fact = factN_1(n);
        
        
        vector<int> v;
        
        for(int i = 1 ; i <= n ; i++)
        {
            v.push_back(i);
        }
        string s = "";
        k = k - 1;
        while(true)
        {
            s += to_string(v[ k / fact ]);
            v.erase(v.begin() + (k / fact));
            if(v.size() == 0)
            {
                break;
            }
            
            k = k % fact;
            fact = fact / v.size();
            
        }
        
        return s;
    }
};