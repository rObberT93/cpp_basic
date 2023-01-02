# main()主函数
```c++
#include<iostream>
using namespace std;
int main(int argc,char*argv[]){
    for(int i=0;i<argc;i++){
        cout<<argv[i]<<endl;
    }
    return 0;
}
```
# 输出
## printf()
```c++
printf（"格式化字符串",输出列表）；
格式化字符串包含：
（1）字符串常量
（2）格式化控制字符串，与各输出项在数量和类型上一一对应，以%开头的字符串
（3）转义字符
```
      %a(%A) |  浮点数、十六进制数字和p-(P-)记数法(C99)    
      %c     |  字符    
      %d     |  有符号十进制整数  
      %f     |  浮点数(包括float和double) 
      %e(%E) |  浮点数指数输出[e-(E-)记数法]   
      %g(%G) |  浮点数不显无意义的零"0"  
      %i     |  有符号十进制整数(与%d相同)  
      %u     |  无符号十进制整数   
      %o     |  八进制整数   
      %x(%X) |  十六进制整数   
      %p     |  指针   
      %s     |  字符串  
      %%     |  "%"
```c++
int a = 4;
printf("%03d",a);
//输出：004 不足3位补全前置0
```
## 操纵符(manipulator)
包含于iomanip头文件  
e.g.
``setw`` 和``width``为每个项指定输出宽度，仅影响紧随其后的输出项！  
``dec``十进制``oct``八进制``hex``十六进制

---
### width 和 setw 的用法
```c++
//#include<iostream>
#include<fstream>
//using namespace std;

int main()
{
    int values[]={1,2,3,4};
    std::ofstream txtout("file.txt");
    for(int i=0;i<4;i++)
    {
        txtout.width(10);
        txtout<<values[i]<<std::endl;
    }
    txtout.close();
    return 0;
}
```
使用setw操纵符指定宽度
```c++
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    int values[]={1,2,3,4};
    string names[]={"a","b","c","d"};
    ofstream txtout;
    textout.open("text.txt")
    for(int i=0;i<4;i++)
        txtout<<setw(6)<<names[i]<<setw(10)<<values[i]<<endl;
    txtout.close();
    return 0;
}
```

### setiosflags操纵符

setiosflags定义在头文件iomanip中，不同于width和setw，setiosflags的影响是持久的，直到用resetiosflags
>setiosflags的参数（流的格式标识）

``ios_base::skipws``在输出中跳过空白  
``ios_base::left``左对齐值，用填充字符填充右边  
``ios_base::right``右对齐，用填充字符填充右边  
``ios_base::internal``在规定的宽度内，指定前缀符号之后，数值之前，插入指定的填充字符  
``ios_base::dec``十进制形式格式化数值  
``ios_base::oct``八进制形式格式化数值  
``ios_base::hex``十六进制形式格式化数值  
``ios_base::showbase``插入前缀符号以表明整数的数值  
``ios_base::showpoint``对浮点数值显示小数点和尾部的0  
``ios_base::uppercase``对于十六进制数值显示大学字母A到F，对于科学格式显示大写字母E  
``ios_base::showpos``对于非负数显示正号  
``ios_base::scientific``以科学格式显示浮点数值  
``ios_base::fixed``以定点格式显示浮点数值，没有指数部分  
``ios_base::unitbuf``每次插入之后转储并清楚缓存区内容
``setprecision(n)``保留n位小数  
    cout<<fixed<<setprecision(n)<<result;

```c++
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    float values[]={123.128976123,21.00,35678.12,412351.453};
    string names[]={"a","b","c","d"};
    for(int i=0;i<4;i++)
    {
        cout<<setiosflags(ios_base::left)<<names[i]<<resetiosflags(ios_base::left)<<setw(25)
        <<setiosflags(ios_base::showpos|ios_base::right)<<setprecision(10)<<values[i]<<endl;
        //浮点数输出默认精度的默认值是6 例如3466.98
        //用setprecision改变精度
        //如果不指定fixed或scientific 精度表示有效数字位数
        //如果设置了ios_base::fixed或ios_scientific 精度值表示小数点之后的位数
        //scientific 输出
        // a        +1.2312897491e+02
        // b        +2.1000000000e+01
        // c        +3.5678121094e+04
        // d        +4.1235143750e+05
        //fixed 输出
        // a          +123.1289749146
        // b           +21.0000000000
        // c        +35678.1210937500
        // d       +412351.4375000000
        //不用scientific或fixed
        //a             +123.1289749
        // b                      +21
        // c             +35678.12109
        // d             +412351.4375
    }
    return 0;
}
```

---
# 数据类型
unsigned 只能表示正值  
一个字节8个bit char一字节；int四字节；float四字节；double八字节   
double精度更高

