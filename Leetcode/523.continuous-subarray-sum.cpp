/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, rem = 0;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int x = sum % k;
            if (s.find(x) != s.end())
            {
                return true;
            }
            s.insert(rem);
            rem = x;
        }
        return false;
    }
};
// @lc code=end
