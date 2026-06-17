class Solution {
public:
    vector<vector<int>> res;

    void f(int i, int n, int k, vector<int>& c) {
        if(c.size() == k) {
            res.push_back(c);
            return;
        }
        if(i == n+1) {
            return;
        }

        c.push_back(i);
        f(i+1, n, k, c);
        c.pop_back();
        f(i+1, n, k, c);
    }

    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> c;
        f(1, n, k, c);
        return res;
    }
};