---
# 运算符
> 位运算符  
所有数值在内存中都是以二进制形式存放的，只有0和1，位运算可以分离出对应位。  

## ``>>``右移
> 右移一位 —— 8>>3=1 (即：00001000>>3=00000001)    
右移一位相当于除二
## ``&``按位与
> 与0 被屏蔽 ；与1 被保留（维持原状）  

## `` i++和++i``
1.a=i++，先把i的值赋予a，然后再执行i=i+1；  
当i初始等于3时，执行a=i++，最终结果a=3，i=4.  
2.a=++i，这个的意思是先执行i=i+1，然后再把i的值赋予a；  
当i初始等于3时，执行a=++i，最终结果a=4，i=4.

___

# 随机数

头文件
```c++
#include<cstdlib> 
``` 
``rand()``产生的随机数范围是0-65536  
如果产生0-99范围内的随机数 ``%100``
___

# 字符串和字符数组
头文件
```c++
#include<cstring>;
```
>复制str2数组内容拼接到str1后面 , 去掉str1原本带的``\0``
```c++
strcat(str1,str2);
```
>把str2的内容复制到str1里，带着str2的``\0``复制，str1里的东西就被覆盖了
```c++
strcpy(str1,str2);
```
>把str2的前3（任意）位复制拼接到str1后面，去掉str1的``\0``。
```c++
strncat(str1,str2，3);
```
>复制str2的前3位，取代str1的前3位，不带``\0``,可以正常输出str1后面的位
```c++
strncpy(str1,str2,3);
```
>比较str1和str2的大小，相等，返回0 ; str1 > str2，返回1 ; str1 < str2, 返回-1。
```c++
strcmp(str1,str2);
```
>比较str1和str2的前n位。
```c++
strncmp(str1,str2);
```
>查找字符串，若str2在str1中出现，则返回str2在str1中首次出现的地址；若未出现，返回NULL
```c++
char str1[20]="12345";
char str2[20]="3"
char *p=strstr(str1,str2);
printf("%s\n",p);//输出345
```
>大小写 string to lower & string to upper
```c++
char str1[20]="ABC"
strlwr(str1);
printf("%s\n",str1)
```
```c++
char str2[20]="abc"
strupr(str2);
printf("%s\n",str2)
```

## string类转换为char字符串
```c++
char c[数组大小]；//不能写成char *c 因为string的str会被析构
string s="一个字符串";
strcpy(c,s.c_str());//把string拷贝到char类型的字符数组c中，然后对拷贝的数据进行操作
```
```c++
/*
c_str() 这个函数转换后返回的是一个临时指针，不能对其进行操作（临时的）
因为这个数据是临时的，所以当有一个改变这些数据的成员函数被调用后，该数据就会改变失效
*/
int main() {
	const char *ptr;
	string s = "12345";
    ptr = s.c_str();
    cout << "s改变前ptr为:" << ptr << endl;//会输出12345
    s = "66666";
    cout << "s改变后ptr为:" << ptr << endl;//会输出66666
    return 0;
}
```
```c++
int main()
{
    string str="abcdef";
    char c[7];
    strcpy(c,str.c_str());//拷贝到内存中去
    cout<<str<<" "<<strlen(c)<<endl;//输出6
    cout<<sizeof(c)<<endl;//输出7 多一位\0
}
```

```c++
/*
c_str() 以 char* 形式传回 string 内含字符串   
如果一个函数要求char*参数，可以使用c_str()方法：
*/
string s = "Hello World!";
printf("%s", s.c_str()); //输出 "Hello World!"
```

## string类型可以当成字符数组使用
```c++
int main()
{
    string a="abcdef";
    cout<<a.length()<<endl;
    for(int i=0;i<a.length();i++) cout<<a[i]<<endl;
}
```

# 指针
>指针变量的类型 变量名 指针的内容  

显示指针值的时候，可以通过``printf("%#p",&a)``的#显示16进制标识
```c++
int a=0;
int *p=NULL,*q=NULL;
//*用来指定某个变量是指针
//符号化常量NULL在头文件<iostream>中定义
//整数0是c++中唯一一个允许赋给指针类型变量的整数值，因为指针变量的数据类型是内存的地址，而不是任何整数。
//值为NULL的指针不指向任何变量，这样初始化可以防止其指向任何位置的内存区域。
P=&a;//&是取地址运算符
cout<<p<<endl;
cout<<*p<<endl;
```
```c++
#include<iostream>
using namespace std;
int main()
{
    int a=0;
    int *p=NULL;
    p=&a;//取a的地址
    cout<<p<<endl;//p是一个指针 里面放的是a的地址 output:0x6fd51ff89c
    cout<<*p<<endl;//使用一元运算符 * 来返回位于操作数所指定地址的变量的值
    return 0;
}
```

