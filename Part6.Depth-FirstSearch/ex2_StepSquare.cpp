/*************************************************
有一个方格矩阵,矩阵边界在无穷远处.我们做如下假设:
    a.每走一步时,只能从当前方格移动一格,走到某个相邻的方格
      上;
    b.走过的格子立即塌陷无法再走第二次;
    c.只能向北,东,西三个方向走;
请问:如果允许在方格矩阵上走n步(n<=20),共有多少种不同的方案?
    2种走法只要有一步不一样,即被认为是不同的方案.
*************************************************/
#include<iostream>
#include<cstring>
using namespace std;
int visted[30][50];
int ways(int i,int j,int n){
    if(n==0)
        return 1;
    visted[i][j]=1;
    int num=0;
    if(!visted[i][j-1])
        num+=ways(i,j-1,n-1);
    if(!visted[i][j+1])
        num+=ways(i,j+1,n-1);
    if(!visted[i+1][j])
        num+=ways(i+1,j,n-1);
    visted[i][j]=0;
    return num;
}
int main(){
    int n;
    cin>>n;
    memset(visted,0,sizeof(visted));
    cout<<ways(0,25,n)<<endl;
    return 0;
}