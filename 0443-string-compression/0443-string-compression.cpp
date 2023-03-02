class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size() == 1)
        {
            return chars.size();
        }
        int cnt = 1;
        int i = 1;
        while(i < chars.size())
        {
            if(chars[i] == chars[i - 1])
            {
                cnt++;
                chars.erase(chars.begin() + i);
            }
            else
            {
                
                string temp = to_string(cnt);
                // cout << temp << " " << cnt << endl;
                if(cnt == 1)
                {
                    i++;
                    continue;
                }
                for(auto it : temp)
                {
                    chars.insert(chars.begin() + i , it);
                    i += 1;
                }
                // if(temp == "1")
                // {
                //     chars.pop_back();
                //     i--;
                // }
                    
                cnt = 1;
                i = i + 1;
                
            }
        }
        
        
        string temp = to_string(cnt);
        if(temp != "1")
        {
             for(auto it : temp)
                {
                    chars.push_back(it);
            
                }
        }
       

        
            
            
            return chars.size();
    }
};