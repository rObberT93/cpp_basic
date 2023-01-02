#include <cmath>
#include <iostream>
//#include <cstdio>
//#include <cstdlib>
#include <cstring>
//#include <algorithm>
 
using namespace std;
 
char a[1001], b[1001];
int dp[1001][1001];//直接把各项结果保存下来用递推
int len1, len2;
 
void lcs(int i,int j)
{
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            // else if(dp[i-1][j] > dp[i][j-1])//分别把两个串的最末尾项纳入考虑
            //     dp[i][j] = dp[i-1][j];
            // else
            //     dp[i][j] = dp[i][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
void llcs()//输出
{
    int i, j, z = 0;
    char c[1001];
    memset(c, 0, sizeof(c));
    i = len1, j = len2;
    while(i!=0 && j!=0)//逐个比较 找到一个就可以
    {
        if(a[i-1] == b[j-1])
        {
            c[z++] = a[--i];
            j--;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else if(dp[i-1][j] >= dp[i][j-1])
            i--;
    }
    for(i=z-1; i>=0; i--)
        printf("%c", c[i]);
    printf("\n");
}

void lllcs()//子串拼接
{
    int i, j, z = 0, k = 0;
    i = len1, j = len2;
    char s[10000];
    while(dp[i][j])
    {
        if(a[i-1] == b[j-1])
        {
            s[k++]=a[--i];
            j--;
        }
        else if(dp[i][j-1] < dp[i-1][j])//选择最短的子列输出
            s[k++] = a[--i];
        else if(dp[i][j-1] >= dp[i-1][j])
            s[k++] = b[--j];
    }
    while(i != 0)
        s[k++] = a[--i];
    while(j!=0)
        s[k++] = b[--j];
    for(z=k-1; z>=0; z--)
        printf("%c", s[z]);
    printf("\n");
}
 
int main()
{
    while(~scanf(" %s",a))
    {
        scanf(" %s", b);
        memset(dp, 0, sizeof(dp));//初始化为全0
        len1 = strlen(a);
        len2 = strlen(b);
        lcs(len1, len2);
        printf("%d\n", dp[len1][len2]);
        llcs();//输出
        lllcs();
    }
    return 0;
}