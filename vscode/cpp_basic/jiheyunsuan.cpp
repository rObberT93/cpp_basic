//交集并集补集并升序排列
void bubblesort(int n,int inter[]){
    for(int j=1;j<=n-1;j++){
        for(int i=n-1;i>=j;i--){
            if(inter[i]<inter[i-1]){
                int temp=inter[i];
                inter[i]=inter[i-1];
                inter[i-1]=temp;
            }
        }
    }
}

int jiao(int n,int m,int a[],int b[],int s[])
{
    int tmp1=0;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            if(a[i]==b[j]){
                tmp1++;
                s[tmp1-1]=a[i];
                break;
            }
        }
    }
    bubblesort(tmp1,s);
    return tmp1;
}
int bingji(int n,int m,int a[],int b[],int bing[])
{
    int tmp2=n;
    bubblesort(n,a);
    bubblesort(m,b);
    for(int i=0;i<=n;i++){
        bing[i]=a[i];
    }
    for(int j=0;j<=m-1;j++){
        if(b[j]>a[n-1]){
            tmp2++;
            bing[tmp2-1]=b[j];
        }
    }
    return tmp2;
}

int buji(int n,int m,int a[],int b[],int bu[])
{   
    int bubu[1005]={0};
    int tmp3=0;
    bubblesort(n,a);
    bubblesort(m,b);
    for(int i=0;i<=n;i++){
        bubu[i]=1;
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            if(a[i]==b[j]){
                bubu[i]=0;
                break;
            }
        }
    }
    for(int i=0;i<=n-1;i++){
            if(bubu[i]==1){
                tmp3++;
                bu[tmp3-1]=a[i];
            }
        }
        return tmp3;
    }