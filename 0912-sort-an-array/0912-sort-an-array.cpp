class Solution {
public:
    
    int getMax(vector<int>& nums)
    {
        int maxi = INT_MIN;
        
        for(auto it : nums)
        {
            maxi = max(maxi , it);
        }
        
        return maxi;
    }
    
    void countSort(vector<int>& nums , int exp , int size)
    {
        vector<int> output(nums.size() , 0);
        vector<int> count(10 , 0);
        
        
        //Keeping freq count of all the most LSB Digit
        /*
            123 
            
            123 / 1 = 123 % 10 == 3
            
            123 / 10 = 12 % 10 == 2 
            and so on
        */
        for(auto it : nums)
        {
            count[(it / exp) % 10] += 1;
        }
        
        
        //Fixing the position of the elements
        for(int i = 1 ; i < count.size() ; i++)
        {
            count[i] += count[i - 1];
        }
        
        
        // Writing in sorted array
        for(int i = size - 1 ; i >= 0 ; i--)
        {
            output[count[(nums[i] / exp) % 10] - 1] = nums[i];
            count[(nums[i] / exp) % 10]--;
        }
        
        nums = output;
        
        
        
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        /*
            Radix Sort :
            
            Number of Bins : 10(Acc to number system (Dec / bin / hex / oct))
            
            Check last number store in that respective bucket
            check last second digit
        */   
        
        int maxi = getMax(nums);
        
        int N = nums.size();
        vector<int> posi;
        vector<int> negi;
        
        for(auto it : nums)
        {
            if(it < 0) negi.push_back(it * -1);
            else posi.push_back(it);
        }
        int maxiPosi = getMax(posi);
        for(int e = 1 ; (maxiPosi / e) > 0 ; e = e * 10)
        {
            countSort(posi , e , posi.size());
        }
        
        int maxinegi = getMax(negi);
        for(int e = 1 ; (maxinegi / e) > 0 ; e = e * 10)
        {
            countSort(negi , e , negi.size());
        }
        
        vector<int> ans;
        for(auto it : negi)
        {
            ans.push_back(it * -1);
        }
        reverse(ans.begin(), ans.end());
        for(auto it : posi)
        {
            ans.push_back(it);
        }
        
        
        return ans;
    }
};