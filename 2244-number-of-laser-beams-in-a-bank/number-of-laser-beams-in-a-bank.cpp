class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int N = bank.size();
        int M = bank[0].size();

        vector<int> rowLasers(N, 0);

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(bank[i][j] == '1'){
                    rowLasers[i]++;
                }
            }
        }
        
        int prev = 0;
        int curr;
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            curr = rowLasers[i];

            if(curr == 0){
                continue;
            }
            ans += curr * prev;
            prev = curr;
        }

        return ans;



    }
};