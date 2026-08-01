class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i=1;i<nums.size()+1;i++) {
            x ^= i;
        }
        for(auto i : nums) {
            x ^= i;
        }
        return x;
    }
};
