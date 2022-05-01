class Solution {
public:
    string reducedString(string s){
        int n = s.length();
        
        stack<char> st;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] != '#'){
                    st.push(s[i]);
                
                continue;
                
            }
            else{
               if(!st.empty()){
                   st.pop();
               } 
                continue;
                
                
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            char temp = st.top();
            ans += temp;
            st.pop();
        }
        return ans;
    }
    
    bool backspaceCompare(string s, string t) {
        
        string ans1 = reducedString(s);
        string ans2 = reducedString(t);
        // cout << ans1 << " " << ans2 <<  endl;
        
        int i = 0 ;
            
        if(ans1.length() != ans2.length()){
            return false;
        }
        
        while(i < ans1.length()){
            if(ans1[i] != ans2[i]){
                return false;
            }
            i++;
        }
        
        
        return true;
    }
};