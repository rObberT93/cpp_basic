# STL
### setw() 函数  

```setw(n)```  
n 表示宽度，用数字表示。

setw() 函数只对紧接着的输出产生作用。当后面紧跟着的输出字段长度小于 n 的时候，在该字段前面用空格补齐，当输出字段长度大于 n 时，全部整体输出。  

> ex: input 
```c++
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << setfill('*') << setw(14) << "runoob" <<endl;
    return 0;
}
```
output
```
********runoob
```
---
## vector
>example.1:
```c++
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
 
int main()
{
    vector<int>obj;//创建一个向量存储容器 int
    for(int i=0;i<10;i++) // push_back(elem)在数组最后添加数据 
    {
        obj.push_back(i);
        cout<<obj[i]<<",";    
    }//输出0,1,2,3,4,5,6,7,8,9,

    for(int i=0;i<1;i++)//去掉数组最后一个数据 
    {
        obj.pop_back();
    }
 
    cout<<"\n";
    cout<<obj.size()<<endl;//输出9
    for(int i=0;i<obj.size();i++)//size()容器中实际数据个数 
    {
        cout<<obj[i]<<",";
    }//输出0,1,2,3,4,5,6,7,8,

    return 0;
}
```
>example.2:
```c++
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    //顺序访问
    vector<int>obj;
    for(int i=0;i<10;i++) obj.push_back(i);  

    //方法一
    cout<<"直接利用数组："; 
    for(int i=0;i<10;i++) cout<<obj[i]<<" ";
    cout<<endl; 

    //方法二，使用迭代器将容器中数据输出 
    cout<<"利用迭代器：" ;
    vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
    for(it=obj.begin();it!=obj.end();it++) cout<<*it<<" ";
    return 0;
}
```
>任意输入
```c++
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a;
    int n,tmp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
```
>二维数组
```c++
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int N=5, M=6; 
    vector<vector<int> > obj(N); //定义二维动态数组大小5行 
    for(int i =0; i< obj.size(); i++)//动态二维数组为5行6列，值全为0 
    { 
        obj[i].resize(M); 
    } 
 
    for(int i=0; i< obj.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<obj[i].size();j++)
        {
            cout<<obj[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
```
```c++
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int N=5, M=6; 
    vector< vector<int> > obj(N, vector<int>(M)); //定义二维动态数组5行6列 
 
    for(int i=0; i< obj.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<obj[i].size();j++)
        {
            cout<<obj[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
```
>输入
```c++
#include<iostream>
#include<vector>
using namespace std;

int main() {
	string str;
	int i;
	vector<string> S;
	vector<int> nums;
 
	while (cin >> i) {
		nums.push_back(i);
		if (cin.get() == '\n') break;
	}
	
	while (getline(cin, str))
	{
		S.push_back(str);
		if (str[str.size()] == '\0') break;
	}
 
	for (auto e : nums) cout << e << " ";
	cout << endl;
	for (auto e : str) cout << e ;
    
	return 0;
}
```


