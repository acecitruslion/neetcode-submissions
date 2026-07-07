class Solution {
public:

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] == 1 || grid[r][c] == 0) {
            return;
        }

        vis[r][c] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, -1, 0, 1};

        if(grid[r][c] == '1') {
            dfs(grid, vis, r, c-1);
            dfs(grid, vis, r, c+1);
            dfs(grid, vis, r+1, c);
            dfs(grid, vis, r-1, c);
        }

        // for(int i=0;i<4;i++) {
        //     int nr = 
        // }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vis(r, vector<int>(c, 0));

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};
