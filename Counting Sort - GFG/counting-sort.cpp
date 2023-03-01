//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int N = arr.size();
        
        vector<int> counts(26 , 0);
        string ans = "";
        for(auto it : arr)
        {
            counts[it - 'a'] += 1;
        }
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(counts[i] == 0) continue;
            
            char temp = i + 97;
            for(int j = 0 ; j < counts[i] ; j++)
            {
                
                ans = ans + temp;
            }
        }
        // cout << ans << endl;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends