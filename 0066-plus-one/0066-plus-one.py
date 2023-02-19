class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
    
        l = map(lambda x: str(x), digits)
        return list(map(lambda x : int(x) , (list(str(int("".join(list(l))) + 1)))))
        