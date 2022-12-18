class Solution:
    
    def Prime(self , n):
        for i in range(2 , n):
            if(n % i == 0):
                return False
            else:
                continue
                
        return True
    
    
    
    def poww(self , n , a):
        i = 0
        while(n):
            if(n % a == 0):
                i+=1
            else:
                break;
                
            n = n / a
        
        return i
    
    
    
    def sumPrimeFactors(self ,n):        
        ans = 0;
        l = []
        temp = n
        for i in range(2 , n):
            
            if((n % i == 0) and (self.Prime(i))):
                
                l.append(self.poww( n , i )  * i)
                
        
        for i in l:
            ans = ans + i
            
        
        return ans
                
               
        
        
    def smallestValue(self, n: int) -> int:
        
        temp = n
        
        while(self.Prime(temp) == False and (temp != 4)):
            
            temp = self.sumPrimeFactors(temp);
            
        
        return temp
        