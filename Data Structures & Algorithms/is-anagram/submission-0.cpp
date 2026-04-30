class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cS;
        unordered_map<char, int> cT;

        for(auto c : s) cS[c]++;
        for(auto c : t) cT[c]++;

        return cS == cT;
    }
};
