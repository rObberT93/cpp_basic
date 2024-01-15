//导弹拦截问题
//最多拦截多少个导弹就是最长不增子列的长度
#include<iostream>
using namespace std;

int remain(int *a,int n)
{
    int len[100];
    for(int i=0;i<n;i++)
        len[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>=a[i] && len[i]<=len[j]+1)//子列问题处理这里的条件即可
            {
                len[i]=len[j]+1;
            }
        }
    }
    int max=len[0];
    for(int i=1;i<n;i++)
    {
        if(len[i]>max)
            max = len[i];
    }
    return max;
}

int nums(int *a ,int n)
{
    int k=1;//需要k套拦截系统
    int system[100];//system[i]表示第i个拦截系统的高度
    system[1]=a[0];
    for(int i=1;i<n;i++)//依次考察第2个到第n个导弹
    {
        //用拦截系统system[p]去拦截
        int p=0;
        for(int j=1;j<=k;j++)
        {
            if(system[j]>=a[i])//依次尝试已有的拦截系统
            {
                if(p==0)//首次发现可拦截a[i]的拦截系统
                    p=j;
                else if(system[j]<system[p])//在已经可以找到一个拦截系统的基础上，不断更新找到最贴近的那个
                    p=j;
            }
        }
        if(p==0)//始终未能找到拦截的系统
            system[++k]=a[i];//建立心系统
        else system[p]=a[i];//更细被选定的最“俭省”拦截系统的最低高度
    }
    return k;
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res_len=remain(a,n);
    cout<<res_len<<endl;
    int res_num=nums(a,n);
    cout<<res_num<<endl;
    return 0;

}