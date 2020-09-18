//
// Created by Edward on 2018/3/26.
//
#include "../utility/LinearTable/DLinkedLIst.h"


// =========== 测试 =========== //
void test01(){
    DLNode *L;
    int a[10] = {1,3,5,7};
    createDListR(L, a, 4);
    printDLinkedListH(L);
}

void test02(){
    DLNode *L;
    int a[10] = {1,3,5,7};
    createDListR(L, a, 4);
    DLNode *p = findNode(L, 5);
    printf("%d", p->data);
}

void test03(){
    DLNode *L;
    int a[10] = {1,3,5,7};
    createDListR(L, a, 4);
    printDLinkedListH(L);

    DLNode *p = L->next->next->next;
    printf("p: %d\n", p->data);

    DLNode *s = (DLNode *) malloc(sizeof(DLNode *));
    s->data = 10;
    printf("s: %d\n", s->data);

    insertAfterNode(p, s);
    printDLinkedListH(L);
}

void test04(){
    DLNode *L;
    int a[10] = {1,3,5,7};
    createDListR(L, a, 4);
    printDLinkedListH(L);

    DLNode *p = L->next;
    printf("p: %d\n", p->data);
    delAfterNode(p);
    printDLinkedListH(L);
}
// =========== 测试 =========== //

int main(){
    // test01();
    // test02();
    // test03();
    test04();
}

