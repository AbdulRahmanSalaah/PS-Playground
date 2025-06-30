#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        // Finding the intersection point
        while (true)
        {
            slow = nums[slow];       // 1 step
            fast = nums[nums[fast]]; // 2 steps
            if (slow == fast)
            {
                break; // Intersection 
            }
        }
        //   entrance to the cycle
        slow = 0; // Reset slow to the start
        while (slow != fast)
        {
            slow = nums[slow]; //  1 step
            fast = nums[fast]; // 1 step
        }
        return slow; //  duplicate number
    }
};