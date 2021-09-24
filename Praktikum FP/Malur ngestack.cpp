#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> tinggi;
int malur(int N, int gedung){
    int max = 1;
    int Xor = 0;
    int temp = 0;
    if (gedung == N-1){
        return max;
    }
    
    for(int i=gedung; i<N; i++){
        if(temp < tinggi.at(i)){
            Xor = Xor^tinggi.at(i);
            temp = tinggi.at(i);
        }   
    }

    if (max <= Xor){
        max = Xor;
    }
    
    return malur(N, gedung+1);
}

int main(){
    int N;
    tinggi.push_back(0);
    int T;
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> T;
        tinggi.push_back(T);
    }
    
    int hasil = malur(N, 0);
    cout << hasil << endl;
    return 0;
}