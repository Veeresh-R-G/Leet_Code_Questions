Complexity Analysis :
Time : O(n) + O(log(m))
Space : O(1)
​
where n is the number of rows and m is the number of columns
```
​
Code :
bool searchMatrix(vector<vector<int>>& matrix, int target) {
int row = -1;
int rowDim = matrix.size();
int colDim = matrix[0].size();
for(int i = 0 ; i < matrix.size() ; i++)
{
if(matrix[i][colDim - 1] >= target)
{
row = i;
break;
}
}
int start = 0;
int end = colDim - 1;
//Binary Search Now !
while(start <= end)
{
int mid = (start + end) / 2;