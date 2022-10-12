//{ Driver Code Starts
// Initila Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int value(int n, int poly[], int x){
        // code here
        long MOD = 1e9 + 7;
        long ans = poly[0];
        for(int i = 1 ; i < n ; i++)
        {
            ans = (ans * x ) % MOD;
            ans = (ans + poly[i] ) % MOD;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;
        int poly[n];
        for(int i = 0;i < n;i++)
            cin>>poly[i];
        cin>>x;
        
        Solution ob;
        cout<<ob.value(n, poly, x)<<"\n";
    }
    return 0;
}
// } Driver Code Ends