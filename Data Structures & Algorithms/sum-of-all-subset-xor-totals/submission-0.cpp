class Solution {
public:

    void f(int i, vector<int>& nums, int xorr, int& sum) {
        if(i >= nums.size()) {
            sum += xorr;
            return;
        }

        xorr^=nums[i];
        f(i+1, nums, xorr, sum);
        xorr^=nums[i];
        f(i+1, nums, xorr, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        f(0, nums, 0, sum);
        return sum;
    }
};