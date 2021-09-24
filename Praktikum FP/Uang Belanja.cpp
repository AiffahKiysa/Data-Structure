#include <bits/stdc++.h>
using namespace std;

long long int temp[100000];
int uang[100000];   
int N;
bool cek[100000];
    
long long int jumlahKoin(int price) {
    if(price == 0) {
        return 0;
    }
    if(cek[price - 1]) {
        return temp[price - 1];
    }
    if(price < uang[0]) {
        cek[price - 1] = true;
        temp[price - 1] = INT_MAX;
    }
    long long int Min = INT_MAX;
    for(int i=1; i<=N; i++) {
        if(uang[i] <= price){
            Min = min(Min, jumlahKoin(price-uang[i])+1);
        }
    }
    cek[price - 1] = true;
    temp[price - 1] = Min;
    return Min;
}
 
int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> uang[i];
    }
    int price;
    cin >> price;
    
    int hasil = jumlahKoin(price);
    if(hasil < 50000) {
        cout << hasil << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}