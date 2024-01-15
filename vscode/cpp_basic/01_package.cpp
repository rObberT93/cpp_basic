//01背包问题
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int dp[5][9]={0};//背包容量为8，有四个物品，每个只能装一次
int w[5]={0,2,3,4,5};//4件物品的重量
int v[5]={0,3,4,5,8};//4件物品的体积
int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<5;i++)//尝试四件物品
    {
        for(int j=8;j>=0;j--)//遍历容量
        {
            if(w[i]>j)//如果这件物品的重量大于目前的容量，那一定放不进去
                dp[i][j]=dp[i-1][j];
            else//如果这件物品可以放进去，考虑两种情况的最大值
            //1.这件物品放进去了，剩余容量继续放
            //2.不放这件，留下更大的空间
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[4][8]<<endl;
}