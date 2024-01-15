#include <iostream>
//筛法求素数
using namespace std;
const int n=1000000;
bool isprime[n+1];
int main()
{
    for(int i=2;i<=n;i++)
        isprime[i]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<=n;j+=i)
                isprime[j]=0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
            cout<<i<<endl;
    }
    return 0;
}