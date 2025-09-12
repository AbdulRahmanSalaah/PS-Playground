class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        for (int i = 0; i < gas.size(); i++)
            totalGas += gas[i];
        for (int i = 0; i < cost.size(); i++)
            totalCost += cost[i];

        if (totalCost > totalGas)
            return -1;

        int total = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};