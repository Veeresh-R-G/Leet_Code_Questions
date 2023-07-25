class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int ind = 0;

        for(int i = 0 ; i < arr.size() - 1 ; i++)
        {
            if(arr[i] > arr[i + 1]){
                ind = i;
                break;
            }
        }

        return ind;

    }
};