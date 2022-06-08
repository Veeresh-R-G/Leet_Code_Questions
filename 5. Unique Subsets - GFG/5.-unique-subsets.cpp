// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>>  ans;
    
    set<vector<int> > mySet;
    
    void solve(int ind , vector<int> inp , vector<int>& out)
    {
        if(ind >= inp.size())
        {
           ans.push_back(out);
           vector<int> t = out;
          sort(t.begin () , t.end());
          mySet.insert(t);
            
            return;
        }
        
        out.push_back(inp[ind]);
        solve(ind + 1 , inp , out);
        
        out.pop_back();
        solve(ind + 1 , inp , out);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        
        int i = 0;
        vector<int> out = {};
        
        solve(i , arr , out);
        
        // for(auto item : ans)
        // {
        //     for(auto ele : item)
        //     {
        //         cout << ele << " - ";
        //     }
        //     cout << "\n";
        // }
        
        
        // cout << "------------------------------------------------------------\n";
        vector<vector<int>> A;
        for (auto it = mySet.begin() ; it != mySet.end() ; it++) 
         {
  
                vector<int> temp = (*it);
                
                A.push_back(temp);
                // cout << endl;
        }
    
        
        return A;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends