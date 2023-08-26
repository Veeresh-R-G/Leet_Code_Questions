class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:

        pairs = sorted(pairs , key = lambda x : x[1])
        # print(pairs)
        curr = float('-inf')
        ans = 0
        for i in pairs:
            if(i[0] > curr):
                ans += 1
                curr = i[1]

        return ans