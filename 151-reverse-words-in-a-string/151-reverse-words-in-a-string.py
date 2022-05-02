class Solution:
    def reverseWords(self, s: str) -> str:
        
        
        '''
        
            Time Complexity : O(n)
            Space Complexity : O(n)
            
        '''
        
        s = s.lstrip(" ")
        s = s.rstrip(" ")
        
        l = list((s).split(" "))
        
        
        ans = ""
        
        
        
        n = len(l) - 1;
        while(n >=0):
         
            if(l[n] != '' and l[n] != " "):
       
                ans = ans + l[n] + " ";
            n = n - 1;
            continue
        
        # print(ans);
        return ans[:len(ans) - 1];
        