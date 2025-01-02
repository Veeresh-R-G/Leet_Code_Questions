class Solution {
public:
    unordered_map<char, int> umap;
    

    bool helper(string word){
        
        int n = size(word);
        if(umap.find(word[0]) != umap.end() && umap.find(word[n - 1]) != umap.end()){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        umap['a'] = 1;
        umap['e'] = 1;
        umap['i'] = 1;
        umap['o'] = 1;
        umap['u'] = 1;

        int n = words.size();
        int sum = 0;
        
        vector<int> ans;
        vector<int> prefix(n, 0);
        
        for(int i = 0; i < n; i++){
            if(helper(words[i])){
                sum++;
            }
            prefix[i] = sum;
        }

        
        for(auto &query: queries){
            int l = query[0];
            int r = query[1];
            if(l == 0){
                ans.push_back(prefix[r]);
            } else{
                ans.push_back(prefix[r] - prefix[l - 1]);
            }
        }

        return ans;
    }
};