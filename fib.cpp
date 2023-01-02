#include <iostream>
using namespace std;

//step1:确定一个能结束的问题
int fib(int n)
{
    //step3:确定终止条件
    if(n==1||n==2)
    {
        return 1;
    }
    //step2:确定常规表达式
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n);
}