class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        unordered_map<char , int> mp;

        int n = answerKey.size();
        int left = 0;
        int maxi = 0;
        for(int right = 0; right < n ; right++)
        {
            mp[answerKey[right]]++;

            while(min(mp['T'] , mp['F']) > k)
            {
                mp[answerKey[left]]--;
                left++;
            }

            maxi = max(maxi , right - left + 1);
        }

        return maxi;

        

    }
};