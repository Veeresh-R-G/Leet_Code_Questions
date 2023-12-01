class Solution {

private:
    void helper(vector<string>& arr, string& s){

        for(auto it : arr){
            s += it;
        }
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s1 = "";
        string s2 = "";

        helper(word1, s1);
        helper(word2, s2);

        return s1 == s2;

        
    }
};