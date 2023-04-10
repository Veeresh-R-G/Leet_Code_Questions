class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
        {
            return true;
        }
        
        stack<char> st;
        
        int n = s.length();
        
        for(int i = 0 ; i < n ; i++)
        {
            char temp = s[i];
            
            if(temp == '{' || temp == '(' || (temp == '['))
            {
                st.push(temp);              
            }
                   
            else
            {
                //here is closing brackets
                
                if(st.size() == 0)
                {
                    return false;
                }
                char pChar = st.top();
                st.pop();
                
                if(temp == ')')
                {
                    if(pChar != '(')
                    {
                        return false;
                    }
                }
                
                
                else if(temp == '}')
                {
                    if(pChar != '{')
                    {
                        return false;
                    }
                }
                
                
                else if(temp == ']')
                {
                    if(pChar != '[')
                    {
                        return false;
                    }
                }
            }
        }
        
        if(st.size() == 0)
        {
            return true;
        }
        return false;
        
    }
};