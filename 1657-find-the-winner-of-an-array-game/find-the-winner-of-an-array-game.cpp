class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int maxEle = INT_MIN;

        for(auto it : arr){
            maxEle = max(maxEle , it);
        }

        queue<int> q;

        for(int i = 1 ; i < arr.size() ; i++){
            q.push(arr[i]);
        }


        int win = 0;
        int currEle = arr[0];


        while(!q.empty()){

            auto f = q.front();
            q.pop();

            if(f == currEle){
                return f;
            }
            if(currEle > f){
                win++;
                if(win == k){
                    return currEle;
                }
                q.push(f);
            }
            else{
                currEle = f;
                q.push(currEle);
                win = 1;
                if(win == k){
                    return currEle;
                }
            }
        }

        return -1;
    }
};