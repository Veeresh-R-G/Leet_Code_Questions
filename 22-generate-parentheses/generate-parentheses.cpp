class Solution {

vector<string> ans;

void solve(int n , int left , int right , string temp){
    if(temp.size() == 2 * n){
        ans.push_back(temp);
        return;
    }


    if(left){
        solve(n , left - 1 , right , temp + '(');
    }


    //To Avoid : )( )( 
    if(right > left){
        solve(n , left , right - 1 , temp + ')');
    }
}
public:
    vector<string> generateParenthesis(int n) {
        

        string temp = "";
        int left = n;
        int right = n;
        solve(n , left , right , temp);
        return ans;
    }
};