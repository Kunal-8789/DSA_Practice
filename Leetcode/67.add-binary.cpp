/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s;
        int carr = 0;
        int l = max(a.length(), b.length());
        if (a.size() > b.size())
        {
            addz(b, a.size() - b.size());
        }
        else
        {
            addz(a, b.size() - a.size());
        }
        for (int i = l - 1; i >= 0; i--)
        {
            if (a[i] != b[i])
            {
                if (carr == 0)
                {
                    s.push_back('1');
                }
                else
                {
                    s.push_back('0');
                }
            }
            else
            {
                if (a[i] == '0')
                {
                    if (carr == 0)
                    {
                        s.push_back('0');
                    }
                    else
                    {
                        s.push_back('1');
                        carr--;
                    }
                }
                else
                {
                    if (carr == 0)
                    {
                        s.push_back('0');
                        carr++;
                    }
                    else
                    {
                        s.push_back('1');
                    }
                }
            }
            
            
        }
        if (carr!=0)
            {
                s.push_back('1');
            }
            reverse(s.begin(), s.end());
            return s;
    }
    void addz(string &a, int n)
    {
        reverse(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            a.push_back('0');
        }
        reverse(a.begin(), a.end());
    }
};
// @lc code=end
