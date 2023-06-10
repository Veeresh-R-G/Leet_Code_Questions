class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        //flag indicates turns
        bool flag = true;
        int i = 0 , j = 0;
        int n = word1.size() , m = word2.size();
        string ans = "";

        while(i < n && j < m)
        {
            if(flag)
            {
                ans = ans + word1[i];
                i++;
            }
            else
            {
                ans = ans + word2[j];
                j++;
            }

            flag = !flag;
        }

        while(i < n)
        {
            ans = ans + word1[i++];
        }

        while(j < m)
        {
            ans = ans + word2[j++];
        }

        return ans;

    }
};