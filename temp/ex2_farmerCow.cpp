#include<iostream>
using namespace std;

int f1(int x[],int n){
    //排序
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]>x[j]){
                int temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    
}