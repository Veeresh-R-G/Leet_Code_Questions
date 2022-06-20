// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    
    vector<int> rowDiff = {-1 , 1 , 0 , 0};
    vector<int> colDiff = {0 , 0, -1 , 1};
    string moves = "UDLR";
    
    void solve(vector<vector<int>> &m , vector<vector<int>> &vis, int row , int col , int n ,
    string& out , vector<string>& ans)
    {
        
        if(row == (n - 1) && col == (n - 1))
        {
            ans.push_back(out);
            return;
        }
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int nextRow = row + rowDiff[i];
            int nextCol = col + colDiff[i];
            
            
            
            if(nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n && m[nextRow][nextCol] && 
            !vis[nextRow][nextCol])
            {
                vis[row][col] = 1;
                out.push_back(moves[i]);
                solve(m, vis ,nextRow , nextCol , n , out , ans);
                vis[row][col] = 0;
                out.pop_back();
            }
            
        }
        /*
        //Move down check
        if((row + 1 < n) && m[row + 1][col] == 1 && vis[row + 1][col] == 0 )
        {
            vis[row][col] = 1;
            out.push_back('D');
            solve(m , vis , row + 1 , col , n , out , ans);
             vis[row][col] = 0;
            out.pop_back();
        }
        
        //Move Up check
        if((row - 1 >= 0) && m[row - 1][col] == 1 && vis[row - 1][col] == 0 )
        {
            vis[row][col] = 1;
            out.push_back('U');
            solve(m , vis , row - 1 , col , n , out , ans);
            vis[row][col] = 0;
            out.pop_back();
        }
        
        //Move Left check
        if((col - 1) >= 0 && m[row][col - 1] == 1 && vis[row][col - 1] == 0)
        {
            vis[row][col] = 1;
            out.push_back('L');
            solve(m , vis , row , col - 1 , n , out , ans);
            vis[row][col] = 0;
            out.pop_back();
        }
        
        
        //Move Right check
        if((col + 1) < n && m[row][col + 1] == 1 && vis[row][col + 1] == 0)
        {
            vis[row][col] = 1;
            out.push_back('R');
            solve(m , vis , row , col + 1 , n , out , ans);
            vis[row][col] = 0;
            out.pop_back();
        }
        */
        
    }
    public:
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis;
        vector<int> temp( n , 0);
        
        for(int i = 0 ; i < n ; i ++)
        {
            vis.push_back(temp);
        }
        vector<string> ans;
        string out = "";
        if(m[0][0] == 1)
        {
            solve(m , vis , 0 , 0 , n , out , ans);
            return ans;
        }
        return {};
        
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends