// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        // vector<int> v;
        int first_bad = -1;
        
        // for(int i = 1 ; i <= n ; i++)
        // {
        //     v.push_back(i);
        // }
        
        //brute force
        
        // for(int i = 1 ; i <=n; i++)
        // {
        //     if((v[i]))
        //     {
        //         first_bad = v[i];
        //         break;
        //     }
        // }
        
        // return first_bad;
        
        
        int s = 1;
        int e = n;
        int mid;
        while(s <= e)
        {
            mid = (s) + (e - s)/2;
            if(isBadVersion(mid))
            {
                if(isBadVersion(mid - 1))
                {
                    e = mid - 1;
                    continue;
                }
                else
                {
                    return mid;
                }
                
        
            }
            else
            {
                s = mid + 1;
            }
        }
        return mid;
    }
};