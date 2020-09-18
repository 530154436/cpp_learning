//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题12. 矩阵中的路径
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
    如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
    例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

    [["a","b","c","e"],
    ["s","f","c","s"],
    ["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

示例 1：
    输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    输出：true

示例 2：
    输入：board = [["a","b"],["c","d"]], word = "abcd"
    输出：false

提示：
    1 <= board.length <= 200
    1 <= board[i].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
 解题思路: 回溯法
    1. 根据给定数组，初始化一个标志位数组 visited
        false: 未走过
        true: 已走过且不能走第二次
    2. 遍历数组，找到与 word 的第一个元素相匹配的矩阵元素，进入judge。
    3. 根据i和j先确定一维数组的位置。
    4. 确定终止条件(直接返回false)：
        (1) 越界
        (2) 当前找到的矩阵值不等于数组对应位置的值
        (3) visited=true
    5. 递归寻找周围四个格子是否符合条件，只要有一个格子符合条件即可，直到 length 达到末尾或者不满足递归条件就停止。
    6. 周围四个格子都没找到，还原一下标志位数组 index 处的标志位，进入下一轮的判断。
 */

bool judge(vector<vector<char>>& board, string word, vector<bool> visited, int i, int j, int rows, int cols, int length){
    if(length==(int)word.size())     //若 length 到达 word 末尾，说明之前的字符都已经匹配成功，直接返回true即可
        return true;

    bool hasPath = false;
    int index = i*cols+j;
    if(i>=0 && j>=0 && i<rows && j<cols && board[i][j]==word[length] && !visited[index]){
        length++;
        visited[index] = true; // 标记走过

        hasPath = judge(board, word, visited, i-1, j, rows, cols, length)       // 向上
                  || judge(board, word, visited, i+1, j, rows, cols, length)    // 向下
                  || judge(board, word, visited, i, j-1, rows, cols, length)    // 向左
                  || judge(board, word, visited, i, j+1, rows, cols, length);   // 向右

        if(!hasPath){       // 回溯
            length--;
            visited[index] = false;
        }
    }
    return hasPath;
}

bool exist(vector<vector<char>>& board, string word) {
    if(board.empty() || board[0].empty()) return false;

    int rows = (int)board.size(), cols = (int)board[0].size(), length=0;    // 矩阵行数列数
    vector<bool> visited (rows*cols, false);                                // 标志位，初始化为false
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(judge(board, word, visited, i, j, rows, cols, length))       // 回溯法
                return true;
        }
    }
    return false;
}