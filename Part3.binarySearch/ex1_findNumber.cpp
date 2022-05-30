#include <iostream>
using namespace std;

#define N 100

bool f1(int a[],int n,int m){
    //枚举法
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==m){
                return 1;
            }
        }
    }
    return 0;
}

bool f2(int a[],int n,int m){
    //二分法
    int b[n],low,high;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //排序
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        low=0;
        high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(b[mid]==m-b[i]){
                cout<<b[mid]<<"+"<<b[i]<<endl;
                return 1;
            }else if(b[mid]>m-b[i]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    }
    return 0;
}

int main(){
    int a[N],n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    if(f1(a,n,m)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    if(f2(a,n,m)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}