#include "iostream"
#include "cmath"
using namespace std;
double sin(double x)
{
    double n=1;
    double t=x;
    double s=x;
    while (fabs(t)>=1e-5)//求浮点数绝对值
    {
        n+=2;
        t=t*(-x*x)/(n-1)/n;
        s=s+t;
    }
    return s;
}
int main(int argc, char* argv[])
{
    double x;
    cin>>x;
    double res=sin(x);
    cout<<res;
    return 0;
}