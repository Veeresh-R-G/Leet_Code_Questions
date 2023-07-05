class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int prevSum = -1;
        int currSum = 0;
        int ans = INT_MIN;

        vector<int> temp;

        int i = 0;
        int ones = 0;
        bool zero = false;
        //keep track of ones after and before 0
        //problem --> Cnt keep track f ones aftr a 0

        for(int i = 0 ; i < nums.size() ; i++)
        {
           if(nums[i] == 1)
           {
               ones++;
           }
           else
           {
               zero = true;
               temp.push_back(ones);
               ones = 0;
           }
        }

        if(!zero)
        {
            return nums.size() - 1;
        }
        temp.push_back(ones);
        for(auto it : temp)
        {
            cout << it << " -- ";
        }
        cout << endl;
        for(int i = 1 ; i < temp.size() ; i++)
        {
            ans = max(ans , temp[i - 1] + temp[i]);
        }

        return ans == INT_MIN ? 1 : ans;

    }
};