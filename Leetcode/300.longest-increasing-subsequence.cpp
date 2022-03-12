/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int ans;
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (nums[j] >)
        //         {
        //             /* code */
        //         }
        //     }
        // }
        vector<int> t(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    t[i] = max(t[i], t[j] + 1);
                }
            }
        }
        auto ans = * max_element(nums.begin(),nums.end());
        return ans;
    }
  
};
// @lc code=end
