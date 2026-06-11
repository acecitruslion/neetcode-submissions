class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto i : operations) {
            if(i == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b);
                s.push(a);
                s.push(a+b);
            }
            else if(i == "D") {
                int num = s.top();
                s.push(num*2);
            }
            else if(i == "C") {
                s.pop();
            }
            else {
                s.push(stoi(i));
            }
        }
        int res = 0;
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};