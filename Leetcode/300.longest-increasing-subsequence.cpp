/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> sorted;
        map<int> index;
        for (int i = 0; i < nums.size(); i++)
        {
            if (index[nums[i]].count() == 0)
            {
                index[nums[i]] = i;
                sorted.push_back(nums[i]);
            }
        }
        sort(sorted.begin(),sorted.end());
        for (int i = 0; i < sorted.size(); i++)
        {
            
        }
        
    }
};
// @lc code=end
