//
// Created by Edward on 2020/9/7.
//

#ifndef TIANQINDATASTRUCT_LINKLIST_HPP
#define TIANQINDATASTRUCT_LINKLIST_HPP

#include "stdlib.h"

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode, *LinkList;

#endif //TIANQINDATASTRUCT_LINKLIST_HPP