>total_basic:
```c++
vertor<int>obj;

obj.push_back(elem);//在数组最后添加数据


obj.pop_back();//去掉数组最后一个数据 

obj.size();//数组大小

obj.clear();//清除容器中所有数据  

#include<algorithm>
sort( obj.begin() , obj.end() );//从小到大

reverse( obj.begin() , obj.end() );//从大到小
```
## algorithm
>next_permutation(begin,end);
```c++
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
```
## 链表
> 基础链表
```c++
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
     //输出链表
    struct node *t=head;
    while(t!=NULL){
        cout<<t->data;
        t=t->next;
    }
    return 0;
}
```
```c++
#include<iostream>
using namespace std;
//1.构建结点
typedef struct node//给struct类型的node改名字
{
    string element;
    struct node *next;//当前这个结点的类型 存放地址
}stu;//stu是struct node的别名，不然定义一个新的结构体都要写struct node两个词
//创建一个长度为n的链表
stu *createlist(int n)//声明一个指向结构体stu的指针
{
    //2.生成头结点
    stu *head =new stu;//第一个结点
    stu *pre=head;//想让pre成为指向下一个结点的指针
    //3.生成普通结点
    for(int i=0;i<n;++i){
        stu *p=new stu;//p是一个指向stu类型的结构体的指针
        //4.输入数据
        cout<<"请输入第"<<i+1<<"个element"<<endl;
        cin>>p->element;//通过指针来访问数据(*p).element或者p->element

        pre->next=p;//让pre的next指向p
        pre=p;//把pre完全变成p
        p->next=NULL;//释放next指向的地址
    }
    return head;
}

void printlist(stu *head)//把建立的链表的首地址（head）传进去
{
    stu *p=head->next;
    while(p!=NULL)
    {
        cout<<p->element<<endl;
        p=p->next;
    }
}

int main()
{
    int n=3;
    stu *head=createlist(n);
    printlist(head);
    system("pause");
    return 0;   
}
```
```c++
/*
循环单链表(带头结点)
*/

#include <iostream>
#include <string>
using namespace std;

struct LNode {
    int data;    // 数据域
    LNode *next; // 指针域
};

typedef struct LNode LNode;     // LNode是一个循环单链表的结点
typedef LNode *LinkList; // LinkList是一个循环单链表

// 初始化循环单链表
void InitList(LinkList &L) {
    L = new LNode;
    L->next = L;
}

// 判断循环单链表是否为空
bool Empty(LinkList &L) {
    if (L->next == L) {
        return true;
    } else {
        return false;
    }
}

// 获取循环单链表长度
int GetLength(LinkList &L) {
    LNode *p = L->next;
    int length = 0;
    while (p != L) {
        p = p->next;
        length++;
    }
    return length;
}

// 头插法建立循环单链表
LinkList List_HeadInsert(LinkList &L) {
    int e;
    cin >> e;
    while (e != 9999) {
        LNode *s = new LNode;
        s->data = e;
        s->next = L->next;
        L->next = s;
        cin >> e;
    }
    return L;
}

// 尾插法建立循环单链表
LinkList List_TailInsert(LinkList &L) {
    LNode *r = L; // r为尾指针
    int e;
    cin >> e;
    while (e != 9999) {
        LNode *s = new LNode;
        s->next = r->next;
        s->data = e;
        r->next = s;
        r = s; // 将r置为新的尾指针
        cin >> e;
    }
    r->next = L; // 尾指针的next置为L
    return L;
}

// 按位查找：查找第i个结点
LNode *GetElem(LinkList &L, int i) {
    if (i < 0) {
        return NULL; // i值不合法
    }
    LNode *p = L;
    int j = 0;
    while (p->next != L && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找：查找数据域为e的结点
LNode *GetLNode(LinkList &L, int e) {
    LNode *p = L->next;
    while (p != L && p->data != e) {
        p = p->next;
    }
    return p;
}

// 查找指定结点的前一个结点
LNode *GetPriorNode(LinkList &L, LNode *p) {
    LNode *s = L;
    while (s->next != p) {
        s = s->next;
    }
    return s;
}

// 查找最后一个结点
LNode *GetLastNode(LinkList &L) {
    LNode *p = L->next;
    while (p->next != L) {
        p = p->next;
    }
    return p;
}

// 前插操作：在p结点之前插入数据e
bool InsertPriorNode(LNode *p, int e) {
    LNode *s = new LNode;
    s->next = p->next;
    s->data = p->data; // 数据后移，模拟结点后移
    p->next = s;
    p->data = e; // 将前结点置为新插入的结点
    return true;
}

// 后插操作：在p结点之后插入数据e
bool InsertNextNode(LNode *p, int e) {
    LNode *q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

// 按位序插入
bool InserstList(LinkList &L, int i, int e) {
    if (i < 1)
    { // i值不合法
        return false;
    }
    // LNode *p = GetElem(L, i - 1); // 遍历查找i-1个结点
    // InsertNextNode(p, 5244);      // 使用后插法
    // 使用前插法，达到同样效果
    LNode *p = GetElem(L, i);
    InsertPriorNode(p, 5244);

    return true;
}

// 删除指定结点
bool DeleteNode(LinkList &L, LNode *p)
{
    if (p == L)
    {
        return false;
    }
    if (p->next == L)
    {                // 要删除最后一个结点
        LNode *s = GetPriorNode(L, p); // s为p的前驱结点
        s->next = p->next;
        delete p;
    }
    else
    {
        LNode *s = new LNode;
        s = p->next;       // 指向被删除结点的后继节点
        p->data = s->data; // 数据前移，模拟结点前移
        p->next = s->next; // 断开与被删除结点的联系
        delete s;
    }
    return true;
}

// 删除p结点的后继结点
bool DeleteNextLNode(LinkList &L, LNode *p) 
{
    if (p == NULL || p->next == L) 
    {
        return false;
    }
    LNode *s = new LNode;
    s = p->next;
    p->next = s->next;
    delete s;
    return true;
}

// 按位序删除
bool ListDelte(LinkList &L, int i, int &e) 
{
    if (i < 1) 
    {
        return false;
    }
    /*  // 按结点删除，实现同样效果
    LNode *p = GetElem(L, i); // 被删除结点
    e = p->data;
    DeleteNode(L, p);
    */
    LNode *p = GetElem(L, i - 1);
    e = p->next->data;
    DeleteNextLNode(L, p);
    return true;
}

// 遍历循环单链表
void TraverseList(LinkList &L) 
{
    if (L->next == L) 
    {
        return;
    }
    LNode *p = L->next; // 指向头指针
    while (p != L) 
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() 
{
    LinkList L;
    InitList(L);
    cout << Empty(L) << endl;

    // List_HeadInsert(L); // 头插法
    List_TailInsert(L); // 尾插法
    TraverseList(L);

    InserstList(L, 3, 5244);
    TraverseList(L);
    cout << "长度：" << GetLength << endl;

    int e = -1;
    ListDelte(L, 6, e);
    cout << "被删除的值：" << e << endl;
    TraverseList(L);
    cout << GetElem(L, 5)->next->next->data << endl; // 验证循环链表的效果
}
```
## 图
```c++
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

//邻接矩阵
namespace Matrix
{
	//Direction表示是否为有向图，V表示中节点的属性，W表示边的权值
	template<class V, class W,bool Direction=false>
	class Graph
	{
	public:
		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(vertexs[i]);
				_VIndexMap[vertexs[i]] = i;
			}

			_matrix.resize(n);
			for (auto& e : _matrix)
			{
				e.resize(n,W());
			}
		}
		//获取顶点的下标
		size_t GetVertexIndex(const V& v)
		{
			auto ret = _VIndexMap.find(v);
			if (ret != _VIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("不存在的顶点");
				return -1;
			}
		}
		void AddEdge(const V& src, const V& dst,const W&w)
		{
			size_t srcindex = GetVertexIndex(src);
			size_t dstindex = GetVertexIndex(dst);
			_matrix[srcindex][dstindex] = w;
			if (Direction == false)
			{
				//无向图
				_matrix[dstindex][srcindex] = w;

			}
		}
		//广度优先搜索
		void BFS(const V& src)
		{
			//找到其下标
			size_t srcindex = GetVertexIndex(src);
			//visited表示没有被访问过的顶点
			vector<bool>visited;
			visited.resize(_vertexs.size(), false);
			//使用队列完成广度遍历
			queue<int>q;
			q.push(srcindex);
			visited[srcindex] = true;
			size_t d = 1;

			//dSize保证队列中的数据走完
			size_t dSize = 1;
			while (!q.empty())
			{
				printf("%s的%d度好友:", src.c_str(), d);
				while (dSize--)
				{
					size_t front = q.front();
					q.pop();
					for (size_t i = 0; i < _vertexs.size(); ++i)
					{
						if (visited[i] == false && _matrix[front][i] != W())
						{
							printf("[%d:%s]", i, _vertexs[i].c_str());
							q.push(i);
							visited[i] = true;
						}
					}
				}
				cout << endl;
				dSize = q.size();
				++d;
			}
		}
		//深度优先搜索
		void _DFS(size_t srcIndex, vector<bool>& visited)
		{
			printf("[%d:%s]", srcIndex, _vertexs[srcIndex].c_str());
			visited[srcIndex] = true;
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (visited[i] == false&&_matrix[srcIndex][i]!=W())
				{
					_DFS(i, visited);
				}
			}
		}
		void DFS(const V& src)
		{
			//找到其下标
			size_t srcindex = GetVertexIndex(src);
			//visited表示没有被访问过的顶点
			vector<bool>visited;
			visited.resize(_vertexs.size(), false);
			_DFS(srcindex, visited);
		}
	private:
		map<V, int> _VIndexMap;//顶点和下标的映射关系
		vector<V> _vertexs;//顶点集合
		vector<vector<W>> _matrix;//存储边集合的矩阵
	};

	void TestGraph()
	{
		string a[] = { "张三","李四","王五","赵六","周七"};
		Graph<string, int>g1(a,sizeof(a)/sizeof(a[0]));
		g1.AddEdge("张三","李四",100);
		g1.AddEdge("张三","王五",200);
		g1.AddEdge("王五","赵六",10);
		g1.AddEdge("李四","周七",50);
		g1.BFS("张三");
		g1.DFS("张三");
	}

}

//邻接表
namespace LinkTable
{
	template<class W>
	struct LinkEdge
	{
		int _srcIndex;
		int _dstIndex;
		W _w;
		LinkEdge<W>* _next;
		LinkEdge(const W& w)
			:_srcIndex(-1)
			, _dstIndex(-1)
			, _w(w)
			, _next(nullptr)
		{}
	};
	//Direction表示是否为有向图，V表示中节点的属性，W表示边的权值
	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef LinkEdge<W> Edge;
	public:
		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(vertexs[i]);
				_VIndexMap[vertexs[i]] = i;
			}
			_linkTable.resize(n,nullptr);
		}
		size_t GetVertexIndex(const V& v)
		{
			auto ret = _VIndexMap.find(v);
			if (ret != _VIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("不存在的顶点");
				return -1;
			}
		}
		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srcindex = GetVertexIndex(src);
			size_t dstindex = GetVertexIndex(dst);

			Edge* sd_edge = new Edge(w);
			sd_edge->_srcIndex = srcindex;
			sd_edge->_dstIndex = dstindex;
			sd_edge->_next = _linkTable[srcindex];
			_linkTable[srcindex]=sd_edge;

			if (Direction == false)
			{
				//有向图的起点和终点相互颠倒
				Edge* ds_edge = new Edge(w);
				ds_edge->_srcIndex = dstindex;
				ds_edge->_dstIndex = srcindex;
				ds_edge->_next = _linkTable[dstindex];
				_linkTable[dstindex] = ds_edge;
			}
		}

		void BFS(const V& src) 
		{
			//找到其下标
			size_t srcindex = GetVertexIndex(src);
			//visited表示没有被访问过的顶点
			vector<bool>visited;
			visited.resize(_vertexs.size(), false);
			//使用队列完成广度遍历
			queue<int>q;
			q.push(srcindex);
			//visited[srcindex] = true;
			size_t d = 0;
			//dSize保证队列中的数据走完
			size_t dSize = 1;
			while (!q.empty())
			{
				printf("%s的%d度好友:", src.c_str(), d);
				while (dSize--)
				{
					size_t index = q.front();
					q.pop();
					if (!visited[index])
					{
						cout << _vertexs[index] << " ";
						visited[index] = true;
						Edge* pCur = _linkTable[index];
						while (pCur)
						{
							q.push(pCur->_dstIndex);
							pCur = pCur->_next;
						}
					}
				}
				cout << endl;
				dSize = q.size();
				++d;
			}
		}
		void _DFS(int index, vector<bool>& visited) {
			if (!visited[index])
			{
				cout << _vertexs[index] << " ";
				visited[index] = true;
				Edge* pCur = _linkTable[index];
				while (pCur)
				{
					_DFS(pCur->_dstIndex, visited);
					pCur = pCur->_next;
				}
			}
		}
		void DFS(const V& v) {
			vector<bool> visited(_vertexs.size(), false);
			_DFS(GetVertexIndex(v), visited);
			for (size_t index = 0; index < _vertexs.size(); ++index)
			{
				_DFS(index, visited);
			}
			cout << endl;
		}
		//非递归深度优先遍历
		void DFS_non_recursive(const V& v) {
			size_t index = GetVertexIndex(v);
			stack<size_t>st;
			set<size_t>set;
			st.push(index);
			set.insert(index);
			cout << _vertexs[index] << " ";
			while (!st.empty())
			{
				Edge* cur = _linkTable[st.top()];
				st.pop();
				while (cur)
				{
					if (!set.count(cur->_dstIndex))
					{
						st.push(cur->_srcIndex);
						st.push(cur->_dstIndex);
						set.insert(cur->_dstIndex);
						cout << _vertexs[cur->_dstIndex] << " ";
						cur = cur->_next;
						break;
					}
					cur = cur->_next;
				}
			}
		}
		
	private:
		map<V, int> _VIndexMap;//顶点和下标的映射关系
		vector<V> _vertexs;//顶点集合
		vector<Edge*> _linkTable;//边的集合的邻接表
	};

	void TestGraph()
	{
		string a[] = { "张三","李四","王五","赵六","周七" };
		Graph<string, int>g1(a, sizeof(a) / sizeof(a[0]));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 10);
		g1.AddEdge("李四", "周七", 50);
		g1.BFS("张三");
		g1.DFS("张三");
	}
}
```
### dijkstra算法
```c++
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int edges[550][550];  // 存放所有的边，例如 edges[i][j] 代表从i到j的距离
int dist[550];  // 记录当前所有点到起点的距离
int visited[550];  // 标记当前的点是否被踢出

int dijkstra(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {  // 每次循环都会剔除掉1个点，因此需要for循环遍历n次。
        int index = -1;  // index代表当前未被访问的距离原点最近的点
        dist[1] = 0; // 原点到原点的距离为0，这个很重要，否则下面for循环所有的dist都是0x3f3f3f3f,无法找出index。
        for (int j = 1; j <= n; j++) { // find the index of min distance 
            if (!visited[j] && (index == -1 || dist[j] < dist[index]))
            { // 当前的点没有被踢出，并且当前点的距离比index点的距离小，则更新index。index == -1表示还未开始找到dist中最小值，则把dist[1]加入。
                index = j;
            }
        }

        visited[index] = 1;  //找到当前距离原点最小值的点，则把点进行标记踢出。
        for (int j = 1; j <= n; j++)
        {
            if (dist[index] + edges[index][j] < dist[j])
            {
                dist[j] = dist[index] + edges[index][j];
            }//index点更新与它相连的所有点。
        }
    }

    if (dist[n] == 0x3f3f3f3f)
    {  //如果没有到n点的路径，则返回-1
        return -1;
    }
    return dist[n];
}

int main()
{
    memset(edges, 0x3f, sizeof(edges));
    int n,m;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int start,end,d;
        scanf("%d %d %d", &start, &end, &d);
        edges[start][end] = edges[start][end] > d ? d: edges[start][end];  //因为题目输入中存在重边，所以，每次取最小值。
    }
    
    memset(dist, 0x3f, sizeof(dist));  // 初始化每个dist的值为0x3f3f3f3f， memset是按照字节来设置的，每个字节为0x3f, int四个字节，因此是 0x3f3f3f3f.
    memset(visited, 0, sizeof(visited)); // 初始化所有的点都没有被踢出。
    printf("%d\n", dijkstra(n,m));
    return 0;
}
```

