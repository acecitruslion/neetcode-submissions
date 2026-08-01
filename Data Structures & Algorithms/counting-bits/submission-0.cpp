class Solution {
public:

    int f(int n) {
        int res = 0;
        while(n) {
            n &= (n-1);
            res++;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<n+1;i++) {
            res.push_back(f(i));
        }
        return res;
    }
};
