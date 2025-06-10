#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1;
        int mxp = 0;
        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                mxp = max(mxp, prices[r] - prices[l]);
            }
            else
            {
                l = r;
            }
            r++;
        }
        return mxp;
    }
};