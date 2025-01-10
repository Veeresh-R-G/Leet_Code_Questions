class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
       vector<string> ans;
    vector<int> maxFreq(26, 0);

    // this will be constant for every A word
    for (auto &B : words2)
    {
        vector<int> temp(26, 0);

        for (auto &a : B)
        {
            temp[a - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            maxFreq[i] = max(maxFreq[i], temp[i]);
        }
    }

    for (auto &A : words1)
    {

        vector<int> freq1(26, 0);

        for (auto &c : A)
        {
            freq1[c - 'a']++;
        }

        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] < maxFreq[i])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans.push_back(A);
        }
    }

    return ans;
    }
};