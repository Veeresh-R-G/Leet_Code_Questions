class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int Q = l.size();
        vector<bool> ans;
        for(int i = 0 ; i < Q ; i++)
        {
            int L = l[i];
            int R = r[i];
            
            if(L + 1 == R)
            {
                
                ans.push_back(true);
                continue;
            }
            
            bool flag = true;
            vector<int> temp(nums.begin() + L , nums.begin() + R + 1);
            
            
            
            sort(temp.begin() , temp.end());
            int diff = temp[1] - temp[0];
            // for(auto it : temp) cout << it << " ";
            for(int j = 2 ; j < temp.size() ;j++)
            {
                if(temp[j] - temp[j - 1] != diff)
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(true);
            else ans.push_back(false);
            
        }
        
        
        return ans;
    }
};