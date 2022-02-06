/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int l = nums.size();
        int sum=0,ans= INT_MIN;
        for(int i=0;i<l;i++)
        {
            sum+=nums[i];
            ans= max(sum,ans);
            if(sum<0)
                sum=0;
        }
        return ans;
        
    }
};
// @lc code=end

