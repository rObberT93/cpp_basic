// //快速幂 求后三位 把复杂度从o(n)变成了o(logn)
// int binarypower_last(int n,int m, int p)//n底数 m指数 mod p p=1000
// {
//     if(m==1) 
//     {
//       return n%p;
//     }
//     else if(m%2==1)//m不是2的倍数 即二进制下末尾位1
//     {
//       return ((binarypower_last(n,m>>1,p)%p)*(binarypower_last(n,m>>1,p)%p)*(n%1000))%p; 
//     }
//     else//m是2的倍数
//     {
//       return ((binarypower_last(n,m>>1,p)%p)*(binarypower_last(n,m>>1,p))%p)%p; 
//     }
// }
#include<iostream>
using namespace std;
//快速幂计算a的n次方
int bin_exp(int a,int n)
{
    int r=1;
    while(n!=0)
    {
        if(n&1==1)
        {
            r=r*a;
        }
        a*=a;
        n=n>>1;
    }
    return r;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<bin_exp(a,n);
    return 0;
}