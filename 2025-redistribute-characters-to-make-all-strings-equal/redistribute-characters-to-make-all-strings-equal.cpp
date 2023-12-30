class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int N = words.size();
        unordered_map<char, int> mp;

        for(auto word: words){
            for(auto letter: word){
                mp[letter]++;
            }
        }


        for(auto it: mp){
            if(it.second % N != 0){
                return false;
            }
        }

        return true;
    }
};