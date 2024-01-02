class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<vector<int>> ans;
        unordered_map<int, int> ump;

        for(auto it: nums){
            ump[it]++;
        }

        while(!ump.empty()){
            vector<int> temp, tempo;

            //by reference will update the map 
            for(auto &it: ump){
                temp.push_back(it.first);
                it.second--;

                if(it.second == 0){
                    tempo.push_back(it.first);
                }
            }

            for(auto it: tempo){
                ump.erase(it);
            }

            ans.push_back(temp);
        }

        return ans;




    }
};