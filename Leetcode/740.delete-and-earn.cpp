/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start

class Solution {
public:
    int t[10006];
    int deleteAndEarn(vector<int>& nums) {
       map<int,int>mp;
       int mx = *max_element(nums.begin(),nums.end());

       for (int i = 0; i < nums.size(); i++)
       {
           mp[nums[i]]++;
       }
       t[1]= mp[1];
       t[2]= max(t[1],mp[2]*2);
       for (int i = 3; i <=mx; i++)
       {
           t[i]=max(t[i-1],t[i-2]+mp[i]*i);
       }
       return t[mx];
       
       
    }
};
// @lc code=end