# 语言 
## 条件运算符
>Exp1？Exp2 ：Exp3；  

如果Exp1为**真** 表达式取Exp2的值   
如果Exp1为**假** 表达式取Exp3的值

## 循环控制语句
>break  

1. 跳出这一层循环（嵌套循环跳出内层进入外层）
2. 终止 switch 语句中的一个 case。

>continue

有点像 break 语句,但continue 会跳过当前循环中的代码，强迫开始下一次循环。
1. for 循环：执行条件测试和循环增量部分
2. while 和 do...while 循环：回到条件测试上。

# 数组
## 数组赋初值
>memset（首地址，数值，数组大小）  
头文件 cstring

是按照**字节**对内存块进行初始化，只能将**int数组**初始化为**0或1**,另外，由于是以字节为单位进行赋值，所以数组大小是指的内存空间，如：给int a[4]赋值，数组大小写4*4=16。    
```c++
memset(a,1,16);
memset(a,1,sizeof(a));
```
## 多维数组
``int a[3][4];``  
存储的时候行优先，先存一行的所有列。  
>初始化  

```int ar[][4]={1,2,3,4,5,6,7,8,9,10,11,12};```

## 将二维数组传递给函数   

方法一：
```c++
void arrayfunction(int a[][4],int row,int col)
{
    ……
}
```
## 数组&指针

## 动态数组
普通数组：  
```c++
int Array[3];//元素个数是常数
```  

或者写成
```c++
const int row=3,col=4;
int Array[row][col];
```  
___
>使用new和delete动态分配内存
```c++
#include <iostream>
using namespace std;
int main ()
{
   double* pvalue  = NULL; // 初始化为 null 的指针
   pvalue  = new double;   // 为变量请求内存
 
   *pvalue = 29494.99;     // 在分配的地址存储值
   cout << "Value of pvalue : " << *pvalue << endl;
 
   delete pvalue;         // 释放内存
   return 0;
}
```

>一维数组
```c++
// 动态分配,数组长度为 m
int *array=new int [m];

//释放内存
delete [] array;
```

> 二维数组
```c++
int **array;
// 假定数组第一维长度为 m， 第二维长度为 n
// 动态分配空间
array = new int *[m];
for( int i=0; i<m; i++ )
{
    array[i] = new int [n]  ;
}
//释放
for( int i=0; i<m; i++ )
{
    delete [] array[i];
}
delete [] array;
```
>三维数组
```c++
int ***array;
// 假定数组第一维为 m， 第二维为 n， 第三维为h
// 动态分配空间
array = new int **[m];
for( int i=0; i<m; i++ )
{
    array[i] = new int *[n];
    for( int j=0; j<n; j++ )
    {
        array[i][j] = new int [h];
    }
}
//释放
for( int i=0; i<m; i++ )
{
    for( int j=0; j<n; j++ )
    {
        delete[] array[i][j];
    }
    delete[] array[i];
}
delete[] array;
```
一个具体的例子
```c++
 1 #include<iostream>
 2 using namespace std;
 3 int main()
 4 {
 5    int n;   //输入数组长度
 6    cin>>n;
 7    int *p;  //声明一个指针
 8    p=new int[n]; /*创建了一个长度为n的动态数组，并且返回这个数组的首地址给p，p就指向了这个动态数组，可以通过指针p
 9                  来操作数组，因为创建的动态数组并没有名字，只返回了首地址给p，所以可以把p看作是这个动态数组的名字 */
10    for(int i=0;i<n;i++)
11        cin>>p[i];
12    for(int i=0;i<n;i++)
13        cout<<p[i]<<" ";
14    delete []p;  //释放这个一维的动态数组，而不是释放指针p。用完以后要记得释放掉
15    cout<<p;    //输出指针p的地址
16    return 0;
17 }
```
> 数组名和指针加减
```c++
```
> 一维数组当成二维数组使用
```c++
int (*)[size];
```
> 二维数组当成一维使用
```c++
```

___
类型 int double char string vector  
```c++
vector<int>Array(3);
Array[0]=7;
Array[1]=8;
Array[2]=9;
Array.push_back(10);
for(int i=0;i<Array.size();i++)
{
    cout<<Array[i]<<" ";
}
```
//输出7 8 9 10
```c++
vector<int>Array;
Array.push_back(7);
Array.push_back(8);
Array.push_back(9);
for(int i=0;i<Array.size();i++)
{
    cout<<Array[i]<<" ";
}
Array.push_back(10);
for(int i=0;i<Array.size();i++)
{
    cout<<Array[i]<<" ";
}
```
//输出7 8 9 10

## 迭代器
给指针++迭代这个数组  
两个特别的迭代器：  
>Array.begin()    

