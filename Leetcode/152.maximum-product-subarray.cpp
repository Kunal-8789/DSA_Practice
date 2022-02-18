/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int curr_min = nums[0],curr_max=nums[0], ans = nums[0];
        for (int i =1; i < nums.size(); i++)
        {
            int temp=curr_min;
           curr_min=min({nums[i],curr_min*nums[i],curr_max*nums[i]});
           curr_max=max({nums[i],temp*nums[i],curr_max*nums[i]});
           ans=max(ans,curr_max);
        }
        return ans;
    }
};
// @lc code=end
