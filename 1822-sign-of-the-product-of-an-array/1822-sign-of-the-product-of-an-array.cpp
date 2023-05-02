class Solution {
public:
    
    int signFunc(int ele)
    {        
        return ele > 0 ? 1 : -1;
    }
    
    int arraySign(vector<int>& nums) {
        
        int pro = 1;
        
        for(auto it : nums)
        {
            if(it == 0) return 0;
            pro = pro * signFunc(it);
        }
        
        return pro;
    }
};