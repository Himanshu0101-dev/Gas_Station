#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;   // net gas across all stations
        int curr_tank = 0;    // current gas while traversing
        int start = 0;        // candidate starting station

        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];

            // If at any point current tank < 0, reset start
            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }

        // If total gas is enough to cover total cost, return start
        return total_tank >= 0 ? start : -1;
    }
};
