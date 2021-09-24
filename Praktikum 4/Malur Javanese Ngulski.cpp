#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
 
using namespace std;

int minnode(int n, double keyval[], bool set[]) {
    double min = numeric_limits<double>::max();
    int min_index;
 
    for (int i=0; i<n; i++) {
        if (set[i] == false && keyval[i] < min) {
            min = keyval[i], min_index = i;
        }
    }
    return min_index;
}

void findcost(int n, vector<vector<double>> city) {
    int parent[n];
    double keyval[n];
    bool set[n];

    for (int i=0; i<n; i++) {
        keyval[i] = numeric_limits<int>::max();
        set[i] = false;
    }

    parent[0] = -1;
    keyval[0] = 0;
 
    for (int i=0; i<n-1; i++) {
        int u = minnode(n, keyval, set);
        set[u] = true;

        for (int v = 0; v < n; v++) {
            if (city[u][v] && set[v] == false &&
                city[u][v] < keyval[v]) {
                keyval[v] = city[u][v];
                parent[v] = u;
            }
        }
    }

    double cost = 0;
    for (int i=1; i<n; i++){
        cost += city[parent[i]][i];
    }
    printf("%lf\n", cost);
}

double euclidean(double a, double b, double c, double d){
    double x = a-c;
    double y = b-d;
    double euclid = sqrt(x*x + y*y);
    return euclid;
}

int main()
{
    int n;
    cin >> n;
    double x[n], y[n], h[n];
    vector<vector<double>> city(n, vector<double>(n, 0.0));

    for (int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    for (int i=0; i<n-1; ++i){
        for (int j=i+1; j<n; ++j){
            city[i][j] = euclidean(x[i], y[i], x[j], y[j]) * abs(h[j]-h[i]);
            city[j][i] = city[i][j];
        }
    }
    findcost(n, city);

    return 0;
}
