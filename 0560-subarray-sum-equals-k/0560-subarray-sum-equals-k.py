class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        prefix_sum = 0
        mp = {0: 1}

        for num in nums:
            prefix_sum += num
            diff = prefix_sum - k
            count += mp.get(diff, 0)

            mp[prefix_sum] = mp.get(prefix_sum, 0) + 1

        return count
