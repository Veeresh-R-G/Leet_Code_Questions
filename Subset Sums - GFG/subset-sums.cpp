// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> inp , vector<int>&ans , int ind , int sum)
    {
        if(ind >= inp.size())
        {
            
            ans.push_back(sum);
            return;
        }
        
        
        sum += inp[ind];
        solve(inp , ans , ind + 1 , sum);
        
        sum -= inp[ind];
        solve(inp , ans , ind + 1 , sum);
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        int sum = 0 , ind = 0;
        
        vector<int> ans;
        
        solve(arr , ans, ind , sum);
        
        sort(ans.begin() , ans.end());
    return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends