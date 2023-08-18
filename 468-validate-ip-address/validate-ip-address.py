class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        
        ipv4 = True
        ipv6 = True
        if("." in queryIP):
            l = queryIP.split(".")
            if(len(l) != 4):
                return "Neither"
            
            if(ipv4):
                for i in range(len(l)):
                    if(not(l[i].isdigit())):
                        return "Neither"
                    # l[i] = int(l[i])

                    if(int(l[i]) > 255 or int(l[i]) < 0):
                        return "Neither"

                    print(l[i])
                    if(len(l[i]) > 1 and str(l[i])[0] == '0'):
                        return "Neither"
 

                return "IPv4"   

        
        elif(":" in queryIP):
            v = ['a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F']
            l = queryIP.split(":")
            if(len(l) != 8):
                return "Neither"

            if(ipv6):
                for i in range(len(l)):
                    curr = l[i]
                    if(not(1 <= len(curr) <= 4)):
                        print("here")
                        return "Neither"
                    for i in curr:
                        if(i.isalpha() and i not in v):
                            print("here :" , curr , i)
                            return "Neither"

                    
                
                return "IPv6"



        
        
        return "Neither"



        
        