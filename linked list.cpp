#include<iostream>
using namespace std;

struct a_list
{
	char name[20];
	int age;
	int pos;
	a_list* next;
};

a_list * head;

a_list * create()
{
	a_list *p=NULL;
	a_list *q=NULL;
	head=NULL;
	int position;
	cout<<"please input the number of the student"<<endl;
	cin>>position;//现根据position判断插入到哪个位置
	while(position!=0)
	{
		p=new a_list;
		p->pos=position;
		cout<<"please input the name of the student"<<endl;
		cin>>p->name;
		cout<<"please input the age of the student"<<endl;
		cin>>p->age;

		if(head==NULL)
		{
			head=p;
		}

		else
		{
			q->next=p;//把p插到q后面 让p始终在待插入的位置
		}
		q=p;//让q始终指向p

		cout<<"please input the the number of the student"<<endl;
		cin>>position;
	}//一旦跳出循环说明有一个位置是0

	if(head!=NULL)//如果链表不空 至少有一个结点
	{
		q->next=NULL;//没有下一个了 p不能再在下一个位置了 所以把p删掉 让q指向一个空结点
	}
	return head;
}	

void disaplay(a_list *head)//参数是头指针head
	{
		if(head==NULL)
		{
			cerr<<"find fault";
			exit (2);
		}
		cout<<"disaplay all students details"<<endl;
		while(head!=NULL)
		{
			cout<<head->name<<endl;
			cout<<head->age<<endl;
			head=head->next;
		}
	}
int main()
{
	disaplay(create());
	return 0;
	system ("pause");
}