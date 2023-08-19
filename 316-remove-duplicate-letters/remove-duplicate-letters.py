class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = []
        
        d = {}

        for i in range(len(s) - 1, -1 , -1):
            if(s[i] in d):
                continue
            else:
                d[s[i]] = i

        print(d)
        for i , char in enumerate(s):
            
            if(char in stack):
                continue;

            while stack and char < stack[-1] and i < d[stack[-1]]:
                stack.pop()

            stack.append(char)


        res = "".join(stack)

        return res