# 头文件tuple
>基本用法
```c++
#include<iostream>
#include<tuple>
using namespace std;

tuple<int , string> find_max()
{
    return make_tuple(1,"haha");
}

int main()
{
    // tuple<int ,int > x(1,1);
    // cout<<get<0>(x) <<" "<<get<1>(x)<<endl;
    // get<0> (x)=100;
    // cout<<get<0>(x) <<" "<<get<1>(x)<<endl;
    int a;
    string b;
    tie(a, b) = find_max();
    printf("%d => %s\n", a, b);
    return 0;
}
```
>函数返回多个值  
```c++
//tuple里可以装各种类型的元素
#include<iostream>
#include<tuple>
using namespace std;

tuple<int ,int , int> sort(int a,int b,int c)
{
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(b,c);
    //return make_tuple(a,b,c);
    //或者
    return {a,b,c};
}
int main()
{
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    tie(a, b ,c) = sort(a,b,c);
    printf("%d%d%d", a, b, c);
    return 0;
}
```
---
``tuple``到底可以怎么用？便捷在哪？    

&nbsp;&nbsp;&nbsp;&nbsp;如果写成函数的形式，把形参传入到括号里，相当于操作这些形参对应的实参，对应成函数的形式就是``y=f(x1,x2,x3,x4,x5)`` 
只能输出一个y值,这样做本质的含义是几个参数共同作用得到一个输出值 ;  
但实际情况可能几个参数会造成一些东西打包改变，是这样的形式 : ``F[ y1, y2, y3 ] = f(x1,x2,x3,x4,x5)`` ;  
&nbsp;&nbsp;&nbsp;&nbsp;于是，要把函数的 **返回值** 类型写成 ``tuple < y1, y2 ,y3> ``就可以输出y1, y2, y3的值了  

