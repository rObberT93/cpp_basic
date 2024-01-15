#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	char my_array[3]={'a','a','c'};
	sort(my_array,my_array+3);
	do{
		for(int i=0;i<3;i++) cout<<my_array[i];
		cout<<"\n";
	}while(next_permutation(my_array,my_array+3));
	return 0;
}