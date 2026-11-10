class Solution {
public:
    vector<int> memo;

    int solve(int i, int n, vector<int>& costs) {
        if(i == n) { return 0; }
        if(memo[i] != -1) { return memo[i]; }

        int var = INT_MAX;
        int j = i + 1;
        if(j <= n) {
            var = solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i);
        }

        j = i + 2;
        if(j <= n) {
            var = min(var, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));
        }

        j = i + 3;
        if(j <= n) {
            var = min(var, solve(j, n, costs) + costs[j - 1] + (j - i) * (j - i));
        }

        return memo[i] = var;
    }
    
    int climbStairs(int n, vector<int>& costs) {
       memo.assign(n + 1, -1);
       return solve(0, n, costs);
    }
};