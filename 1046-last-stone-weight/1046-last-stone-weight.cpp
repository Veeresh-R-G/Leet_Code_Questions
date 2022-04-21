class Solution {
public:
    
    void print(vector<int> s)
    {
        for(int i =0 ; i < s.size() ; i++)
        {
            cout << s[i] << " ";
        }
        cout<<endl;
    }
    int lastStoneWeight(vector<int>& s) {
//          priority_queue<int> g = gq;
        
//         for(int i = 0 ; i < s.size() ; i++){
//             gq.push(s[i]);
//         }
        
//         //now we have max heap ready
        
        if(s.size() == 1)
        {
            return s[0];
        }
        
        else if(s.size() == 0){
            return 0;
        }
        
        sort(s.begin(), s.end());
        
        //min size of vecotr is 0 or 1 
        /*
            2 --> 1 will remain or 0 will remain 
            3 --> 1 will remain
        
        
        s.size() != 1 || s.size() != 0
        */
        
        
        // print(s);
        while(s.size() > 1) //s.size() > 1 min 2 elements
        {
            /*
                toh minimum 2 elements should be there
            */
            int n = s.size();
            int max1 = s[n - 1];
            int max2 = s[n - 2];
            
            
            s.pop_back();
            s.pop_back();
            
            int diff = max1 - max2;
            
            if(diff!=0){
                s.push_back(diff);
            }
            
            sort(s.begin() , s.end());
            // print(s);
        }
        
        if(s.size() == 0){
            return 0;
        }
        else{
            return s[0];
        }
        
    }
};