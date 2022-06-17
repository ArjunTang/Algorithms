/*

总时间限制: 1000ms 内存限制: 65536kB

--描述--
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other,
FJ want to assign the cows to the stalls,
such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?

农夫John 建造了一座很长的畜栏，它包括N (2≤N≤100,000)个隔间，
这些小隔间的位置为x[0],...,x[N-1] (0≤x ≤1,000,000,000,均为整数,各不相同)，
John的C (2<CSN)头牛每头分到一个隔间。牛都希望互相离得远点省得互相打扰。
怎样才能使任意两头牛之间的最小距离尽可能的大，这个最大的最小距离是多少呢？

--输入--
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

--输出--
* Line 1: One integer: the largest minimum distance

--样例输入--
5 3
1
2
8
4
9

--样例输出--
3

--提示--
OUTPUT DETAILS:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
Huge input data,scanf is recommended.

--来源--
USACO 2005 February Gold

*/

#include<iostream>
using namespace std;

int f1(int *p,int n,int c){
    //排序
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]>p[j]){
                int temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    //二分法求最小距离
    int left=0;
    int right=n-1;
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(mid==0){
            return p[mid+c-1]-p[mid];
        }
        if(p[mid]>p[mid-1]){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return p[mid]-p[mid-c+1];
}

int main(){
    int n,c,x[100000];
    int *p=x;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    cout<<f1(p,n,c)<<endl;

    return 0;
}