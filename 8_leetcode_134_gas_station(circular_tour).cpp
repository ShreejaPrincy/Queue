/************************************************************
 GAS STATION PROBLEM – MULTIPLE APPROACHES
 ************************************************************/

/*
------------------------------------------------------------
1) BRUTE FORCE SIMULATION
------------------------------------------------------------
Approach:
Try starting from every station and simulate the full circular tour.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) {

            // Skip if cannot even reach next station
            if (gas[i] < cost[i]) continue;

            int currGas = gas[i];
            int j = i;

            // Try completing the circle
            while (true) {
                currGas -= cost[j];
                if (currGas < 0) break;

                j = (j + 1) % n;
                currGas += gas[j];

                if (j == i) return i; // Completed full circle
            }
        }
        return -1;
    }
};


/*
------------------------------------------------------------
2) GREEDY WITH TOTAL GAS CHECK
------------------------------------------------------------
Approach:
If total gas is sufficient, reset the starting point whenever current fuel becomes negative.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        // No possible solution
        if (totalGas < totalCost) return -1;

        int currGas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i] - cost[i];

            // Restart from next station if fuel goes negative
            if (currGas < 0) {
                currGas = 0;
                start = i + 1;
            }
        }
        return start;
    }
};


/*
------------------------------------------------------------
3) GREEDY WITH DEFICIT TRACKING (BEST APPROACH)
------------------------------------------------------------
Approach:
Track fuel deficit while traversing once; if total fuel covers deficit, the last reset index is the answer.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int currGas = 0;
        int deficit = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            currGas += gas[i] - cost[i];

            // If fuel becomes negative, store deficit and move start
            if (currGas < 0) {
                deficit += currGas;
                currGas = 0;
                start = i + 1;
            }
        }

        // Check if total fuel is enough to cover deficit
        return (currGas + deficit >= 0) ? start : -1;
    }
};


