#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        map<char, int> count1, count2;
        for (char c : s1)
        {
            count1[c]++;
        }
        int n = s1.size(), m = s2.size();

        if (n > m)  
            return false;

        for (int i = 0; i < n; i++)  
        {
            count2[s2[i]]++;
        }

        if (count1 == count2)   
            return true;
        for (int i = n; i < m; i++)
        {
            count2[s2[i]]++;   
            count2[s2[i - n]]--;
            if (count2[s2[i - n]] == 0)  
            {
                count2.erase(s2[i - n]);
            }
            if (count1 == count2)
                return true;
        }
        return false;
    }
};