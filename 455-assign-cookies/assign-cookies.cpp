class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int N = g.size();
        int M = s.size();

        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < N && j < M){

            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return ans;

    }
};