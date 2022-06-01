class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        /*
        
            Time Complexity : O(n)
            Space Complexity : O(n)
            
            Used using DP approach
            Store the total of given vector in s
            
            then traverse the reverse way and keep subtracting the elements from the sum and keep pushing
            to the ans vector
            
            at last since we have the reverse ans vector
            
            we will reverse it again to obtain the correct order 
            return ans vector
        
        */
        vector<int> ans = {};
        
        int n = nums.size();
        
        int s = 0;
        
        for(auto it : nums)
        {
            s += it;
        }
        
        ans.push_back(s); //[10 , 10 -]
        int e = n -1; // e = 3
        
        while(e)
        {
            s = s - nums[e]; // 3 - nums[1] == 3 - 2 == 1
            
            ans.push_back(s);//{10 , 6 , 3 , 1}
            
            e--; // e = 0 break now
            
        }
        
        
        for(int i = 0 ; i < (ans.size() / 2) ;i++)
        {
            int temp = ans[i];
            ans[i] = ans[n- 1 - i];
            ans[n - 1 - i] = temp;
        }
        
        return ans;
    }
};