```c++
#include<iostream>
#include<tuple>
using namespace std;

tuple<int> find_max(int a,int b,int c)
{
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b<c) swap(b,c);
    return {a};
}
int main()
{
    int a;
    int b;
    int c;
    cin>>a>>b>>c;
    //auto语句 不用定义tuple里的东西了，自动匹配
    auto[x] = find_max(a,b,c);
    printf("%d",x);
    return 0;
}
```
>应用
```c++
//矩阵乘法
#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

tuple<vector<float>, int, int> matrixTimes(vector<float> A, vector<float> B, int nA, int mA, int nB, int mB)
{
    int nC=nA,mC=mB;
    vector<float> C(nC * mC, 0);
    //compute C_ij
    //A nA * mA
    //B nB * mB
    //C nA * mB
    //C_ij=\sum_j{A_ik * B_kj}
    //A_ik=A[i*mA+k]
    //B_kj=B[k*mB+j]
    //C_ij=C[i*mC+j]
    for(int i=0 ; i<nC ; i++)
    {
        for(int j=0 ; j<mC ;j++)
        {
            float sum=0.0f;//reset sum
            for(int k=0 ; k<mA ; k++)
            {
                sum+=A[i * mA + k] * B[k * mB + j];
            }
            C[i * mC + j]=sum;
        }
    }
    return {C, nC, mC};
}

int main()
{
    vector <float> A={1,2,1,2};
    vector <float> B={2,1,1,1};
    auto[C,nC,mC]=matrixTimes(A,B,2,2,2,2);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<C[i*2+j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```
