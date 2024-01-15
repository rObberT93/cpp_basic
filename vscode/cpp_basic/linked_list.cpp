#include <iostream>
using namespace std;
struct node//一个链表的结点
{
    int data;//数据域
    struct node* next;//指针域
 };
int main()
{
    struct node *head,*p,*q;//三个指针
    head=p=q=NULL;
    int a;
    int n;//链表长度
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;//输入数据
        p=new struct node;//p指向创建出来的新结点
        p->data=a;
        if(head==NULL)//新建的是首结点
        {
            head=p;//头指针指向第一个有数据的结点
            q=p;//把p和q都指向这个结点
        }
        else//不是首结点
        {
            q->next=p;//q是当前所在的结点
            q=p;//
        }
    }
    if(q!=NULL)
    {
        q->next=NULL;
    }
    int x;//删除指定index的结点
    cin>>x;
    struct node *temp=head;
    struct node *tmp;
    for(int i=1;i<x;i++)
    {
        tmp=temp;
        temp=temp->next;
    }
    tmp->next=temp->next;
    delete temp;
     //输出链表
    struct node *t=head;
    while(t!=NULL)
    {
        cout<<t->data;
        t=t->next;
    }
    return 0;
}
