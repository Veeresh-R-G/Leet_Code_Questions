class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        vector<vector<string>> ans;
        
        
        for(int i = 0 ; i < ans.size() ; i++)
        {
            vector<int>(26 , 0);
            
        }
        
        map<vector<int> , vector<string>> mp;
        
        for(auto it :strs)
        {
            vector<int> v(26 , 0);
            for(auto ele : it)
            {
                v[ele - 'a']++;
            }
            
            mp[v].push_back(it);
        }
        
        for(auto it : mp)
        {
            vector<string> temp;
            for(auto ele : it.second)
            {
                temp.push_back(ele);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};