#include <bits/stdc++.h>
#include <stdio.h>

void sorting(long long n){
    while(n>=11){
        if (n%11 == 0 || n%15 == 0){
            printf("YES\n");
            break;
        }
        n = n-11;
    }
    if (n<11){
        printf("NO\n");
    }
}

int main()
{
    int t;
    long long n;
    scanf("%d", &t);

    for (int i=0; i<t; i++){
        scanf("%lld", &n);
        if (n<11){
            printf("NO\n");
        }
        else{
            sorting(n);
        }
    }
    return 0;
}