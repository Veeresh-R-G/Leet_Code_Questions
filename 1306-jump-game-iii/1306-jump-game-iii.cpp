class Solution {
public:
    
    bool isValid(int n , int ind , vector<int>& vis)
    {
        if(ind >= n || ind < 0 || vis[ind] == 0)
        {
            return true;
        }
        
        return false;
    }
    bool f(vector<int>& arr , int ind , int n ,vector<int>& vis)
    {
        if(ind >= n || ind < 0)
        {
            return false;
        }
        
        if(arr[ind] == 0)
        {
            return true;
        }
        /*
            
            dry run incase u forget why the Vis array is required       
            
        */
        
        vis[ind] = 1;
        
        int jumps = arr[ind];
        
        
        bool forward = isValid(n , ind + jumps , vis) ? f(arr , ind + jumps , n , vis) : false;
        
        if(forward) return true;
        
        bool backward = isValid(n , ind - jumps , vis) ? f(arr , ind - jumps , n , vis) : false;
        
        return backward || forward;
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        
 
        int n = arr.size();
        
        vector<int> vis(n , 0);
        return f(arr , start , n , vis);
    }
};