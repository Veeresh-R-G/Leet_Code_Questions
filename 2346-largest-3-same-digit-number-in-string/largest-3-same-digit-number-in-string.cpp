class Solution {

private:
    bool checkSeq3(string& s){
        return s[0] == s[1] && s[1] == s[2] && s[2] == s[0];
    }

public:
    string largestGoodInteger(string num) {
        
        int n = num.size();

        if(n == 3){
            return checkSeq3(num) ? num : "";
        }

        //works for Size > 3
        string ans = "";
        for(int i = 0 ; i <= n - 3; i++){
            string temp = num.substr(i , 3);
            if(checkSeq3(temp)){
                if(ans == ""){
                    ans = temp;
                }
                else{
                    ans = temp[0] > ans[0] ? temp : ans;
                }
            }
        }    

        return ans;
    }
};