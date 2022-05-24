//使用递归替代多重循环

#include<iostream>
using namespace std;

#define MAXSIZE 100
int N;
int queensPosition[MAXSIZE];

void nQueens(int n){
    if(n == N){
        for(int i = 0; i < N; i++){
            cout<<queensPosition[i]+1<<" ";
        }
        cout << endl;
        return;
    }
    for(int i=0;i<N;i++){
        int j;
        for(j=0;j<n;j++){
            if(i == queensPosition[j] || abs(i-queensPosition[j]) == abs(j-n)){
                break;
            }
        }
        if(j == n){
            queensPosition[n] = i;
            nQueens(n+1);
        }
    }
}

int main(){
    cin>>N;
    nQueens(0);
    return 0;
}