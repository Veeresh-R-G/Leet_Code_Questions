class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }

        if(s.size() == k){
            return true;
        }

        vector<int> freq(26, 0);
        int odd = 0;

        for(auto &c: s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2){
                odd++;
            }
        }

        // if odd occurences are greater than k
        //then we need atleast that many palindromes 
        //which are greater than K 
        return odd <= k;

    }
};