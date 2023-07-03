class Solution {
public:
    bool buddyStrings(string s, string goal) {
       //Ascii Thing didn't work because both can have the same string
       //so on swapping any of those we will not reach goal
        int n = s.size();
        int m = goal.size();

        if(n != m)
        {
            return false;
        }

        if(s == goal)
        {
            vector<int> a(26 , 0);

            for(auto it : s)
            {
                a[it - 'a']++;
                if(a[it - 'a'] == 2)
                {
                    //aab <--> aba case
                    return true;
                }
            }
            
            //ab <---> ab case
            return false;
        }

        int ind1 = -1 , ind2 = -1;
        for(int i = 0; i < s.size() ; i++)
        {
            if(s[i] != goal[i])
            {
                if(ind1 == -1)
                {
                    ind1 = i;
                }

                else if(ind2 == -1)
                {
                    ind2 = i;
                }

                else
                {
                    //third point of differnce
                    return false;
                }
            }
        }

        //only 1 difference
        if(ind2 == -1) return false;

        return s[ind1] == goal[ind2] && s[ind2] == goal[ind1];


       

    }
};