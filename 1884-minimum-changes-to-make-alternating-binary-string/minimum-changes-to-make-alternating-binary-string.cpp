class Solution {
public:
    int minOperations(string s) {

        int one = 0;
        int zero = 0;

        //flag true -> 1
        //flag false -> 0

        bool flag = true;
        int cntOne = 0;
        int cntZero = 0;

        for(auto it: s){
            if(it - '0' != flag){
                cntOne++;
            }
            flag = !flag;
        }

        flag = false;
        for(auto it: s){
            if(it - '0' != flag){
                cntZero++;
            }
            flag = !flag;
        }

        return min(cntOne, cntZero);



        return abs(zero - one) / 2;
        
    }
};