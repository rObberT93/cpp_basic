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
        for (int j = 1; j <= n; j++)
        { // find the index of min distance 
            if (!visited[j] && (index == -1 || dist[j] < dist[index])) // 当前的点没有被踢出，并且当前点的距离比index点的距离小，则更新index。index == -1表示还未开始找到dist中最小值，则把dist[1]加入。
                index = j;
        }

        visited[index] = 1;  //找到当前距离原点最小值的点，则把点进行标记踢出。
        for (int j = 1; j <= n; j++) 
        {
            if (dist[index] + edges[index][j] < dist[j]) //index点更新与它相连的所有点。
                dist[j] = dist[index] + edges[index][j];
        }
    }

    if (dist[n] == 0x3f3f3f3f) //如果没有到n点的路径，则返回-1
        return -1;
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