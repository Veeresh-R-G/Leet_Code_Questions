class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = list()

        for word in words:
            for ele in words:
                if ele == word:
                    continue
                else:
                    if ele.find(word) != -1:
                        ans.append(word)

        return list(set(ans))