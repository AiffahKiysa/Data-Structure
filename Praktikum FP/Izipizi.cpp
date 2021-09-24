#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Izipizi{
    int row, colomn;
    int cost;
    bool operator>(const Izipizi &e) const{
        return this->cost > e.cost;
    }
};

int arr_x[] = {-1, 0, 1, 0};
int arr_y[] = {0, 1, 0, -1};

int main()
{
    int Q, N, M;
    cin >> Q;
    for (int i=0; i<Q; i++){
        cin >> N >> M;  
        vector<vector<int> > matrix(N, vector<int>(M));
        for (int j=0; j<N; ++j){
            for (int k=0; k<M; ++k){
                cin >> matrix[j][k];
            }
        }

        priority_queue<Izipizi, vector<Izipizi>, greater<Izipizi> > pq;
        vector<vector<int> > cost(N, vector<int>(M, -1));

        Izipizi graph;
        graph.row = 0;
        graph.colomn = 0;
        graph.cost = matrix[0][0];
        cost[0][0] = graph.cost;
        
        pq.push(graph);
        while (!pq.empty())
        {
            Izipizi v = pq.top();
            pq.pop(); 
            for (int i = 0; i < 4; ++i)
            {
                int r = v.row + arr_x[i];
                int c = v.colomn + arr_y[i];
                if (r<0 || r>=N ){
                    continue;
                }
                if (c<0 || c>=M){
                    continue;
                }
                if (cost[r][c] == -1 || cost[v.row][v.colomn] + matrix[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[v.row][v.colomn] + matrix[r][c];
                    graph.row = r;
                    graph.colomn = c;
                    graph.cost = cost[r][c];
                    pq.push(graph);
                }
            }
        }
        int hasil = cost[N-1][M-1];
        cout << hasil << endl;
    }
    return 0;
}

