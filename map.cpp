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


