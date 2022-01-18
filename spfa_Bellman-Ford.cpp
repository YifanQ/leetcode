#include <functional>
#include<vector>
#include <queue>
#include<iostream>

using namespace std;
# define INF 0x3f3f3f3f

// iPair ==> Integer Pair（整数对）
typedef pair<int, int> iPair;

// 加边
void addEdge(vector<vector<pair<int, int>>> &adj, int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}


// 计算最短路
void shortestPath(vector<vector<pair<int,int>>> &adj, int V, int src)
{
    // 关于stl中的优先队列如何实现，参考下方网址：
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    // 距离置为正无穷大
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    // 插入源点，距离为0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* 循环直到优先队列为空 */
    while (!pq.empty())
    {
        // 每次从优先队列中取出顶点事实上是这一轮最短路径权值确定的点
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        // 遍历所有边
        for (auto x : adj[u])
        {
            // 得到顶点边号以及边权
            int v = x.first;
            int weight = x.second;

            //可以松弛
            if (dist[v] > dist[u] + weight)
            {
                // 松弛
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // 打印最短路
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
int main()
{
    vector<int> arr = {7,6,9,6,9,6,9,7};

    int V = 9;
    vector<vector<iPair>> adj(V);
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}
