//百练2815
//http://www.bailian.openjudge.cn/practice/2815

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int R,C;
int room[60][60];
int color[60][60];
int maxRoomArea=0,roomNum=0;
int roomArea;
void Dfs(int i,int k){
    if(color[i][k])
        return;
    ++roomArea;
    color[i][k]=roomNum;
    if((room[i][k]&1)==0)
        Dfs(i,k-1);
    if((room[i][k]&2)==0)
        Dfs(i-1,k);
    if((room[i][k]&4)==0)
        Dfs(i,k+1);
    if((room[i][k]&8)==0)
        Dfs(i+1,k);
}
int main(){
    cin>>R>>C;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            cin>>room[i][j];
    memset(color,0,sizeof(color));
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++){
            if(color[i][j]==0){
                roomNum++;
                roomArea=0;
                Dfs(i,j);
                maxRoomArea=max(maxRoomArea,roomArea);
            }
        }
    cout<<roomNum<<" "<<maxRoomArea<<endl;
    return 0;
}