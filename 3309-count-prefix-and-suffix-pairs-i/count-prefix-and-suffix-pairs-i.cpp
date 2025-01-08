class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int cnt = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                string str1 = words[i];
                string str2 = words[j]; 
                if (str2.find(str1) == 0 &&
                    str2.rfind(str1) == str2.size() - str1.size()) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};