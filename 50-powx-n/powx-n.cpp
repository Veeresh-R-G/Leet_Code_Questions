class Solution {

private:
    double helper(double x , int n){
        if(n == 0) return 1;
        if(x == 0) return 0;


        double res = helper(x , n / 2);
        res = res * res;

        return n % 2 ? x * res :  res;
    }
public:
    double myPow(double x, int n) {
        
        double ans = helper(x , abs(n));

        if(n < 0) return 1.0 / ans;
        return ans;
    }
};