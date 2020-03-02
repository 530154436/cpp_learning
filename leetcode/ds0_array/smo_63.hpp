//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"

/**
面试题63. 股票的最大利润
    假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

示例 1:
    输入: [7,1,5,3,6,4]
    输出: 5
解释:
    在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
    输入: [7,6,4,3,1]
    输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
 解题思路：打擂台法
    + 遍历数组:
    (1) 记录最大差价: 当前差价 = 当前股价 - 历史最小股价
    (2) 更新最小股价
 */
int maxProfit(vector<int>& prices) {
    int size = (int)prices.size();
    if(prices.empty() || size<2) return 0;

    int min = prices[0];
    int maxDiff = 0;
    for(int i=1; i<size; i++){
        // 当前差价 = 当前股价 - 历史最小股价
        int curDiff = prices[i]-min;
        if(curDiff>maxDiff)
            maxDiff = curDiff;

        // 更新历史最小股价
        if(prices[i]<min)
            min = prices[i];
    }
    return maxDiff;
}
