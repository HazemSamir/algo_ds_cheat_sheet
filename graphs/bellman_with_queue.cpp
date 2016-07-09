#define MAXN 1000010

struct edge {int toNode; double weight;};

vector<edge> graph[MAXN];
double dist[MAXN];
int parent[MAXN];
bool inQueue[MAXN];
int counter[MAXN];
int n;

bool bellmanModified(int src)
{
    for(int i=0; i<=n; i++)
        dist[i]=INF,inQueue[i]=false,counter[i]=0,parent[i]=-1;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQueue[src] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        inQueue[node] = false;
        for(auto ed : graph[node]) {
            if(dist[node] + ed.weight < dist[ed.toNode]) {
                dist[ed.toNode] = dist[node] + ed.weight;
                parent[ed.toNode] = node;
                if(!inQueue[ed.toNode]) {
                    q.push(ed.toNode);
                    inQueue[ed.toNode] = true;
                    if(++counter[ed.toNode] >= n) // negative cycle
                        return false;
                }
            }
        }
    }
    return true;
}
