class Solution {
public:

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || !grid[i][j]) {
            return 0;
        }
        vis[i][j] = 1;
        int res = 4;
        
        for(int k=0;k<4;k++) {
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) res--; 
        }

        return res + dfs(i-1, j, grid, vis) + dfs(i+1, j, grid, vis) + dfs(i, j+1, grid, vis) + dfs(i, j-1, grid, vis);
    }


    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));


        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return dfs(i, j, grid, vis);
                }
            }
        }

        return 0;
    }
};