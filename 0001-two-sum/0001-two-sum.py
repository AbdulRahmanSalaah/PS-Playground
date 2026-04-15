class Solution(object):
    def twoSum(self, nums, target):
        mp = {}  
        
        for i, num in enumerate(nums):
            c = target - num
            
            if c in mp:
                return [mp[c], i]
            
            mp[num] = i
            
        return []