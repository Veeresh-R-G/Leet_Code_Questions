class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        
        int row = b.size();
        int col = b[0].size();
        
       vector<vector<int>> tempo;
        
        for(int i = 0 ; i < row ; i++){
            vector<int> temp;
            for(int j = 0 ; j < col ; j++){
                
                temp.push_back(b[i][j]);
            }
            tempo.push_back(temp);
            
        }
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                int top = i - 1;
                int left = j - 1;
                int right = j + 1;
                int down = i + 1;
                
                int cell = tempo[i][j];
                
                //alive cells
                if(cell == 1){
                    int alive = 0;
                    
                    //top
                    if(top >= 0)
                    {
                        if(tempo[top][j] == 1){
                            alive++;
                        }
                    }
                    
                    //below
                    if(down < row){
                        if(tempo[down][j] == 1){
                            alive++;
                        }
                    }
                    
                    //left side
                    if(left >= 0){
                        if(tempo[i][left] == 1){
                            alive++;
                        }
                    }
                    
                    
                    //right
                    if(right < col){
                        if(tempo[i][right] == 1){
                            alive++;
                        }
                    }
                    
                    //top - left diag
                    if(top >= 0 && left >=0)
                    {
                        if(tempo[top][left]){
                            alive++;
                        }
                    }
                    
                    //top-right diag
                    if(top>=0 && right < col){
                        if(tempo[top][right]){
                            alive++;
                        }
                    }
                    
                    //bottom-left
                    if(down < row && left >=0){
                        if(tempo[down][left]){
                            alive++;
                        }
                    }
                    
                    //bottom right
                    if(down < row && right < col)
                    {
                        if(tempo[down][right])
                        {
                            alive++;
                        }
                    }
                    
                    
                    // now compare value of alive cells
                    
                    if(alive < 2 || alive > 3){
                        //cell dies here
                        b[i][j] = 0;
                    }
                }
                
                else{
                    //dead cell
                    //cell == 0
                    
                    int alive = 0;
                    
                    //top
                    if(top >= 0)
                    {
                        if(tempo[top][j] == 1){
                            alive++;
                            cout << "top " ; 
                        }
                    }
                    
                    //below
                    if(down < row){
                        if(tempo[down][j] == 1){
                            alive++;
                            cout << "below " ; 
                        }
                    }
                    
                    //left side
                    if(left >= 0){
                        if(tempo[i][left] == 1){
                            alive++;
                            cout << "left " ; 
                        }
                    }
                    
                    
                    //right
                    if(right < col){
                        if(tempo[i][right] == 1){
                            alive++;
                            cout << "right " ; 
                        }
                    }
                    
                    //top - left diag
                    if(top >= 0 && left >=0)
                    {
                        if(tempo[top][left]){
                            alive++;
                            cout << "top-left " ; 
                        }
                    }
                    
                    //top-right diag
                    if(top>=0 && right < col){
                        cout << top << " " << right << " ";
                        cout << "top-right " << tempo[top][right] << " " ; 
                        if(tempo[top][right]){
                            alive++;
                            
                        }
                    }
                    
                    //bottom-left
                    if(down < row && left >=0){
                        if(tempo[down][left]){
                            alive++;
                            cout << "bottom-left " ; 
                            
                        }
                    }
                    
                    //bottom right
                    if(down < row && right < col)
                    {
                        if(tempo[down][right])
                        {
                            alive++;
                            cout << "bottom-right " ; 
                        }
                    }
                    
                    cout << alive << endl;
                    // now compare value of alive cells
                    
                    if(alive == 3){
                        //cell lives now
                        b[i][j] = 1;
                    }                   
                    
                    
                }
            }
        }
    }
};