// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	
	    void solve(string s ,vector<string>&ans)
	    {
	        int n = s.length();
	        
	       
	        for(int i = 0 ; i < (1 << n) ; i++)
	        {
	            string temp = "";
	            for(int j = 0 ; j < n ; j++)
	            {
	                
	                if((i & (1 << j)))
	                {
	                    temp+=s[j];
	                }
	            }
	           // cout << temp << " ";
	           if(temp.size())
	            ans.push_back(temp);
	        }
	        
	   }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    vector<string> ans;
		    
		    solve(s , ans);
		    
		    sort(ans.begin() , ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends