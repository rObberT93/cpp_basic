#include<iostream>
using namespace std;
int p[100000];
void merge(int begin,int end,int *nums)
{
    //1.递归终止条件
    if(begin>=end) return;
    int m=(begin+end)/2;
    //2.把两个子数组分开排序
    merge(begin,m,nums);
    merge(m+1,end,nums);
    //3，合并有序子数组中的元素
    int i=begin;
    int j=m+1;
    int index=begin;
    //3.1 传入新数组
    //3.2 依次取出子数组的元素，进行合并
    while(i<=m && j<=end)//左闭右闭
    {
        if(p[i]<=p[j])
            p[index++]=nums[i++];
        else
            p[index++]=nums[j++];
    }
    //3.3 如果子数组没有取完，则全部放入临时空间
    while(j<end)
        p[index++]=nums[j++];
    while(i<m)
        p[index++]=nums[i++];
    //3.4 从临时空间复制会返回数组中
    for(int s=begin;s<end;s++)
        nums[s]=p[s];
}
int main()
{
    int n;
    cin>>n;
    int *nums=new int [n];
    for(int i=0;i<n;i++)
        cin>>nums[i];
    // int *p=new int [n];
    for(int i=0;i<n;i++)
        p[i]=nums[i];
    //int p[8]={3,2,1,4,8,6,5,7};
    merge(0,n-1,nums);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    delete []nums;
}