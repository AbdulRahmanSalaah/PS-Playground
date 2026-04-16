class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        x = n // 3
        mp = {}
        ans = []

        for num in nums:
            mp[num] = mp.get(num, 0) + 1

        for num in mp:
            if mp[num] > x:
                ans.append(num)
        return ans
