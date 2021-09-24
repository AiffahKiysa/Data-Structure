#include <stdio.h>
#include <stdlib.h>

typedef struct PartTime{
    int P, Q;
};
PartTime pt[100];

int main()
{
    int M, N, i;
    scanf("%d %d", &M, &N);
    for (i=1; i<=M; i++){
        scanf("%d %d", &(pt[i].P), &(pt[i].Q));
        if (pt[i].P != i){
            printf("ID harus urut\n");
            return 0;
        }
    }
    int X, Y, j, k;
    int hasil=0, count=0, sum=0;
    for (j=0; j<N; j++){
        scanf("%d %d", &X, &Y);
        for (k=1; k<=M; k++){
            if (pt[k].P == Y){
                hasil = X*pt[k].Q;
                count++;
                sum = sum + hasil;
            }
        }
    }
    if (count!=N){
        printf("Maaf barang tidak tersedia\n");
    }
    printf("%d\n", sum);
    return 0;
}
