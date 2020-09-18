//
// Created by Edward on 2020/2/15.
//
#include "../lib.hpp"
/**
面试题04. 二维数组中的查找
    在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
    现有矩阵 matrix 如下：
    [
      [1,   4,  7, 11, 15],
      [2,   5,  8, 12, 19],
      [3,   6,  9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30]
    ]
    给定 target = 5，返回 true。
    给定 target = 20，返回 false。

限制：
    0 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
+ 解题思路：
    1. **标志数**引入： 此类矩阵中左下角和右上角元素有特殊性，称为标志数。
        `左下角`元素： 为所在列最大元素，所在行最小元素。
        `右上角`元素： 为所在行最大元素，所在列最小元素。
    2. **标志数**性质： 将 matrix 中的右上角元素（标志数）记作 flag ，则有:
        (1)若 flag > target ，则 target 一定在 flag 所在行的下方，即 flag 所在行可被消去。
        (2)若 flag < target ，则 target 一定在 flag 所在列的左方，即 flag 所在列可被消去。

    3. 从矩阵 matrix 右上角元素（索引设为 (i, j) ）开始遍历，并与目标值对比：
        当 target > matrix[i][j] 时： 行索引向下移动一格（即 i++），即消去矩阵第 i 行元素；
        当 target < matrix[i][j] 时： 列索引向左移动一格（即 j--），即消去矩阵第 j 列元素；
        当 target == matrix[i][j] 时： 返回 true 。
    4. 若行索引或列索引越界，则代表矩阵中无目标值，返回 false 。

作者：jyd
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
Java
 */
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) return false;

    int n=(int)matrix.size(), m=(int)matrix[0].size();
    int i=0, j=m-1;
    while(i<n && j>=0){
        if(target<matrix[i][j]){
            j--;
        }else if(target>matrix[i][j]){
            i++;
        }else{
            return true;
        }
    }
    return false;
}