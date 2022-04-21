class Solution {
public:
    
    void swap(vector<int> v , int s ,int e)
    {
        int temp;
        temp = v[s];
        v[s] = v[e];
        v[e] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        
        int z = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] != 0){
                int temp;
        temp = nums[z];
        nums[z] = nums[i];
        nums[i] = temp;
                z++;
                i++;
            }
            else{
                i++;
            }
        }
    }
};