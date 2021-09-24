#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;
int total;

class Graph
{
    int V; 
    list< pair<int, int> > *adj;

public:
    Graph(int V); 
    void addEdge(int u, int v, int w);
    void shortestPath(int next, int src);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int next, int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    int count;
    bool visited = false;
    
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                count++;
            }
        }
    }
    
    for(int i=0; i<count; i++){
        if(i==next && visited == false) {
            visited = true;
            total += dist[i];
        }
    }
}

int main()
{
    int V, E, Q;
    cin >> V >> E >> Q;
    Graph g(V);

    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u = u-1;
        v = v-1;
        g.addEdge(u, v, w);
    }

    int q[Q];
    for(int i=0; i<Q; i++){
        cin >> q[i];
        q[i]=q[i]-1;
    }

    for(int i=0; i<Q; i++){
        if (i==Q-1) break;
        int next = q[i+1];
        g.shortestPath(next, q[i]);
    }
    cout << total << endl;
    return 0;
}
