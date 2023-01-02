#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[110],b[110],c[110];
    cin>>a>>b;
    int x[110]={};
    int y[110]={};
    int z[110]={};
    for(int i=0;i<strlen(a);i++)
        x[strlen(a)-1-i]=a[i]-'0';
    for(int i=0;i<strlen(b);i++)
        y[strlen(b)-1-i]=b[i]-'0';
    int m=max(strlen(a),strlen(b));
    int w=0;//记录进位
    for(int i=0;i<=m;i++){
        z[i]=x[i]+y[i]+w;
        w=z[i]/10;
        z[i]=z[i]%10;
    }
    if (z[m] != 0) cout<<z[m];
    for(int i=m-1;i>=0;i--)
        cout<<z[i];
    return 0;
}
