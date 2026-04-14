class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for s in strs:
            sstring = s
            sstring = "".join(sorted(sstring))
            mp[sstring].append(s) 
        return list(mp.values())
