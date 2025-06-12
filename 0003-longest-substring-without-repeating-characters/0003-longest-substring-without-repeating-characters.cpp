#define ll long long
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, ll> mp;
    ll l = 0, r = 0;
    ll res = 0;
    while (r < s.size())
    {
        mp[s[r]]++;
       while(mp[s[r]]>1)
        {
            mp[s[l]]--;
           
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;


    }
};