class Solution {
public:
    vector<string> createGrid(int m, int n) {
        std::vector<string> grid;
        for(int i = 0; i < m; ++i) {
            std::string path;
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    path += ".";
                } else {
                    if(j != n - 1) {
                        path += "#";
                    } else {
                        path += ".";
                    }
                }

            }
            //Push the row
            grid.push_back(path);
        }
        return grid;
    }
};