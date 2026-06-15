class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for(int i=0;i<temperatures.size();i++) {
            int temp = temperatures[i];
            while(!st.empty() && st.top().first < temp) {
                auto p = st.top();
                st.pop();
                res[p.second] = i - p.second;
            }
            st.push({temp, i});
        }
        return res;
    }
};
