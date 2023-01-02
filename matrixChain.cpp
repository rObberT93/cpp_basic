//矩阵链乘法 Ai的大小是Pi-1*pi
#include<iostream>
using namespace std;
int p[100]={30,35,15,5,10,20,25};
int n=6;//矩阵数量
int m[100][100];//从第i个矩阵到第j个矩阵的最小代价
int s[100][100];//保存最优值m[i][j]的对应分割点
void matrix_chain()
{
    for(int i=1;i<=n;i++) m[i][i]=0;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void print_optimal_parens(int i,int j)
{
    if(i==j)
        cout<<'A'<<i;
    else{
        cout<<'(';
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        cout<<')';
    }
}
int main()
{
    matrix_chain();
    print_optimal_parens(1,6);
    cout<<endl;
    cout<<m[1][6];
    return 0;
}