>Array.end()//不存在 指向不存在的元素 访问会出错
```c++
vector<int>::iterator it = Array.begin();
//或直接写auto it = Array.begin() auto可根据数组类型自动判断迭代器
//使用解引用运算符可以得到迭代器指向的元素的一个引用
cout<<"Array的第一个元素是"<<*it<<end;
it++;
cout<<"下一个元素是"<<*it<<end;
it--;
cout<<"我又回来了"<<*it<<end;
```
> 清空动态数组
``Array.clear() ``
> 基于范围的for循环
```c++
for(int item : Array)//冒号前是要迭代的临时变量 每次都会在后面这个数组拿一个元素按顺序复制给前面的临时变量
{
    cout<<item<<endl;
}
```
# 函数
### swap
> 如果想对传入函数的形参作改变 必须要取形参的地址  

方法：写一个``*`` 或者用表示引用的``&``符号
```c++
//case1
void myswap(int *x,int *y)
{
    int temp=y;
    y=x;
    x=temp;
}
```
```c++
//case2
void myswap(int &x,int &y)
{
    int temp=y;
    y=x;
    x=temp;
}
```
>利用位运算还有一种写法
```c++
void swap(int &a,int &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
```
> 指向函数的指针
```c++
#include<iostream>
using namespace std;
int max(int a,int b)
{
   if(a>=b) return a;
   else return b;
}

int min(int a ,int b)
{
   if(a>=b) return b;
   else return a;
}

int add(int a,int b)
{
   return a+b;
}

int fun(int a,int b,int(*p)(int,int))
{
   int result=(*p)(a,b);
   return result;
}//把函数地址作为参数传到另一个函数里

int main()
{
      int (*p)(int,int);
      int n;
      cin>>n;
      switch(n)
      {
         case 1:p=max;break;
         case 2:p=min;break;
         case 3:p=add;break;
         default:break;
      }
      int a,b;
      cin>>a>>b;
      cout<<fun(a,b,p);
      //多fun这一步的意义还没有搞清楚 用p(a,b)不是一样的效果吗？
}
```
```c++
//可能它想让我这么干？
#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int min(int a ,int b)
{
   if(a>=b) return b;
   else return a;
}

int add(int a,int b)
{
   return a+b;
}

void fun(int a,int b,int(*p)(int,int))
{
   int result=(*p)(a,b);
   cout<<result;
}

int main()
{
      int (*p)(int,int);
      int n;
      cin>>n;
      int a,b;
      cin>>a>>b;
      if(n==1) fun(a,b,max);
      if(n==2) fun(a,b,min);
      if(n==3) fun(a,b,add);
}
```
### typedef  : 给变量类型取别称

```c++
typedef int wealth;
wealth money1;
wealth money2;
wealth money3;
wealth money4;
//有很多变量的时候，用typedef现在他们都叫wealth
//如果想给无数个变量都修改变量类型，如从int改成long long，不用typedef需要把每一个变量名字前面都修改
//但现在只需要在第一行把int改成long long，后面变量类型就都变了。
```

# 链表
```c++
#include<iostream>
using namespace std;
//1.构建结点
struct a_list
{
    string element;
    a_list * next;
};
a_list *head=NULL;//2.把头指针设为全局变量
//链表需要终止条件 一种方法设置为长度为n的 另一种通过输入值是不是0判断要不要继续往下连

//mod1：创建一个长度为n的链表
node* createlist(int n)//一个返回node的函数指针
{
    a_list * p=NULL;//先定义好两个指向a_list的指针pq
    a_list * q=NULL;
    //3.生成普通结点
    for(int i=0;i<n;i++){
        p=new a_list;
        //4.输入数据
        cout<<"请输入第"<<i+1<<"个element"<<endl;
        cin>>p->element;
        // pre->next=p;
        // pre=p;
        // p->next=NULL;
        if(head==NULL)//如果头指针是空 说明现在列表中没有元素 要插入第一个结点
        {
            head=p;
            q=p;
        }
        else//把p插入到q的下一位
        {
            q->next=p;
            q=p;
        }
    }
    return head;
}

void printlist(a_list * head)
{
    a_list * p=head->next;//这样就可以不改变head了
    while(p!=NULL)
    {
        cout<<p->element<<endl;
        p=p->next;
    }
}

int main()
{
    int n=3;
    printlist(createlist());
    system("pause");
    return 0;
}
```

```c++
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
			head=p;
		else
			q->next=p;//把p插到q后面 让p始终在待插入的位置
		q=p;//让q始终指向p

		cout<<"please input the the number of the student"<<endl;
		cin>>position;
	}//一旦跳出循环说明有一个位置是0

	if(head!=NULL)//如果链表不空 至少有一个结点
		q->next=NULL;//没有下一个了 p不能再在下一个位置了 所以把p删掉 让q指向一个空结点
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
```

