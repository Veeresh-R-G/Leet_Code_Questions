// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int one = 0;
        int two = 0;
        int z = 0;
        
        
        
        for(int i = 0 ; i < n ;i++)
        {
            if(a[i] == 0)
            {
                z++;
            }
            else if(a[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        
        for(int i = 0 ; i < z ; i++)
        {
            a[i] = 0;
        }
        for(int i = z ; i < one + z ; i++)
        {
            a[i] = 1;
        }
        
        for(int i = one + z; i < n  ; i++)
        {
            a[i] = 2;
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends