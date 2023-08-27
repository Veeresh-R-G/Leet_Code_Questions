class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
    vector<int> ans;
    for(int i = 0 ; i < asteroids.size() ; i++){


        //right - side
        if(st.empty() || asteroids[i] > 0){
            st.push(asteroids[i]);
        }

        //left side
        else{

           while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
               st.pop();
           }

           if(!st.empty() && (st.top()) == abs(asteroids[i])){
               st.pop();
           }

           else{
               if(st.empty() || st.top() < 0){
                   st.push(asteroids[i]);
               }
           }
        //    st.push(asteroids[i]);
            
        }

       
    }

    while(!st.empty()){
            int t = st.top();
            st.pop();

            ans.push_back(t);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};