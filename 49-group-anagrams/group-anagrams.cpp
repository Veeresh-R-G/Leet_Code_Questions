class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.size() == 1){
            return {{strs[0]}};
        }

        

        vector<vector<string>> ans;
        map<vector<int> , vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++){

            vector<int> hash(26 , 0);

            for(auto it : strs[i]){
                hash[it - 'a']++;
            }

            if(mp.find(hash) != mp.end()){
                mp[hash].push_back(strs[i]);
            }
            else{
                mp[hash] = {strs[i]};
            }

        }

        for(auto it : mp){
            vector<string> temp;
            for(auto j : it.second){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};