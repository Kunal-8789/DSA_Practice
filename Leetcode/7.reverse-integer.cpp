/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        
        
       

       
       long long int ans=0 ;
        while (x != 0)
        {
            ans= ans*10 + (x%10);
            x /= 10;
        }
        if (ans>INT32_MAX  or ans <INT32_MIN)
        {
            return 0;
        }
        
        return (int) ans;
    }
};
// @lc code=end
