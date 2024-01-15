//最大公约数
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	if(a%b==0)
	return b;
	return gcd(a%b,b);
}

int gcd(int a,int b)
{
    if(a<b) swap(a,b);
    while(b>0)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}