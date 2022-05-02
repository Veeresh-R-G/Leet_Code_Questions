class Solution:
    def reverseWords(self, s: str) -> str:
        
        s = s.lstrip(" ")
        s = s.rstrip(" ")
        
        l = list((s).split(" "))
        
        
        ans = ""
       
        # print(l)
        n = len(l) - 1;
        while(n >=0):
         
            if(l[n] != '' and l[n] != " "):
       
                ans = ans + l[n] + " ";
            n = n - 1;
            continue
        
        # print(ans);
        return ans[:len(ans) - 1];
    
    '''
    
    ['the', 'sky', 'is', 'blue']
blue is sky the 
['hello', 'world']
world hello 
['a', 'good', '', '', 'example']
example   good a 

    '''
        