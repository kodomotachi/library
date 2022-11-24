#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;

vector<vector<int>> graph(MAXN);
bool visited[MAXN];
int n;

void BFS(int u)
{
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int x : graph[v])
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int m;
	cin >> n >> m;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!visited[i])
		{
			++cnt; // count component
			BFS(i);
		}
	return cout << (cnt == 1 ? "YES" : "NO"), 0; // If graph has only 1 component, print "YES" otherwise, print "NO".
}