#include<iostream>
using namespace std;
int board[15][15];//（1，1）到（n，n）

//置为0表示可以放置 置为1表示不可以放置
/*
1  1  1  1  1
1  1  1  1  1
1  1  1  1  1
1  1  1  1  1
1  1  1  1  1
*/
bool diag_l[30]={0};//左对角线
//(i,j)位置的对角线 i+j （1，1）=2 （14，14）=28 直接相加
bool diag_r[30]={0};//右对角线
//（i，j）j-i+n
bool col[15]={0};//列
bool row[15]={0};//行
int dp[15];//dp[i]=j表示皇后放在第i行（因为按行的顺序往下放置，所以就是第i个皇后）放在第j列
//不用试行 行一定是独立的
int n;
int res=0;//开成全局

void queen(int i)//尝试第i个皇后
{
    for(int j=1;j<=n;j++)//枚举列
    {
        if(col[j]==0&& diag_l[i+j]==0 && diag_r[i-j+n+1]==0)//可以放置 去修改条件
        {
            dp[i]=j;
            col[j]=1;
            diag_l[i+j]=1;
            diag_r[j-i+n]=1;
            if(i+1<=n)//还可以继续尝试
                queen(i+1);
            else//不能继续尝试了 说明找到了一种方法
                res++;

            //回溯 把这一步枚举的清除
            col[j]=0;
            diag_l[i+j]=0;
            diag_r[j-i+n]=0;
        }
    }
}

int main()
{
    cin>>n;//有几个皇后
    queen(1);
    cout<<res;
}