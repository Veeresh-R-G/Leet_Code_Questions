class Solution {

private:
    bool isPossible(int n , vector<int>& batteries , long long avg_total_time){

        long long total_duration = 0;

        for(auto it : batteries){
            total_duration += min(avg_total_time ,it * 1ll);
        }

        long long temp = avg_total_time * n;

        return total_duration >= temp;

    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long maxi = -1e9;
        long long mini = 1e9;
        long long sum = 0;

        for(auto it : batteries){
            maxi = max(maxi , it * 1ll);
            mini = min(mini , it * 1ll);
            sum += it;
        }


        long long left = mini;
        long long right = sum;


        while(left <= right){
            long long avg_total_time = (left + right) / 2;


            if(isPossible(n , batteries , avg_total_time)){
                left = avg_total_time + 1;
            }
            else{
                right = avg_total_time - 1;
            }
        }


        return right;
    }
};