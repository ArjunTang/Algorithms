#include<cstdio>
#include<iostream>
#include<cmath> 
#include<algorithm>
using namespace std;
int number[100+1];		//存放输入的数字字符串 
long long num[100+1][100+1];	
long long dp[100+1][100+1];
int m,n;
int Num(int i,int j)
{
	int k,sum=0,temp;
	double t=j-i;
	for(k=i;k<=j;++k,--t)
	{
		temp=pow(10,t);
		sum=sum+number[k]*temp;
	}
	return sum;
}
void calculate(void)
{
	int i,j;
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)
			num[i][j]=Num(i,j);
	/*
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
			printf("%d\t",num[i][j]);
		printf("\n");
	}
	printf("\n");
	*/		
}
int main()
{
	cin>>n>>m;				//在n个数字中插入m个加号 
	int i,j,p,minn=__INT_MAX__;
	for(i=1;i<=n;++i)			//从下标为1开始存放 
		cin>>number[i];
	calculate();
	for(i=1;i<=n;++i)			//在i个数字中插入j个加号 
	{
		for(j=0;j<=m;++j)
		{
			if(j==0)
				dp[i][j]=num[1][i];
			else if(i<=j)
				dp[i][j]=__INT_MAX__;
			else
			{
				minn=__INT_MAX__;
				for(p=j;p<=i-1;++p)
				{
					if(minn>(dp[p][j-1]+num[p+1][i]))
						minn=dp[p][j-1]+num[p+1][i];
				}
				dp[i][j]=minn;
			}
		}
	}
	/*
	for(i=0;i<=n;++i)
	{
		for(j=0;j<=m;++j)
		{
			printf("%d\t",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	cout<<dp[n][m]<<endl;
	return 0;
} 