class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
        {
            return nums.size();
        }


        set<int> s;
        vector<int> v;
        for(auto it : nums)
        {
            s.insert(it);
        }

        for(auto it : s)
        {
            v.push_back(it);
        }

        int N = v.size();
        int ans = 0;
        int tempLen = 1;
        int i = 1;

        while(i < N)
        {
            if(abs(v[i] - v[i - 1]) == 1)
            {
                tempLen++;
                i++;
            }
            else
            {
                i++;
                ans = max(ans , tempLen);
                tempLen = 1;
            }
        }

        //Since it wont consider after last comparison 
        ans = max(ans , tempLen);
        return ans;



        return s.size();
    }
};