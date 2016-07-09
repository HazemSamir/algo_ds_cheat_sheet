#include<bits/stdc++.h>
using namespace std ;
#define f first
#define s second
const int maxnode = 20000;
const int maxedge = 200000;
const int oo = 1000000000;
int node, src, dest, nedge;
int head[maxnode], point[maxedge], nt[maxedge], flow[maxedge], capa[maxedge];
int dist[maxnode], Q[maxnode], work[maxnode];

void init(int _node, int _src, int _dest)
{
    node = _node;
    src = _src;
    dest = _dest;
    for (int i = 0; i < node; i++) head[i] = -1;
    nedge = 0;
}

void add(int u, int v,int c)
{
    point[nedge] = v, capa[nedge] = c, flow[nedge] = 0, nt[nedge] = head[u], head[u] = (nedge++);
    point[nedge] = u, capa[nedge] = 0, flow[nedge] = 0, nt[nedge] = head[v], head[v] = (nedge++);
}
bool dinic_bfs()
{
    memset(dist, 255, sizeof (dist));
    dist[src] = 0;
    int sizeQ = 0;
    Q[sizeQ++] = src;
    for (int cl = 0; cl < sizeQ; cl++)
        for (int k = Q[cl], i = head[k]; i >= 0; i = nt[i])
            if (flow[i] < capa[i] && dist[point[i]] < 0)
            {
                dist[point[i]] = dist[k] + 1;
                Q[sizeQ++] = point[i];
            }
    return dist[dest] >= 0;
}

int dinic_dfs(int x, int exp)
{
    if (x == dest) return exp;
    for (int &i = work[x]; i >= 0; i = nt[i])
    {
        int v = point[i], tmp;
        if (flow[i] < capa[i] && dist[v] == dist[x] + 1 && (tmp = dinic_dfs(v, min(exp, capa[i] - flow[i]))) > 0)
        {
            flow[i] += tmp;
            flow[i^1] -= tmp;
            return tmp;
        }
    }
    return 0;
}

int maxFlow()
{
    int result = 0;
    while (dinic_bfs())
    {
        for (int i = 0; i < node; i++) work[i] = head[i];
        while (1)
        {
            int delta = dinic_dfs(src, oo);
            if (delta == 0) break;
            result += delta;
        }
    }
    return result;
}

int main(){
    int t , h ;
    scanf("%d%d",&t,&h) ;
    int s = 0 , des = t+h+1 ;
    init(des+1,s,des) ;
    for(int i = 1 ; i <= t ; i++){
        int x , y ;
        scanf("%d",&x) ;
        add(s,i) ;
        while(x--){
            scanf("%d",&y) ;
            add(i,t+y) ;
        }
    }
    for(int i = 1 ; i <= h ; i++){
        add(t+i,des) ;
    }
    cout << h-maxFlow() ;
    return 0 ;
}
