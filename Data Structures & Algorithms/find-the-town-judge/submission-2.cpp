class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // vector<vector<int>> adj(n+1);
        vector<int> out(n+1, 0);
        vector<int> in(n+1, 0);
        
        for(auto p : trust) {
            int u = p[0];
            int v = p[1];

            // adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        for(int i=1;i<n+1;i++) {
            if(out[i]== 0 && in[i] == n-1) {
                return i;
            }
        }
        return -1;
    }
};