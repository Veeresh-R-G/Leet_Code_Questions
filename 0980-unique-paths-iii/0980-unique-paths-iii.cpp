class Solution {
public:
    
    int f(vector<vector<int>>& grid , int row , int col , int endR , int endC , vector<vector<bool>>& vis,
         int rowLim , int colLim)
    {
        //Out of Limits
        if(row == rowLim || col == colLim || row < 0 || col < 0)
        {
            return 0;
        }
        
        
        //Reach the destination
        if(row == endR && col == endC)
        {
            
            for(auto i = 0 ; i < rowLim ; i++)
            {
                for(auto j = 0 ; j < colLim ; j++)
                {
                    // cout << vis[i][j] << "---" << grid[i][j] << " ";
                    
                    if(vis[i][j] == false && !grid[i][j])
                    {
                        return 0;
                    }
                }
               
            }
          
            return 1;
        }
               
        /*
            Now the movements
            
            1. Up 
            2. Down
            3. Left
            4. Right
        */
        int up = 0 , down = 0 , left = 0 , right = 0;
        
        if(row > 0 && vis[row - 1][col] == false)
        {
            cout << "up" << endl;
            vis[row][col] = true;
            up = f(grid , row - 1 , col , endR , endC , vis , rowLim , colLim);
            vis[row][col] = false;
        }
        
        if(row < rowLim - 1 && vis[row + 1][col] == false)
        {
            cout << "down" << endl;
            vis[row][col] = true;
            down = f(grid , row + 1 , col , endR , endC , vis , rowLim , colLim);
            vis[row][col] = false;
            
        }
        
        if(col > 0 && vis[row][col - 1] == false)
        {
            cout << "left" << endl;
            vis[row][col] = true;
            left = f(grid , row , col - 1 , endR , endC , vis , rowLim , colLim);
            vis[row][col] = false;
        }
        
        if(col < colLim - 1 && vis[row][col + 1] == false)
        {
            cout << "right" << endl;
            vis[row][col] = true;
            right = f(grid , row , col + 1 , endR , endC , vis , rowLim , colLim);
            vis[row][col] = false;
        }
        
        
        return up + down + left + right ;
        
    
        
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int st_x = -1, st_y = -1;
        int end_x = -1, end_y = -1;
        int N = grid.size();
        int M = grid[0].size();
        
        vector<vector<bool>> vis(N , vector<bool>(M , false));
        
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                
                if(grid[i][j] == -1)
                {
                    //Obstacle Detection
                    vis[i][j] = true;
                }
                if(st_x == -1)
                {
                    if(grid[i][j] == 1)
                    {
                        st_x = i;
                        st_y = j;
                        
                    }
                }
                
                if(end_x == -1)
                {
                    if(grid[i][j] == 2)
                    {
                        end_x = i;
                        end_y = j;
                        
                    }    
                }
                
            }           
        }
        
        cout << st_x << " " <<st_y << "----" << end_x << " " << end_y << endl; 
       
        return f(grid , st_x , st_y , end_x , end_y , vis , N , M);
    }
};