//
// Created by Edward on 2018/5/3.
//
#include "MGraph.h"
#include <iostream>
using namespace std;

#define MAX 100
#define INF 10000

/**
 * 最小生成树之 Prim (普里姆算法)
 *
 * @param g   图
 * @param v0  起始顶点
 * @param sum 权值总和
 */
void Prim(MGraph g, int v0, int &sum){
    int lowcost[MAX], vset[MAX], v;
    int i,j,k,min;
    v = v0;

    // 赋初值
    for(i=0; i<g.n; i++){
        lowcost[i] = g.edegs[v][i];
        vset[i] = 0;
    }

    vset[v0] = 1;
    sum = 0;
    for(i=0; i<g.n-1; i++){
        min=INF;
        // 选出候选边中的最小者
        for(j=0; j<g.n; j++){
            if(vset[j]==0 && lowcost[j]<min){
                min = lowcost[j];
                k = j;
            }
        }
        vset[k]=1;
        sum += min;
        v = k;

        // 以刚加入的顶点 v 为媒介更新候选边
        for(j=0; j<g.n; j++){
            if(vset[j]==0 && g.edegs[v][j]<lowcost[j]){
                lowcost[j] = g.edegs[v][j];
            }
        }
    }
}