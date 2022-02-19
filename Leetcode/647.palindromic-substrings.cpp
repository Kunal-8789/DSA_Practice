/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution
{
public:
    int t[1003][1003];
    int countSubstrings(string s)
    {
        int n = s.size();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
    }
    int ans=0;
    int solve(string s,int i, int j)
    {
        if (i>j)
        {
            return 0;
        }
        if (t[i][j]!=-1)
        {
            return t[i][j];
        }
         if (isPalindrome(s,i,j))
        {
            return 0;
        }
        

        for (int k = i; k < j; k++)
        {
            int temp = solve(s,i,k) + solve(s,k+1,j)+1;
            if (temp>ans)
            {
                ans=temp;
            }
            
            
        }
       
        return t[i][j]=ans;
        
        
    }
     bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end
