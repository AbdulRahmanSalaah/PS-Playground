class Solution(object):
    def twoSum(self, nums, target):
        mp = {}
        for i,n in enumerate(nums):
            dif = target-n
            if dif in mp:
              return [mp[dif], i]

            mp[n]=i
        return []