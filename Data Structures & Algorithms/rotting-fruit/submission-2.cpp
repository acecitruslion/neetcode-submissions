class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> mins(r, vector<int>(c, 0));

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr < 0 || nc < 0 || nr >= r || nc >= c || grid[nr][nc] != 1) {
                    continue;
                }

                mins[nr][nc] = mins[row][col] + 1;
                grid[nr][nc] = 2;
                q.push({nr, nc});
            }
        }

        int maxx = 0;

        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j] == 1) return -1;
                else if(mins[i][j] > maxx) {
                    maxx = mins[i][j];
                }
            }
        }
        return maxx;
    }
};
