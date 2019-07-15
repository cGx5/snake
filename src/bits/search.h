#ifndef search_h
#define search_h

typedef struct result {
    int *fa;    // fa[v] 表示 v 的父亲是  fa[v]
    char *dir;  // dir[v]  表示 u 到 v 的方向
    int *dis;   // dis[v]  表示 src 到 v 的距离
    int pos;    // 找到的第一个豆子的位置编号 
} result;

result bfs(graph *g, int src, int flag); // g 表示图  src 起点  flag 表示是否找最近的一个豆子   1 表示是找最近的豆子， 0 表示遍历一个图

void print(int fa[], char dir[], int u);

void result_free(result *res);

#endif
