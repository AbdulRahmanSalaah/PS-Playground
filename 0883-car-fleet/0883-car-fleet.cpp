#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {

        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i)
        {
            int dist = target - position[i];
            double time = (double)dist / speed[i];
            cars[i] = {position[i], time};
        }
        stack<double> st;
        sort(cars.rbegin(), cars.rend());
        for (int i = 0; i < n; ++i)
        {
            double time = cars[i].second;
            if (st.empty() || st.top() < time)
            {
                st.push(time);
            }
        }
        return st.size();
    }
};