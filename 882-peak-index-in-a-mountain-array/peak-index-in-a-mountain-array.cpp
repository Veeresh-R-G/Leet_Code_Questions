class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // int ind = 0;

        // for(int i = 0 ; i < arr.size() - 1 ; i++)
        // {
        //     if(arr[i] > arr[i + 1]){
        //         ind = i;
        //         break;
        //     }
        // }

        // return ind;

        // linear works

        int left = 0 , right = arr.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                return mid;
            }

            else if(arr[mid] < arr[mid + 1]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return -100;

    }
};