#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mink = r;
        while (l <= r)
        {
            int k = (l + r) / 2;
            long long tottime = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                tottime += ceil((double)piles[i] / k);
            }
            if (tottime <= h)
            {
                mink = k;
                r = k - 1;
            }
            else
            {
                l = k + 1;
            }
        }
        return mink;
    }
};