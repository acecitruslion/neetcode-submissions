class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int p = 0;

        for(auto c : order) {
            mp[c] = p;
            p++;
        }

        for(int i=0;i<words.size()-1;i++) {
            string a = words[i];
            string b = words[i+1];

            for(int j = 0;j<a.size();j++) {
                if(j == b.size()) return 0;
                if(a[j] != b[j]) {
                    if(mp[a[j]] > mp[b[j]]) {
                        return 0;
                    }
                    break;
                }
            }
        }
        return true;
    }
};