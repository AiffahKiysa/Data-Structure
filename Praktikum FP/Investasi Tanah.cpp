#include <bits/stdc++.h>
using namespace std;

int N;
int M[300][300];

int sumHist(int* arr, int* start, int* finish)
{
    int sum = 0, maxSum = INT_MIN, i;
 
    *finish = -1;
    int local_start = 0;
 
    for (i=0; i<N; ++i){
        sum += arr[i];
        if (sum < 0){
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    if (*finish != -1)
        return maxSum;
 
    maxSum = arr[0];
    *start = *finish = 0;
 
    for (i=1; i<N; i++){
        if (arr[i] > maxSum){
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum()
{
    int maxSum = INT_MIN, Left, Right, Top, Bottom;
    int temp[N], sum, start, finish;
 
    for (int i=0; i<N; ++i) {
        memset(temp, 0, sizeof(temp));
 
        for (int j=i; j<N; ++j) {
 
            for (int k=0; k<N; ++k)
                temp[k] += M[k][j];
 
            sum = sumHist(temp, &start, &finish);

            if (sum > maxSum) {
                maxSum = sum;
                Left = i;
                Right = j;
                Top = start;
                Bottom = finish;
            }
        }
    }
    cout << maxSum << endl;
}
 

int main()
{
    cin >> N;
    
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> M[i][j];
        }
    }

    findMaxSum();

    return 0;
}
