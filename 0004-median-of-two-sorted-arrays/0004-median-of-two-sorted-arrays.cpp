#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int half = (n1 + n2 + 1) / 2;
        if (n1 > n2) 
        {
            swap(nums1, nums2);
            swap(n1, n2);
        }

        int l = 0, r = n1;
        while (l <= r)
        {
            int midx = (l + r) / 2;
            int partitionY = half - midx;

            int maxX = (midx == 0) ? INT_MIN : nums1[midx - 1];
            int minX = (midx == n1) ? INT_MAX : nums1[midx];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == n2) ? INT_MAX : nums2[partitionY];

            if (maxX <= minY && maxY <= minX)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                }
                else
                {
                    return max(maxX, maxY);
                }
            }
            else if (maxX > minY)
            {
                r = midx - 1;
            }
            else
            {
                l = midx + 1;
            }
        }
        return 0.0; 
    }
};