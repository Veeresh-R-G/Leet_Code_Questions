class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string, string>mp;

        for(auto path: paths){
            mp[path[0]] = path[1];
        }

        string currCity = paths[0][0];

        while(true){

            if(mp.find(currCity) != mp.end()){
                currCity = mp[currCity];
            }
            else{
                return currCity;
            }
        }

        return "";
    }
};