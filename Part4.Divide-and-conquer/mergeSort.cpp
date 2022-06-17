#include<iostream>
using namespace std;

void merge(int a[],int s, int m,int e,int tmp[]){
    int pd = 0;
    int p1 = s,p2 = m+1;
    while(p1<=m && p2<=e){
        if(a[p1]<a[p2]){
            tmp[pd++] = a[p1++];
        }
        else{
            tmp[pd++] = a[p2++];
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

void mergeSort(int a[],int s,int e,int tmp[]){
    if(s<e){
        int m = (s+e)/2;
        mergeSort(a,s,m,tmp);
        mergeSort(a,m+1,e,tmp);
        merge(a,s,m,e,tmp);
    }
}

int a[10] = {24,3,5,7,9,1,2,4,6,8};
int b[10];
int main(){
    int size = sizeof(a)/sizeof(a[0]);
    mergeSort(a,0,size-1,b);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}