#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;
int A[MAX],maxLen[MAX];
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        maxLen[i]=1;
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<i;j++){
            if(A[i]>A[j]){
                maxLen[i]=max(maxLen[i],maxLen[j]+1);
            }
        }
    }
    cout<<*max_element(maxLen+1,maxLen+N+1)<<endl;
    return 0;
}