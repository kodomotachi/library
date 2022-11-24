#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAXN = 1e5 + 3;
vector<vector<pair<int, int>>> a(1e5 + 3);
int n, dist[MAXN], par[MAXN];
bool visited[MAXN];

bool dijkstra(int s, int t)
{
	fill(dist, dist + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	visited[s] = true;
	q.push({0, s});
	par[s] = -1;
	dist[s] = 0;
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (u == t)
			return true;
		visited[u] = true;
		for (auto &pr : a[u])
		{
			int v = pr.first;
			int w = pr.second;
			if (!visited[v] && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
				par[v] = u;
			}
		}
	}
	return false;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a[x].push_back({y, w});
		a[y].push_back({x, w});
	}
	if (dijkstra(1, n)) // Check if 1 to n have path
	{
		vector<int> path;
		for (int v = n; v != -1; v = par[v])
			path.push_back(v); // Write out path
		for (int i = path.size() - 1; i >= 0; --i)
			cout << path[i] << " "; // Print them
	}
	else
		cout << "-1"; // Print "-1" if no path connect them
	return 0;
}