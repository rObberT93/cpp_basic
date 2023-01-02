#include<iostream>
#include<algorithm>
using namespace std;

void quickSort(int left, int right, int* a)
{
	// 只包含一个元素 或者为空
	if(left>=right) return;
	int i = left, j = right;
	int base  = a[left];//这里哨兵选的是最左边的！值！
	while(i<j)
	{
		// 从右往左找到小于base的元素
		while(j>i && a[j] >= base)//这里的判断条件记得加！i<j！虽然只有i<j才能进while循环 但会在循环里越界
			j--;
		// 从左往右找到大于base的元素
		while(j>i && a[i] <= base)
			i++;
		swap(a[i],a[j]); //先把左右整体交换对了
	}
	swap(a[left], a[i]);//再把哨兵放到该放的位置上
	quickSort(left,i-1, a);
	quickSort(i+1,right,a);
}


int main()
{
    int n=5;
    int a[5]={2,1,5,2,3};
    //int tmp={0};
    quickSort(0,4,a);
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
}