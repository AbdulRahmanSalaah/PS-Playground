#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int midValue = matrix[mid / m][mid % m];
            if (midValue == target)
            {
                return true;
            }
            else if (midValue < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};