#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9+77;

int N, M;
int a[150];
int dp[100][10000];

int solve(int id, int sum){
    if(id == N){
        if(sum > 5000){
            return 0;
        }
        return inf;
    }

    int &res = dp[id][sum];
    if(res != -1){
        return res;
    }

    res = inf;
    if(id != M-1){
        res = min(res, solve(id+1, sum));
    }

    res = min(res, solve(id+1, sum+a[id]) + a[id]);
    return res;
}
 
 
int main(){
    while(scanf("%d %d", &N, &M) != EOF){
        memset(dp , -1 , sizeof(dp));
        if (!N && !M){
            break;
        }
        for(int i=0 ; i<N; ++i){
            int x1, x2;
            scanf("%d.%d" , &x1, &x2);
            a[i] = x1 * 100 + x2;
        }
        double ans;
        if (a[M-1] > 5000){
            ans = 100.00;
        }
        else{
            int res = solve(0, 0);
            ans = (1.0 * a[M-1] * 100.0) / res;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
return 0;
}