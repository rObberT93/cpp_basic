//选择排序
#include<iostream>
using namespace std;

void selectionsort(int *a,int n)
{
    //1.检查递归是否终止
    if(n<=1) return;
    //2.查找最小元素
    int smallest=0;
    for(int i=0;i<n;i++)//尽量写成开区间 被小于的数就是数组大小
    {
        if(a[i]<a[smallest])
        {
            smallest=i;
        }
    }
    //3.将最小元素与a[0]交换（if needed）
    if(smallest)
    {
        swap(a[0],a[smallest]);
    }
//4.对剩余数组继续使用选择排序
selectionsort(a+1,n-1);
}
int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selectionsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    delete[]a;
    return 0;
}