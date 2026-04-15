class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)
        longest = 0 

        for num in st:
            if num-1 not in st:
                l = 1 
                while num+l in st:
                    l+=1
                longest = max(longest,l)
        return longest