// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int min(int a , int b){
        return a>=b ? b : a;
    }
    int nCr(int n, int r){
        // code here
        if(n < r){
            return 0;
        }
        int MOD = 1000000007;
        
        long long arr[n + 1][r + 1];
        
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= (min(i , r)) ; j++)
            {
                
                
                    if(i == j || j == 0)
                    {
                        arr[i][j] = 1;
                    }

                    else
                    {
                        arr[i][j] = (arr[i -1][j] + arr[i-1][j-1]) % MOD;
                    }
            }
        }
            
        
        return arr[n][r];
        
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends