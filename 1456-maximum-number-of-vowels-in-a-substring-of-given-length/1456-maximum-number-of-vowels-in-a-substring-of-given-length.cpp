class Solution {
public:
    int maxVowels(string s, int k) {
        
        int N = s.size();
        
        
        /*
            Brute Force : O(N^2)
        */
        
        //Optimise using sliding window
        
        //Pre-process
        int ans = 0;
        for(int i = 0 ; i < k ;i++)
        {
            char it = s[i];
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
            {
                    ans++;
            }
        }
        
        
        int max_in_window = ans;
        //Sliding window here
        for(int i = k ; i < N ; i++)
        {
            char curr = s[i];
            char start = s[i - k];
            
            if(curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
            {
                max_in_window++;
            }
            if(start == 'a' || start == 'e' || start == 'i' || start == 'o' || start == 'u')
            {
                max_in_window--;
            }
            // cout << max_in_window << endl;
            ans = max(ans , max_in_window);
           
        }
      
        return ans;
    }
};