class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        
        l = list(map(int, nums))
        l = sorted(l)
        print(l)
        return str(l[len(l) - k])
        '''
        10 7 6 3 k=4
        21 12 2 1 k =3
        
        '''
        
        