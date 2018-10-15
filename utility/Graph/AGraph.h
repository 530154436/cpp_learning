//
// Created by 郑楚彬 on 2018/5/3.
//
#include <iostream>
using namespace std;

#define MAX 100

/**
 * 弧-节点
 */
typedef struct ArcNode{
    int adjvex;               // 边指向的顶点编号
    struct ArcNode* nextarc;  // 指向下一条边的指针
    int info;                 // 边的相关信息，如权值
} ArcNode;

/**
 * 顶点类型
 */
typedef struct VNode{
    char data;          // 顶点信息
    ArcNode *firstarc;  // 指向第一条边的指针
} VNode;

/**
 * 邻接表
 */
typedef struct AGraph{
    VNode adjlist[MAX]; // 邻接表
    int n;              // 顶点数
    int e;              // 边数
} AGraph;


// 记录顶点的访问记录
int visit[MAX];

/**
 * 图的深度优先搜索算法 (DFS)
 *
 * @param g 邻接表
 * @param v 顶点编号
 */
void DFS(AGraph* g, int v){
    ArcNode *p;

    // 设置已访问
    visit[v] = 1;

    // 访问操作
    cout << g->adjlist[v].data << ' ';

    // 顶点 v 的第一条边
    p = g->adjlist[v].firstarc;
    while(p!=NULL){
        // 边指向的终点
        if(visit[p->adjvex] == 0){
            DFS(g, p->adjvex);
        }
        p = p->nextarc;
    }
}

void dfs(AGraph* g){
    int i;
    // 对图所有顶点的标志位进行初始化
    for(i=0; i<g->n; i++){
        visit[i] = 0;
    }
    // 检查图的所有顶点是否被标记过，如果未被标记，则从该未被标记的顶点开始继续遍历
    for(i=0; i<g->n; i++){
        if(visit[i]==0){
            DFS(g, i);
        }
    }
}

/**
 * 图的广度优先搜索算法 (BFS)
 *
 * @param g 邻接表
 * @param v 顶点编号
 */
void BFS(AGraph *g, int v){
    int vertex;
    ArcNode* p;

    // 定义队列
    int queue[MAX], front=0, rear=0;

    // 当前顶点入队
    rear = (rear+1)%MAX;
    queue[rear] = v;

    while(front != rear){
        // 队头出队
        front = (front+1) % MAX;
        vertex = queue[front];

        // 访问队头节点
        visit[vertex] = 1;
        cout << g->adjlist[vertex].data;

        p = g->adjlist[vertex].firstarc;
        while(p!=NULL){
            // 邻接顶点若未访问则入队
            if(visit[p->adjvex] == 0){
                rear = (rear+1) % MAX;
                queue[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}

void bfs(AGraph* g){
    int i;
    // 对图所有顶点的标志位进行初始化
    for(i=0; i<g->n; i++){
        visit[i] = 0;
    }
    // 检查图的所有顶点是否被标记过，如果未被标记，则从该未被标记的顶点开始继续遍历
    for(i=0; i<g->n; i++){
        if(visit[i]==0){
            BFS(g, i);
        }
    }
}

