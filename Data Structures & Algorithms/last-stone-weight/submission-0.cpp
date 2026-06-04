class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int s : stones) {
            maxh.push(s);
        }

        while(maxh.size() > 1) {
            int x = maxh.top();
            maxh.pop();
            int y = maxh.top();
            maxh.pop();

            if(x == y) {
                continue;
            }
            maxh.push(abs(x-y));
        }
        maxh.push(0);
        return maxh.top();
    }
};
