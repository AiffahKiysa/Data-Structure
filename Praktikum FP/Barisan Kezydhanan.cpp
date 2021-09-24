#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define mod 1000000007
vector<int> FuncX;
void barisan(){
    int fx;
    for (int i=0; i<1000000; i++){
        if (i==0){
            fx = 11;
        }
        else if (i==1){
            fx = 15;
        }
        else if (i>=2 && i<11){
            fx = ((FuncX[i-1]%mod) + (FuncX[i-2]%mod))%mod;
        }
        else if (i>=11 && i<15){
            fx = ((FuncX[i-11]%mod) + (FuncX[i-2]%mod))%mod;
        }
        else if (i>=15){
            fx = ((FuncX[i-11]%mod) + (FuncX[i-15]%mod))%mod;
        }
        FuncX.push_back(fx);
    }
}

int main()
{
    barisan();
    int t, x;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf("%d", &x);
        printf("%d\n", FuncX.at(x));
    }
    
    return 0;
}
