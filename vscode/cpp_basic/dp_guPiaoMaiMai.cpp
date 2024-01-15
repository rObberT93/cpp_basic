#include<iostream>
using namespace std;

//动态规划dp[n][2]
//dp[i][0]表示截至到第i天 手里还有股票 说明前面买入 没卖出去 一定是负数
//dp[i][0]=max(dp[i-1][0],-a[i])
//dp[i][1]表示截至到第i天 手里没有股票 可能是今天卖出去的 也可能是保留i-1天的最大值
//如果第i天的价值小于第i-1天，则选择卖出第i天的而不是第i-1天的
//dp[i][1]=max(dp[i-1],dp[i-1]-a[i]+a[i-1])
int curr_max(int *a,int n)
{
    int**dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int[2];
    if(n==1) return 0;
    dp[0][0]=-a[0];
    dp[0][1]=0;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][0],(-a[i]));
        dp[i][1]=max(dp[i-1][1],dp[i-1][1]-a[i]+a[i-1]);
    }
    int res=max(dp[n-2][0],dp[n-1][1]);
    for(int i=0;i<2;i++)
        delete []dp[i];
    delete []dp;
    return res;
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int res=curr_max(a,n);
    cout<<res;
    delete []a;
    return 0;

}