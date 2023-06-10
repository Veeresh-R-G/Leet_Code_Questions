class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        // contraint so high : Cant go through all 1 to N;
        // Binary Search -> log(N)

        int mid = n;
        int emptyR = n - index - 1; // no: of Right Empty Cells
        int emptyL = index; //no: of Left Empty Cells

        int l = 1;
        int r = maxSum;

        int ans;
        while(l <= r)
        {
            int mid = ((r - l)/ 2)  + l;

            long long leftSum = 0 , rightSum = 0 , el = mid - 1;

            if(emptyR <= el)
            {
                rightSum = ((el * (el + 1)) / 2) - (((el - emptyR) * (el - emptyR + 1)) / 2); 
            }
            else
            {
                rightSum = ((el * (el + 1)) / 2) + (emptyR - el);
            }

            if(emptyL <= el)
            {
                leftSum = ((el * (el + 1)) / 2) - (((el - emptyL) * (el - emptyL + 1)) / 2);
            }
            else
            {
                leftSum = ((el * (el + 1)) / 2) + (emptyL - el);
            }

            long long sum = leftSum + rightSum + mid;

            if(sum <= maxSum)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;

    }
};