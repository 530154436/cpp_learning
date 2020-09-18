//
// Created by Edward on 2018/6/1.
//
#define m 3
typedef  int KeyType;

/**
 * 记录
 */
typedef struct Record{
    KeyType key;    // 关键字
    char data;      // 数据域
}Record;

/**
 * B-树节点
 */
typedef struct BTreeNode{
    int                 keynum;         // 节点中关键字个数，即节点的大小
    struct BTreeNode    *parent;        // 指向双亲节点
    KeyType             key[m+1];       // 关键字向量，0号单元未用
    Record              *recptr[m+1];   // 记录指针向量，0号单元未用
    struct BTreeNode    *ptr[m+1];      // 子树指针向量
}BTreeNode, *BTree;

/**
 *  B-树的查找结果类型
 */
typedef struct Result{
    BTreeNode *pt;      // 指向找到的节点
    int i;              // 1...m，在节点中的关键字序号
    int tag;            // 1-查找成功，0-查找失败
}Result;

/**
 * 查找操作
 *
 * @param T
 * @param key
 */
void searchBTree(BTree T, KeyType key){

}


















