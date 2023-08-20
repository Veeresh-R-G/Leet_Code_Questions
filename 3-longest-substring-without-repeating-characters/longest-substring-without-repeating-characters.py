class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        r = 0
        l = 0
        ans = 0
        char_set = set()
        while(r < len(s)):

            while(s[r] in char_set):
                char_set.remove(s[l])
                l += 1
            
            char_set.add(s[r])

            ans = max(ans , r - l + 1)
            r += 1
        
        return ans

            