//二分查找
#include<iostream>
using namespace std;
int main()
{
    int a[5]={1,3,5,7,9};
    //step.0：建模 想成划分红蓝区域
    //step.1：建立两个指针 初始化为-1 和 n
    int l=-1,r=5;
    int m;
    //找到第一个大于等于4的元素
    //step.2：判断终止条件 即l和r相邻的情况
    while(l+1!=r)
    {
        m=(l+r)/2;//m向下取整
        //step.3：更新左右指针 保持左右性质不变
        if(a[m]<4)
        {
            l=m;//如果m在边界上 +1和-1很容易边界条件出错
        }
        else
        {
            r=m;
        }
    }
    //根据建模情况确定返回l还是r
    cout<<a[r];
}