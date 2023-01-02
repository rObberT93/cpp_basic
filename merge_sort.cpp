#include <iostream>
using namespace std;
int pn[10000000];//临时数组

void merge(int *p,int n)
{
    if(n<=1)return;
    int ll=n/2;//左子列的长度
    int rr=n-n/2;//右子列的长度
    merge(p,ll);
    merge(p+ll,rr);

    // int *pn=new int[n];//每次调用函数往里new数组速度很慢 也可以放在函数里每次new
    int i=0,j=ll,k=0;
    while(i<ll && j<n)
    {
        if(p[i]>p[j])
            pn[k++]=p[j++];
        else
            pn[k++]=p[i++];
    }
    /*
    for(;i<ll;i++)
        pn[k++]=p[i];
    for(;j<n;j++)
        pn[k++]=p[j];
    */
    while(i<ll)
        pn[k++]=p[i++];
    while(j<n)
        pn[k++]=p[j++];
    for(int s=0;s<n;s++)
        p[s]=pn[s];
    /*
    可以从递归的根节点往上输出每个排序之后的子序列
    for(int i=0;i<n;i++)
        cout<<pn[i]<<" ";
    */
    //delete[]pn;
}
int main()
{
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    merge(p,n);
    for(int i=0;i<n;i++)
        cout<<p[i];
    delete[]p;
}