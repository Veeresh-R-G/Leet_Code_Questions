//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col, int newColor , int oldColor ,int rowLim , int colLim)
    {
        if(row >= rowLim || col >= colLim || row < 0 || col < 0)
        {
            return;
        }
        
        if(image[row][col] == newColor || image[row][col] != oldColor) return;
        
        image[row][col] = newColor;
        
        dfs(image , row , col - 1 , newColor , oldColor , rowLim , colLim);
        dfs(image , row , col + 1 , newColor , oldColor , rowLim , colLim);
        dfs(image , row + 1 , col , newColor , oldColor , rowLim , colLim);
        dfs(image , row - 1 , col , newColor , oldColor , rowLim , colLim);
        
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int N = image.size();
        int M = image[0].size();
        
        int oldColor = image[sr][sc];
        
        
        dfs(image , sr,  sc,newColor,oldColor, N ,M);
        
        return image;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends