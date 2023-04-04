class Solution {
public:
    int partitionString(string s) {
        
        
        /*
        
            Two pointer will not work : 
            aabbc
            will just compare the first character with the substring that I am checking
            Will not take care of the inner characters
            
            
        */
        
        vector<int> seen(26 , -1);
        
        int cnt = 1;
        int substringStart = 0;
        
        int N = s.size();
        
        /*
        
        
            we require the >= if the starting char is not same as the endng char which
            is repeating in between
            
            for example : 
            aabbc
            
            a ab bc
            
            after the first partition a is formed
            then ab and then when we come to b(from bc)
            since starting char is a and repeated char is b which is repeated internally
            
            we require the greater than case
            
            Takes care of the two pointer solution that I was not handling!!
        */
        for(int i = 0 ; i < N ; i++)
        {
            if(seen[s[i] - 'a'] >= substringStart)
            {
                cnt++;
                substringStart = i;
            }
            seen[s[i] - 'a'] = i;
        }
        
        return cnt;
    }
};