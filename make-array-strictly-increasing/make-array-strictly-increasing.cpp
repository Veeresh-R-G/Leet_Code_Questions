class Solution {

private:

    map<pair< int , int > , int> dp;

    int f(vector<int>& arr1 , vector<int>&arr2 , int i , int N , int prev)
    {
        if(i >= N)
        {
            return 0;
        }

        if(dp.find({i , prev}) != dp.end())
        {
            return dp[{i , prev}];
        }

        //change and not change option

       
        int ans = INT_MAX / 2;
        int id = upper_bound(arr2.begin() , arr2.end() , prev) - arr2.begin();


        //Just continue case
        if(arr1[i] > prev)
        {
            ans = min(ans , f(arr1 , arr2 , i + 1 , N , arr1[i]));
        }   

        //if it is a valid index and then replace and go ahead
        if(id < arr2.size())
        {
            ans = min(ans , 1 + f(arr1 , arr2 , i + 1 , N , arr2[id]));
        }


        return dp[{i , prev}] = ans;

        
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        

        //We sorted here so we can use Binary Search OMMGG
        //FML
        sort(arr2.begin() , arr2.end());


        int N = arr1.size();
        int i = 0;
        
        int ans = f(arr1 , arr2 , i , N , INT_MIN);
        return  ans >= INT_MAX / 2 ? -1 : ans;
    }
};