class Solution(object):
    def isAnagram(self, s, t):
        mp = defaultdict(int)

        for ch in s :
            mp[ch]+=1
        for ch in t :
            mp[ch]-=1
        

        for val in mp.values():
            if (val!=0):
                return False
        return True

        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        