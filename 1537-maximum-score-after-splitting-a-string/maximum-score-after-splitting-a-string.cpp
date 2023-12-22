class Solution {
public:
    int maxScore(string s) {
        
        int N = s.size();
        vector<int> ones(N , 0);
        vector<int> zeroes(N , 0);

        int cnt = 0;
        int ans = INT_MIN;

        for(int i = 0 ; i < N ; i++){
            if(s[i] == '0'){
                zeroes[i] = cnt;
                cnt++;
            }
            else{
                zeroes[i] = cnt;
            }
        }


        cnt = 0;
        for(int i = N - 1 ; i >= 0 ; i--){
            if(s[i] == '1'){
                ones[i] = cnt;
                cnt++;
            }
            else{
                ones[i] = cnt;
            }
        }


        for(int zInd = 1, oInd = 0; zInd < N && oInd < N - 1; zInd++, oInd++){
           
           ans = max(ans, zeroes[zInd] + ones[oInd]);           
        }

        return ans;
    }
};