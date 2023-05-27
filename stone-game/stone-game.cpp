class Solution {

private:

    map<pair<int, int> , int> mp;

public:


    int f(vector<int>& piles , int l , int r)
    {
        if(l > r)
        {
            return 0;
        }

        if(mp.find({l , r}) != mp.end())
        {
            return mp[{l , r}];
        }

        //Even length is only when Alice is picking
        //But on zero based indexing (r - l) will be odd when len of array will be even
        //Even --> ALice is making choice
        //Odd --> Bob is picking
        bool even = (r - l) % 2 ? true : false;
        
        int left = even ? piles[l] : 0;
        int right = even ? piles[r] : 0;

        
        return mp[{l , r}] = max(f(piles , l + 1 , r) + left , 
        f(piles , l , r - 1) + right);

    }

    bool stoneGame(vector<int>& piles) {
        
        int l = 0;
        int r = piles.size();

        int sum = 0;
        for(auto it : piles) sum += it;

        return f(piles , l , r - 1) > (sum / 2);
        
    }
};