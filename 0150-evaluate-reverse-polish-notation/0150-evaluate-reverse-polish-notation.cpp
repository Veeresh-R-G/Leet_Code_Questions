
using namespace std;
class Solution {
public:
    
    bool isOperator(string op)
    {
        return op == "*" || op == "/" || op == "+" || op == "-";
    }
    
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        
        if(n == 1)
        {
            string ans = tokens[0];
            return stoi(ans);
        }
        
        long long ans = 0;
        
        stack<long long> st;        
        for(int i = 0 ; i < n ; i++)
        {
            string ele = tokens[i];
            
            if(isOperator(ele))
            {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(ele == "-")
                {
                    ans = (num2 - num1);
                }
                else if(ele == "*")
                {
                    ans = (num2 * num1);
                }
                else if(ele == "/")
                {
                    ans = (num2 / num1);
                }
                else
                {
                    ans = (num2 + num1);
                }
                
                st.push((ans));
            }
            else
            {
                st.push(stoi(ele));
            }
        }
        
        
        return ans;
        
    }
};