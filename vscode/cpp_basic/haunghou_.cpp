#include<iostream>
using namespace std;

int n;
//int x,y;
int num;
int pos[15];//记录每个皇后所占用的列号 pos[i]=1~14
bool col[15];//列是否安全
bool l_dia[30];//2-28
bool r_dia[30];//2-28

int Try(int i)//第i行 第j列
{
    for(int j=1;j<=n;j++)
    {
        //if(i==x&&j==y)continue;
        if(col[j]&&r_dia[i-j+n+1]&&l_dia[i+j])
        {
            pos[i]=j;
            col[j]=false;
            r_dia[i-j+n+1]=false;
            l_dia[i+j]=false;
            if(i<n)
                Try(i+1);
            else
                num++;
            //回溯
            col[j]=true;
            r_dia[i-j+n+1]=true;
            l_dia[i+j]=true;
        }
    }
return num;
}

int main()
{
    num=0;
    cin>>n;
    //cin>>x>>y;
    for(int i=0;i<=n;i++)
        col[i]=true;
        
    for(int i=0;i<30;i++)
    {
        l_dia[i]=true;
        r_dia[i]=true;
    }
    cout<<Try(1);
    return 0;
}