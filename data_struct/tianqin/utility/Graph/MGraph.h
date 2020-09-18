//
// Created by Edward on 2018/5/3.
//

#define MAX 100

/**
 * 顶点类型
 */
typedef struct VertexType{
    int no;     // 顶点编号
    char info;  // 顶点其他信息
} VertexType;

/**
 * 邻接矩阵
 */
typedef struct MGraph{
    int edegs[MAX][MAX];   // 邻接矩阵
    int n, e;              // 顶点数和边数
    VertexType vex[MAX];   // 图的邻接矩阵类型
} MGraph;