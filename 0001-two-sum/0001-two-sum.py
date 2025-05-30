class Solution(object):
    def twoSum(self, nums, target):
        mp = {}
        n = len(nums)

        for i in range(n):
            mp[nums[i]]=i

        for i in range (n):
            c = target - nums[i]
            if( c in mp and mp[c]!=i ):
                return [i, mp[c]]

        return []
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        