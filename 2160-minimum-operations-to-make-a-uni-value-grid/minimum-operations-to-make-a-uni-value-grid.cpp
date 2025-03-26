class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i] - nums[0]) % x!= 0)
            {
                return -1;
            }
        }

        int mid = nums[nums.size()/2];
        int ops=0;

        for(int i=0;i<nums.size();i++)
        {
            ops += abs(nums[i] - mid) / x;
        }

        return ops;
    }
};