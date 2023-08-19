class Solution {
public:
    string reverseParentheses(string s) {
        

        stack<char> st;
        string t = "";
        bool bracks = false;
        for(auto it : s){

            if(it == ')'){
                bracks = true;
                t = "";
                while(!st.empty() && st.top() != '('){
                    char currTop = st.top();
                    t = t + currTop;
                    st.pop();
                }

                st.pop();

                for(auto it : t){
                    st.push(it);
                }

            }else{
                st.push(it);
            }
        }

        
        if(!bracks){
            return s;
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
     
        return ans;
    }
};