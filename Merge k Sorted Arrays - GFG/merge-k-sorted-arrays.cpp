// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans = arr[0];
        
        for(int i = 1 ; i < arr.size(); i++)
        {
            int one = 0;
            int two = 0;
            vector<int> v = arr[i];
            vector<int> temp = {};
        
            while(one < ans.size() && two < v.size())
            {
                if(ans[one] <= v[two])
                {
                    temp.push_back(ans[one++]);
                }
                
                else
                {
                    temp.push_back(v[two++]);
                }
                
            }
            
            while(one < ans.size())
            {
                temp.push_back(ans[one++]);
            }
            
            while(two < v.size())
            {
                temp.push_back(v[two++]);
            }
            
            ans = temp;
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends