#include <cstdlib>
#include <string>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        int n = ops.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++)
        {
            string temp = ops[i];
            
            if(temp == "C"){
                
                ans.pop_back();
            }
            
            else if(temp == "D"){
                int num = ans[ans.size() -1];
                // ans.pop_back();
                ans.push_back(num * 2);
                // ops.pop_back();
                // ops.push_back(num * 2); --> here is the error
                //  it is vecotr of strings but i am pushing int adeke not working
             }
            
            else if(temp == "+"){
                int n1 = ans[ans.size() - 1];
                int n2 = ans[ans.size() - 2];
                // ans.pop_back();
                // ans.pop_back();                
                ans.push_back(n1 + n2);
            }
            
            else{
                ans.push_back(stoi(temp));
            }
        }
        int ansSum = 0;
        
        for(int i = 0 ; i < ans.size() ;i++){
            ansSum += ans[i];
        }
        return ansSum;
        
    }
};