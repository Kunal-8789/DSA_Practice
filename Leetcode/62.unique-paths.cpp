/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.27%)
 * Likes:    8198
 * Dislikes: 282
 * Total Accepted:    884.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int t[102][102], ans = 0;
    int uniquePaths(int m, int n)
    {
        memset(t, -1, sizeof(t));
        return solve(0, 0, m, n);
    }
    int solve(int i, int j, int m, int n)
    {
        if (i >= m or j >= n)
        {
            return 0;
        }

        if (i == m and j == n)
        {
            return 1;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        ans += solve(i, j++, m, n) + solve(i++, j, m, n);

        return t[i][j] = ans;
    }
};
// @lc code=end
