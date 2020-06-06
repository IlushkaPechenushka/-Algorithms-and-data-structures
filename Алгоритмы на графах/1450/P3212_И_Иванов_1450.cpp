#include<bits/stdc++.h>
#include<string>
#include<map>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

const int INF = -1e9;
vector<int> dist (505, INF);
vector <vector<pair<int, int> > > g(124755);
set <pair<int, int> > q;

int main()
{
	int n, m, start, endd;
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
		
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		//cin >> a >> b >> c;
		
		g[a].pb(make_pair(b, c));
	}
	
	scanf("%d %d", &start, &endd);
 
	dist[start] = 0;
	q.insert(make_pair(dist[start], start));
	
	while (!q.empty()) 
	{
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for(int i = 0; i < g[v].size(); ++i) 
		{
			int to = g[v][i].f, len = g[v][i].s;
			
			if (dist[v] + len > dist[to]) {
				q.erase(make_pair(dist[to], to));
				dist[to] = dist[v] + len;
				
				q.insert(make_pair(dist[to], to));
			}
		}
	}
	
	if(dist[endd] > 0) printf("%d", dist[endd]);
	else printf("No solution");
	
	
   	return 0;		
}

