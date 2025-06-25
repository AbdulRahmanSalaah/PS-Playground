#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> out(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;
        while (r < n)
        {
            while (!q.empty() && nums[q.back()] <= nums[r])
            {
                q.pop_back();
            }
            q.push_back(r);
 
            if (l > q.front())  // to handle the cose of k being 1
            {
                q.pop_front();
            }

            if ((r + 1) >= k)
            {
                out[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return out;
    }
};