#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int l = 0, r = nums.size() - 1;
        int mn = nums[0];
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            mn = min(mn, nums[mid]);
        }
        return min(mn, nums[l]);
    }
};