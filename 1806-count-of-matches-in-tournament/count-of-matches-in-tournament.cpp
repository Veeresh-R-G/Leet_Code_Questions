class Solution {

private:
    int helper(int teams){

        int ans = 0;
        while(teams != 1){
            if(teams % 2){
                ans += ((teams - 1) / 2);
                teams /= 2;
                teams += 1;
            }
            else{
                ans += (teams / 2);
                teams /= 2;
            }
        }


        return ans;

    }
public:
    int numberOfMatches(int n) {
        
        int ans = helper(n);

        return ans;
    }
};