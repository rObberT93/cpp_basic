#include<iostream>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct date
{
    int y;
    int m;
    int d;
}now;

int isLeap(int year)
{
    if((year%4==0&&year%400!=0)||year%400==0)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    now.y=2022,now.m=12,now.d=14;
    while(n--)//循环n次
    {
        now.d++;
        if(now.d>month[now.m])
        {
            now.m++;
            if(now.m>12)
            {
                now.m=1;
                now.y++;
                if(isLeap(now.y))
                    month[2]=29;
                else
                    month[2]=28;
            }
            now.d=1;
        }
    }
    printf("%04d-%02d-%02d\n",now.y,now.m,now.d);
}