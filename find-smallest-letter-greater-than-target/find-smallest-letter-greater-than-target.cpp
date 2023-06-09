class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        


        char ans = '$';

        for(auto it : letters)
        {
            if(target < it)
            {
                ans = it;
                break;
            } 
        }


        return ans == '$' ? letters[0] : ans ;
    }
};