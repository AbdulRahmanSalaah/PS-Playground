class Solution(object):
    def topKFrequent(self, nums, k):
        count = Counter(nums)
        top_k = count.most_common(k)
        return [num for num ,freq in top_k]