class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        int n = 0;
        int carry = 0;
        for(int i = digits.size() - 1 ; i >= 0 ; i--)
        {
            if(i == digits.size() - 1)
            {
                carry = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            }
            
            else
            {
                int temp = digits[i] + carry;
                digits[i] = (temp) % 10;
                carry = (temp) / 10;
            }
            
        }
        
        if(carry)
        {
            digits.insert(digits.begin() , carry);
        }
        
        return digits;
        
        
        
    }
};