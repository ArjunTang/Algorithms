#include<iostream>
using namespace std;

int f(int m,int n){
    if(m>n)
        return f(n,n);
    if(m==0)
        return 0;
    if(n==0)
        return 1;
    return f(m-1,n)+f(m,n-m);
}

int main(){
    int t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cout<<f(m,n)<<endl;
    }
}