class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] || grid[r][c] == 0) {
            return 0;
        }
        vis[r][c] = 1;
        return 1 + dfs(grid, vis, r-1, c) + dfs(grid, vis, r+1, c) + dfs(grid, vis, r, c-1) + dfs(grid, vis, r, c+1);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));

        int maxx = 0;

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    maxx = max(maxx, dfs(grid, vis, i, j));
                }
            }
        }

        return maxx;
    }
};
