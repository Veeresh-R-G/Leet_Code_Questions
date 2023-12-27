class Solution {


public:
    int minCost(string colors, vector<int>& neededTime) {
        

        int ans = 0;
        int prev = 0;
        int N = colors.size();


        for(int i = 1; i < N; i++){
            if(colors[prev] != colors[i]){
                prev = i;
            }

            else{
                if(neededTime[prev] < neededTime[i]){
                    ans += neededTime[prev];
                    prev = i;
                }
                else{
                    ans += neededTime[i];
                }
            }
        }

        return ans;

    }
};