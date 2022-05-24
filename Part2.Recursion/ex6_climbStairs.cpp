//使用递归将问题分解为规模更小的子问题进行求解

#include<iostream>
using namespace std;
int f(int n){
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else
        return f(n-1)+f(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}