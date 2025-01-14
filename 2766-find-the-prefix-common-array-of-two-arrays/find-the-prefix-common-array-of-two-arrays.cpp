class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int currCommon = 0;
        int n = A.size();

        vector<int> ans;
        unordered_map<int, int> temp;


        for(int i = 0 ; i < n; i++){
            int a = A[i];
            int b = B[i];


            temp[a]++;
            if(temp[a] == 2){
                currCommon++;
            } 

            temp[b]++;
            if(temp[b] == 2){
                currCommon++;
            }

            ans.push_back(currCommon);
            
        }

        return ans;


        return ans;
    }
};