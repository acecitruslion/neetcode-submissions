class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // vector<vector<int>> vis(r, vector<int>(c, 0));

        queue<pair<int, int>> q;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                    // vis[r][c] = 1;
                }
            }
        }
        while(!q.empty()) {
            auto [row, col] = q.front();
            // int row = q.front().first;
            // int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if(nr < 0 || nc < 0 || nr >= r || nc >= c || grid[nr][nc] != INT_MAX) {
                    continue;
                }

                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
};
