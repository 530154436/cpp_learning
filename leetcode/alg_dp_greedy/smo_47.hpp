//
// Created by 郑楚彬 on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题47. 礼物的最大价值
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:
    输入:
    [
      [1,3,1],
      [1,5,1],
      [4,2,1]
    ]
    输出: 12
解释:
    路径 1→3→5→2→1 可以拿到最多价值的礼物
 
提示：
    0 < grid.length <= 200
    0 < grid[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路: 动态规划 (辅助二维数组)
    初始值：
        d[0][0] = grid[0][0]
        d[i][0] = d[i-1][0] + grid[i][0]
        d[0][j] = d[0][j-1] + grid[0][j]
    递推:
        d[i][j] = max(d[i−1][j],d[i][j−1]) + grid[i][j]
        d_{i,j} 表示到坐标$(i,j)$的格子时能拿到的礼物总和的最大值.
 */
int maxValue(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int m=(int)grid.size(), n=(int)grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int left=0, up=0;   // 第0行、第0列
            if(i>0)
                up = dp[i-1][j];
            if(j>0)
                left = dp[i][j-1];
            dp[i][j] = (up>left?up:left) + grid[i][j]; // 到坐标(i,j)的格子时能拿到的礼物总和的最大值.
        }
    }
    return dp[m-1][n-1];
}