class Solution {
public:

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for(auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        queue<pair<int, int>> pq, aq;
        vector<vector<bool>> pac(r, vector<bool>(c, 0));
        vector<vector<bool>> atl(r, vector<bool>(c, 0));

        for(int i=0;i<c;i++) {
            pq.push({0, i});
            aq.push({r-1, i});
        }
        for(int j=0;j<r;j++) {
            pq.push({j, 0});
            aq.push({j, c-1});
        }

        bfs(pq, pac, heights);
        bfs(aq, atl, heights);

        vector<vector<int>> res;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
