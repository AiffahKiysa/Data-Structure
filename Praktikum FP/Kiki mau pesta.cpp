#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

double X[105];
double Y[105];

double Euclidean(int f1, int f2){
    double x = X[f1] - X[f2];
    double y = Y[f1] - Y[f2];
    return sqrt(x * x + y * y);
}

struct Distance{
    double Ds;
    int f1, f2;
    bool operator<(const Distance & other) const{
        return Ds < other.Ds;
    }
};

Distance total_Ds[105*105];
bool connected[105];
double totalCost;

void Connect(const Distance &dist)
{
    connected[dist.f1] = connected[dist.f2] = true;
    totalCost += dist.Ds;
}

int main()
{
    int testcase;
    cin >> testcase;
    for (int i=0; i<testcase; ++i){
        if (i) cout << endl;
        int n;
        cin >> n;
        for (int i=0; i<n; ++i){
            cin >> X[i] >> Y[i];
            connected[i] = false;
        }

        int num_Ds = 0;
        for (int i=0; i<n; ++i){
            for (int j=0; j<i; ++j){
                double Ds = Euclidean(i, j);
                total_Ds[num_Ds].Ds = Ds;
                total_Ds[num_Ds].f1 = i;
                total_Ds[num_Ds].f2 = j;
                ++num_Ds;
            }
        }

        sort(total_Ds, total_Ds + num_Ds);
        totalCost = 0;
        int k =2;
        Connect (total_Ds[0]);

        for (; k<n; ++k){
            for (int l=1; ;++l){
                if (connected[total_Ds[l].f1] ^ connected[total_Ds[l].f2]){
                    Connect (total_Ds[l]);
                    break;
                }
            }
        }
        cout << setprecision(2) << fixed;
        printf("%.2lf\n", totalCost);
    }
    return 0;
}