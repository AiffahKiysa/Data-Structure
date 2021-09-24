#include <bits/stdc++.h>
#define INF 999999999

using namespace std;

class Graph {
    int V, E;
    int **mat;
    bool *visited;
    bool *isLeaf;
    int minLeafDist;
    int minLeaf;

public:


    Graph(int v, int e) {     
        this->V = v;
        this->E = e;
        this->minLeafDist = INF;

        visited = new bool[v];
        for (int i = 0; i < v; ++i) 
            visited[i] = false;

        isLeaf = new bool[v];
        for (int i = 0; i < v; ++i) 
            isLeaf[i] = false;

        mat = new int*[v];
        for (int i = 0; i < v; ++i) {
            mat[i] = new int[v];
            for (int j = 0; j < v; ++j) 
                mat[i][j] = 0;
        }
    }

    void addEdge(int u, int v, int w) {
        mat[u][v] = w;
        mat[v][u] = w;
    }

    void DFS(int u, bool visited[], int dist) {
        
        bool over = true;   // true jika sampai node leaf
        visited[u] = true;  // node ditandai visited

        for (int v = 0; v < V; ++v) {   // untuk setiap neighbor
            if (mat[u][v] != 0 && !visited[v]) {   
                DFS(v, visited, dist + mat[u][v]); // dist di tambahkan weight
                over = false;                      // DFS berlanjut/belum leaf
            }
        } 

        if (over && u != 0) {       
            if (minLeafDist > dist) {   // update jarak terpendek & leaf terdekat
                minLeafDist = dist;     
                minLeaf = u;
            } else if (minLeafDist == dist) {  // jika jarak sama
                minLeaf = min(minLeaf, u);     // pilih leaf # terkecil
            }
        }
    }

    int findMinLeaf(int u) {

        minLeafDist = INF;  

        int neighborCount = 0;                      // hitung jumlah neighbor 
        for (int i = 0; i < V; ++i)                 
            if (mat[u][i] != 0) neighborCount++;     

        if (neighborCount == 1 && u != 0) return u; // jika bukan node 0 &
                                                    // leaf node, kembalikan node
        for (int i = 0; i < V; ++i) 
            visited[i] = false;     // belum ada yang visited

        int dist = 0;           // jarak menuju node leaf
        DFS(u, visited, dist); 

        return minLeaf;
    }

};

int main() {

    int V, E;
    cin >> V >> E;         
    Graph tree(V, E);     

    int u, v, w;
    for(int i = 0; i < E; ++i) {   // input edge
        cin >> u >> v >> w;
        tree.addEdge(u, v, w);    
    } 

    int Q, q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {  // query
        cin >> q;
        cout << tree.findMinLeaf(q) << endl;
    }

    return 0;
}