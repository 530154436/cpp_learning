//
// Created by Edward on 2020/2/23.
//
#include "../lib.hpp"
/*
面试题11. 旋转数组的最小数字
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
    例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：
    输入：[3,4,5,1,2]
    输出：1

示例 2：
    输入：[2,2,2,0,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
解题思路: 二分查找
   + 将数组分成左右两部分，并且左右两部分分别有序。
   + 初始化左右指针l和r，分别指向首尾元素，每次取中间mid:
    (1) 如果 nums[mid] > nums[r]，说明mid在左侧有序部分，我们排除mid左侧（包括mid）所有元素
    (2) 如果 nums[mid] < nums[r]，说明mid在右侧有序部分，我们排序mid右侧（不包括mid） 所有元素
    (3) 如果 nums[mid] == nums[r]，我们只需要右侧指针左移一位即可。

 */
int minArray(vector<int>& numbers) {
    int size = (int)numbers.size();
    int l=0, r=size-1;
    int m=l;
    while(l<r){
        m = (l+r)/2;
        if(numbers[m]>numbers[r])
            l = m+1;
        else if(numbers[m]<numbers[r])
            r = m;
        else
            r--;
    }
    return numbers[r];
}