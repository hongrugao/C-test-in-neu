//Dijstra算法的实现   2.5

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 20;
const int INF = 1e7;
int n;   //城市个数
int m;   //路线条数
int map[N][N];
int dist[N];   //最短路径长度
int p[N];   //先驱节点
bool flag[N];

void init()
{
	int u, v ,w;
	cout << "请输入城市个数:" << endl;
	cin >> n;
	cout << "请输入城市间路线条数:" << endl;
	cin >> m;
	//cout << "请输入城市间路线以及权重:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = INF;
		}
		flag[i] = 0;
		p[i] = -1;
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		cout << "请输入城市间路线以及权重:" << endl;
		cin >> u >> v >> w;
		map[u][v] = min(w, map[u][v]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
}
void Dijkstra(int u)
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = map[u][i];
		if (dist[i] == INF)
		{
			p[i] = -1;
		}
		else
		{
			p[i] = u;
		}
	}
	flag[u] = 1;
	int t = u;
	int iter = n;
	while(1)
	{
		if (iter == 1)
		{
			break;
		}
		int minVertex=INF;
		for (int i = 0; i < n; i++)
		{
			if (flag[i] == 0 && dist[i] != INF)
			{
				if (dist[i] < minVertex)
				{
					minVertex = dist[i];
					t = i;
				}
			}
		}
		//cout << t << endl;
		if (t == u) return;
		flag[t] = 1;
		for (int i = 0; i < n; i++)
		{
			if (flag[i]==0&&dist[i] > dist[t] + map[t][i])
			{
				dist[i] = dist[t] + map[t][i];
				p[i] = t;
			}
		}
		iter--;
	}
}
int main()
{
	init();
	int u;
	cout << "输入小明的起始点" << endl;
	cin >> u;
	Dijkstra(u);
	for (int i = 0; i < n; i++)
	{
		cout << "从"<<u<<"到"<<i<<"最短距离是"<<dist[i] << endl;
	}
}
