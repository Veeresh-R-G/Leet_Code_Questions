class Solution:
    def calPoints(self, ops: List[str]) -> int:
        l = list()
        
        for i in range(len(ops)):
            if( ops[i] == "D"):                
                n = l[len(l) - 1]
                l.append(n * 2)
                # print(l)
            elif(ops[i] == "C"):
                l.pop()
                # print(l)
                
            elif(ops[i] == "+"):
                # print(l)
                n1 = l[len(l) - 1]
                n2 = l[len(l) - 2]
                
                l.append(n1 + n2)
                
            else:
                
                l.append(int(ops[i]))
                # print(l)
                
        ans = 0
        for i in l:
            ans+=i
            
        return ans
        