class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
        {
            return 0;
        }
        
		vector<int> copy = nums;
		
		sort(nums.begin(),nums.end());
        
		int start=0;
        int n=nums.size();
        
		while(start<n and nums[start]==copy[start]){
			start++;
		}
        
        
		int end=nums.size()-1;
		while(end>=0 and nums[end]==copy[end]){
			end--;
		}
        
        
		if(start==n){
            return 0;
        }
        
		return end-start+1;
	}
};