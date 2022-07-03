/*************************************************
题目:
    ex1:输出前m大的数
    --描述--
        给定一个数组包含n个元素,统计前m大的数并且把这m个数
        从大到小输出.
    --输入--
        第一行包含一个整数n,表示数组的大小(n<100000);
        第二行包含n个整数,表示数组的元素,整数之间以一个空
        格分开.每个整数的绝对值不超过100000000.
        第三行包含一个整数m(m<n).
    --输出--
        从大到小输出前m大的数,每个数一行.
*************************************************/

/*************************************************
分析:
    如果直接快速排序后输出,时间复杂度为O(nlogn);
    如果使用分治处理,时间复杂度为O(n+mlogm).
    若m足够小则可以使时间复杂度降至O(n),下面使用分治处理.
*************************************************/

#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void QuickSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int i = s,j = e;
    int pivot = a[(s+e)/2];
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    QuickSort(a,s,j);
    QuickSort(a,i,e);
}

//把数组前k大的都弄到最右边
void arrangeRight(int a[],int left,int right,int k){
    if(left>=right){
        return;
    }
    if(k==right-left+1){
        return;
    }
    int i = left,j = right;
    int pivot = a[left];
    while(i != j){
        while(i<j && a[j]>=pivot){
            j--;
        }
        swap(a[i],a[j]);
        while(i<j && a[i]<=pivot){
            i++;
        }
        swap(a[i],a[j]);
    }
    if(j-i+1==k){
        return;
    }
    else if(j-i+1>k){
        arrangeRight(a,i+1,right,k);
    }
    else{
        arrangeRight(a,left,i-1,k-j+i-1);
    }
}

int main(){
    int a[]={11, 4, 14, 6, 1, 12, 8, 9, 3, 13, 7, 10, 5, 2, 15};
    int size = sizeof(a)/sizeof(a[0]);
    int k = 5;
    arrangeRight(a,0,size-1,k);
    QuickSort(a,size-k,size-1);
    while(k--){
        cout<<a[--size]<<" ";
    }
    cout<<endl;
    return 0;
}
