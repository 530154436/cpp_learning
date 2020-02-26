//
// Created by 郑楚彬 on 2020/2/2.
//
#include "../lib.hpp"
#include <unordered_map>

/**
347. 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

    示例 1:
        输入: nums = [1,1,1,2,2,3], k = 2
        输出: [1,2]
    示例 2:
        输入: nums = [1], k = 1
        输出: [1]
    说明：
        你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
        你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/top-k-frequent-elements

 哈希表计数, 最小堆(k大小)
 */

// 解题思路:
//  (1) 使用Hash表进行词频统计，并放入容器中
//  (2) 先建一个容量为k的小根堆, 然后把剩下的大于堆顶的元素和堆顶交换并调整堆，则堆中的元素即为TopK

void swap(pair<int,int> &a, pair<int,int> &b){
    pair<int,int> tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void adjustDown(vector<pair<int,int>> &nums, int k, int len){
    pair<int,int> pval = nums[k];
    for(int i=2*k+1; i<len; i=(2*i+1)){
        if(i+1<len && nums[i].second>nums[i+1].second) i++;
        if(pval.second>nums[i].second){
            nums[k] = nums[i];
            k = i;
        }else{
            break;
        }
    }
    nums[k] = pval;
}

void buildMinHeap(vector<pair<int,int>> &nums, int len){
    for(int k=len/2-1; k>=0; k--){
        adjustDown(nums, k, len);
        //cout<<"k="<<k<<",len="<<len<<" 向下调整: ";
        //display(nums);
    }
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Hash统计词频
    unordered_map<int,int> counter;
    for(int item:nums) counter[item]++;
    vector<pair<int,int>> counts(counter.begin(),counter.end());
    //display(counts);

    // 创建最小堆
    buildMinHeap(counts, k);
    //display(nums);

    // 加入新元素
    for(int i=k; i<counts.size(); i++){
        if(counts[i].second>counts[0].second){
            swap(counts[i], counts[0]);
            adjustDown(counts, 0, k);
        }
    }

    vector<int> res;
    for(int i=0; i<k; i++){
        res.push_back(counts[i].first);
    }
    return res;
}