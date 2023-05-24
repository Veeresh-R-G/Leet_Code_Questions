class Solution {
public:


    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int , int> m;

        for(auto it : nums)
        {
            m[it]++;
        }

        vector<pair<int , int>> v;

        for(auto& it : m)
        {
            v.push_back(it);
        }

        sort(v.begin() , v.end(), cmp);

        vector<int> ans;
        // for(auto it : v)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        for(int i = k - 1 ; i >= 0 ; i--)
        {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};