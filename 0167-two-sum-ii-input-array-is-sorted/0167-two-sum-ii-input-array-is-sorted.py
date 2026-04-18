class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        sm = 0
        while l < r:
            sm = numbers[l] + numbers[r]
            if sm > target:
                r -= 1
            elif sm < target:
                l += 1
            else:
                return [l + 1, r + 1]
