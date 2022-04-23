import random
class Codec:
    
    def __init__(self):
        self.d = dict()
        self.l1 = [chr(i) for i in range(65 , 91)]
        self.l2 = [chr(i) for i in range(97 , 123)]
        self.l3 = [str(i) for i in range(0 , 10)]
        self.l = self.l1 + self.l2 + self.l3
        #instance variable 
        '''
        
        
        Unique for each object of this class
        
        '''
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        temp = "".join(random.sample(self.l, 6))
        if(longUrl not in self.d.keys()):
            self.d[temp] = longUrl
        
        return temp
        
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.d[shortUrl]
            
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))