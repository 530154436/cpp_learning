//
// Created by 郑楚彬 on 2018/5/3.
//
#include "../utility/Graph/AGraph.h"

/* ================================= 例题选讲 ================================= */
/*
 * 例题 5.1 设计一个算法，求不带权无向连通图 G 中距离顶点 v 最远的一个顶点
 *     (所谓最远就是到达 v 路径长度最长)
 */
int BFS_1(AGraph* G, int v){
    ArcNode* p;
    int i,j;

    // 队列定义
    int que[MAX], front=0,rear=0;

    // 访问纪录
    int visit[MAX];
    for(i=0; i<G->n; i++) visit[i]=0;

    // 入队
    rear = (rear+1) % MAX;
    que[rear] = v;
    while(front != rear){
        front = (front+1) % MAX;
        j = que[front];
        visit[j] = 1;
        p = G->adjlist[j].firstarc;
        while(p != NULL){
            // 入队
            if(visit[p->adjvex] == 0){
                rear = (rear+1) % MAX;
                que[rear] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
    // 队空的时候 j 保存了遍历过程中的最后一个节点
    return j;
}

/*
 * 例题 5.2 设计一个算法，判断无向图 G 是否是一棵树。若是树，返回 1，否则返回 0。
 *
 * 思路：一个无向图是一棵树的条件是有 n-1 条边的连通图
 */
void DFS2(AGraph* G, int v, int &vn, int &en){
    ArcNode* p;
    // 顶点数 +1
    vn++;
    visit[v] = 1;
    p = G->adjlist[v].firstarc;
    while(p!=NULL){
        // 边数 +1
        en++;
        if(visit[p->adjvex] != 0){
            DFS2(G,p->adjvex, vn, en);
        }
        p = p->nextarc;
    }
}

int GisTree(AGraph* G){
    int i, v=0, vn=0, en=0;
    for(i=0; i<G->n; i++){
        visit[i] = 0;
    }
    DFS2(G, v, vn, en);

    // 判断是否有 n-1 条边
    if(vn==G->n && G->n==en/2){
        return 1;
    }else{
        return 0;
    }
}

/*
 * 例题 5.3 图采用邻接表存储，设计一个算法，判别顶点 i 和 j (i!=j) 之间是否存在路径。
 */
int DFSTravel(AGraph* G, int i, int j){
    int k;
    for(k=0; i<G->n; k++){
        visit[k]=0;
    }

    DFS(G, i);
    // 等于1说明访问过程中遇到了j
    if(visit[j]==1){
        return 1;
    }else{
        return 0;
    }
}
/* ================================= 例题选讲 ================================= */










