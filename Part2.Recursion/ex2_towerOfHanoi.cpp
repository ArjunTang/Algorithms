//使用递归将复杂问题拆解为简单问题

#include<iostream>
using namespace std;

void hanoi(int n,char src,char mid,char dest,int & counts){
    if(n==1){
        cout<<counts<<"."<<src<<"->"<<dest<<endl;
        counts++;
        return;
    }
    hanoi(n-1,src,dest,mid,counts);
    cout<<counts<<"."<<src<<"->"<<dest<<endl;
    counts++;
    hanoi(n-1,mid,src,dest,counts);
    return;
}

int main(){
    int n,counts;
    cin>>n;
    hanoi(n,'A','B','C',counts);
    cout<<"Total moves: "<<counts-1<<endl;
    return 0;
}