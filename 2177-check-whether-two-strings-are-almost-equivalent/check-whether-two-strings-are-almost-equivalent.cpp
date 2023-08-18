class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        int n = word1.size();
        vector<int> map1(26 , 0) , map2(26 , 0);

        for(auto it : word1){
            map1[it - 'a']++;
        }

        for(auto it : word2){
            map2[it - 'a']++;
        }

        int diff = 0;

        for(int i = 0 ; i < 26 ; i++){
            if(abs(map1[i] - map2[i]) > 3){
                return false;
            }
        }

        return true;


    }
};