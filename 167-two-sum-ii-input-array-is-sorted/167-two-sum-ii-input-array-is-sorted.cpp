class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int s = 0;
        int e = n.size() - 1;
        vector<int> ans;
        while(s != e)
        {
            if(n[s] + n[e] > t){
                e = e - 1;
            }
            else if(n[s] + n[e] < t){
                s += 1;
            }
            else
            {
                ans.push_back(s + 1);
                ans.push_back(e + 1);
                break;
            }
        }
        return ans;
    }
};