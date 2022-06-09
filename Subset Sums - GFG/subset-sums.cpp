// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(int i , vector<int> inp , vector<int> & out , vector<int>& sum)
    {
        if(i >= inp.size())
        {
            int s= 0;
            for(auto ele : out)
            {
                s += ele;
            }
            
            sum.push_back(s);
            
            return;
        }
        
        
        out.push_back(inp[i]);
        solve(i + 1 , inp , out , sum);
        
        out.pop_back();
        solve(i + 1 , inp , out ,sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int ind = 0;
        vector<int> out;
        
        vector<int> sum;
        
        
        solve(ind , arr , out , sum);
        
        sort(sum.begin() , sum.end());
        return sum;
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