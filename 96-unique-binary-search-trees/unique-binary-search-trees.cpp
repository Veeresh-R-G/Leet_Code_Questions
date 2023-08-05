class Solution {


private:
   vector<int> dp;

   int solve (int nodes){
            
        if(nodes <= 1){
            return 1;
        }

        if(dp[nodes] != -1){
            return dp[nodes];
        }

        int ans = 0;
        for(int node = 1 ; node <= nodes ; node++){

            ans += solve(node - 1) * solve(nodes - node);
        }

        return dp[nodes] = ans;

    }
public:
    int numTrees(int n) {
       /*
       
        Points : 
        1. We dont care with the values present on the left / right subtrees
        2. so the nodes --> 1 , 2 ,3  and nodes --> 4 , 5, 6 will give the same 
            answer because # of nodes = 3
       */


       
        dp.resize(n + 1, -1);
       return solve(n);
    }
};