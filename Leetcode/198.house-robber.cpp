/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
int t[107];
    int rob(vector<int> &nums)
    {
        
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
    int solve(vector<int> &nums, int i)
    {
        if (i >= nums.size()) 
        {
            return 0;
        }
        if (t[i] != -1)
        {
            return t[i];
        }
        int ans = max(nums[i] + solve(nums, i + 2), solve(nums, i + 1));

        return t[i] = ans;
    }
};
// @lc code=end
