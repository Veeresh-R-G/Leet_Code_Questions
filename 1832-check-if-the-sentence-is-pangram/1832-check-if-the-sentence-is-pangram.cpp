class Solution {
public:
    bool checkIfPangram(string sen) {
        
        map<char , bool> m;
        
        int n = sen.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            m[sen[i]] = true;
        }
        
        
        return m.size() == 26;
        
    }
};