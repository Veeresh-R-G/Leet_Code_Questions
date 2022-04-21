class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t1 = 0;
        int t2 = 0;
        int size1 = s.size();
        int size2 = t.size();
        
        while(t1 < size1 && t2 < size2)
        {
            if(s[t1] == t[t2])
            {
                t1 += 1;
                t2 += 1;
            }
            else
            {
                t2+=1;
            }
        }
        // cout << "T1 == " << t1<<endl;
        // cout << "T2 == " << t2 << endl;
        if(t1 < size1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};