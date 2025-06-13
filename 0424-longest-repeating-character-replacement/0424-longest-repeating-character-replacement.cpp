#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int l = 0, r = 0;
        int res = 0;
        int maxFreq = 0;

        while (r < s.size()) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);

            while (r - l + 1 - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }
        return res;
        
    }
};