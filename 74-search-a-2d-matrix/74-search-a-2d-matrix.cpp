class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int cols = matrix[0].size(); //1
        int rows = matrix.size(); // 2
        int whichRowanta = 0; //0
        
        /*
        i = 0 
        1 < mat[0][0] ==> 1 < 1
        
        */
        
        for(int i = 0; i < rows ; i++)
        {
            if(target <= matrix[i][cols - 1])
            {
                whichRowanta = i;
                break;
            }
        }
        
        vector<int> search = matrix[whichRowanta];
        
        int s = 0;
        int e = cols - 1;
        bool found = false;
        while(s <=e && !found)
        {
            int mid = (s) + ((e - s) / 2);
            
            if(search[mid] == target)
            {
                found = true;                
            }
            
            else if(target > search[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return found;
    }
};