class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> diffArray(n , 0);

        for(auto &shift: shifts){
            int direction = shift[2];

            if(direction){
                diffArray[shift[0]]++;

                if(shift[1] + 1 < n){
                    diffArray[shift[1] + 1]--;
                }
            } else{
                diffArray[shift[0]]--;

                if(shift[1] + 1 < n){
                    diffArray[shift[1] + 1]++;
                }
            }
        }

        string res(n, ' ');
        int numShifts = 0;

        for(int i = 0; i < n; i++){
            numShifts = (numShifts + diffArray[i]) % 26;

            if(numShifts < 0){
                numShifts += 26;
            }

            res[i] = 'a' + (s[i] - 'a' + numShifts) % 26;
        }

        return res;
    }
};