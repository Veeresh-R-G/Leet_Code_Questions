class Solution {
public:
    int minimumLength(string s) {
        
        int del = 0;
        unordered_map<char, int> umap;

        for(auto &c: s){
            umap[c]++;
        }

        for(auto it: umap){
            if(it.second % 2){
                del += it.second - 1;
            } else{
                del += it.second - 2;
            }
        }

        return s.size() - del;
        
    }
};