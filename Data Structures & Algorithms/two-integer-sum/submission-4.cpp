class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> A;

        for(int i=0;i<n;i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int l = 0;
        int r = n-1;

        while(l<r) {
            int m = A[l].first + A[r].first;

            if(target < m) r--;
            else if(target > m) l++;
            else return {(min(A[l].second, A[r].second)), (max(A[l].second, A[r].second))};
        }

        return {};
    }
};
