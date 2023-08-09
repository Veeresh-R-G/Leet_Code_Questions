class Solution {

private:
    bool canFindPairs(vector<int>&nums , int maxDiff , int p){

        int pairs = 0;
        int prev = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if( prev != -1 && abs(nums[i] - prev) <= maxDiff ){
                pairs++;
                prev = -1;
            }
            else{
                prev = nums[i];
            }
            if(pairs == p) return true;
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin() , nums.end());
        //by sorting we will ensure to take consecutive pairs 
        //coz we want minimum difference


        //use BS to maximise the differene
        int n = nums.size();
        //BS on the Difference
        int left = 0;
        int right = nums[n - 1] - nums[0];


        while(left <= right){
            
            int mid = left + (right - left) / 2;
            if(canFindPairs(nums,mid, p)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};