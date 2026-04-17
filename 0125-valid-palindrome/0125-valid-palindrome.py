class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = "".join(c for c in s if c.isalnum())
        l = 0 
        r = len(s)-1

        while(l<r):
            if(s[l]==s[r]):
                l+=1
                r-=1
            else:
                return False
            
        return True
