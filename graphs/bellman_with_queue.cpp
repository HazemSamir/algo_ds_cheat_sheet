#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <fstream>
#include <time.h>
#define mod 1000000007
#define M_PI 3.14159265358979323846
#define INF 100000000000000LL
using namespace std;
vector < vector< pair < int , double > > > graph;
double dist[1000010];
int parent[1000010];
bool inQueue[1000010];
int counter[1000010];
int n;
bool bellmanModified(int src)
{
    for(int i =0;i<=n;i++)
        dist[i]=INF,inQueue[i]=false,counter[i]=0,parent[i]=-1;
    dist[src] = 0;
    queue< int > q;
    q.push(src);
    inQueue[src]=true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        inQueue[node] = false;
        for(int i = 0 ; i < graph[node].size() ; i++)
        {
            int toNode = graph[node][i].first;
            double weight = graph[node][i].second;
            if(dist[node] + weight < dist[toNode])
            {
                dist[toNode] = dist[node] + weight;
                parent[toNode] = node;
                if(!inQueue[toNode])
                {
                    q.push(toNode);
                    inQueue[toNode] = true;
                    if(++counter[toNode] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}
