class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        l = 0
        r = max(len(word1), len(word2)) 
        res = []
        while l < r:
            if l < len((word1)):
                res.append(word1[l])
            if l < len((word2)):
                res.append(word2[l])
            l += 1

        return "".join(res)
