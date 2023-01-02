//冒泡排序
//数组a n个元素 下标从0到n-1
void bubblesort(int n,int a[]){
    for(int j=1;j<=n-1;j++){//j表示第几次排序
        for(int i=n-1;i>=j;i--){//i表示排序时比较的脚标
            if(a[i]<a[i-1]){//下标从0到n-1从小到大排列
                int temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
        }
    }
}