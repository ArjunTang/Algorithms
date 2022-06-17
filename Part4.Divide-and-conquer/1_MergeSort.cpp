#include<iostream>
using namespace std;

int cnt = 0;
void Merge(int a[],int s, int m,int e,int tmp[]){
    int pd = 0;
    int p1 = s,p2 = m+1;
    while(p1<=m && p2<=e){
        if(a[p1]<a[p2]){
            tmp[pd++] = a[p1++];
        }
        else{
            tmp[pd++] = a[p2++];
            cnt += m-p1+1;
        }
    }
    while(p1<=m){
        tmp[pd++] = a[p1++];
    }
    while(p2<=e){
        tmp[pd++] = a[p2++];
    }
    for(int i=0;i<e-s+1;i++){
        a[s+i] = tmp[i];
    }
}

void MergeSort(int a[],int s,int e,int tmp[]){
    if(s<e){
        int m = (s+e)/2;
        MergeSort(a,s,m,tmp);
        MergeSort(a,m+1,e,tmp);
        Merge(a,s,m,e,tmp);
    }
}

int a[10] = {4,7,9,2,1,5,3,6,8,0};
int b[10];
int main(){
    int size = sizeof(a)/sizeof(a[0]);
    MergeSort(a,0,size-1,b);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"逆序数为:"<<cnt<<endl;
    return 0;
}