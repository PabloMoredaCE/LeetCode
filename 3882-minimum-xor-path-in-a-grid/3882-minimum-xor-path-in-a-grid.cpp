class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<bool>> prev(n, vector<bool>(1024, false));
        prev[0][0] = true;

        for(int i = 0; i < grid.size(); ++i) {
            vector<vector<bool>> current(n, vector<bool>(1024, false));
            for(int j = 0; j < n; ++j) {
                for(int x = 0; x < 1024; ++x) {
                    bool above = prev[j][x];
                    bool left = j > 0 && current[j - 1][x];
                    if(above || left) {
                        current[j][x ^ grid[i][j]] = true;  
                    }
                }
            }
            prev = current;
        }
        int x = 0;
        while(!prev[n - 1][x]) { x++; }
        return x;
    }
};
