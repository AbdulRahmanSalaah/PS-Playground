#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        map<char, int> mp;
        int maxLength = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l)
            {
               
                l = mp[s[r]] + 1; 
            }
            mp[s[r]] = r;                         
            maxLength = max(maxLength, r - l + 1); 
            r++;                                   
        }
        return maxLength;
    }
};