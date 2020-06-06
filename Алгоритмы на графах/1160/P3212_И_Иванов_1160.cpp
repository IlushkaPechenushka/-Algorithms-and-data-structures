#include<bits/stdc++.h>
#include<string>
#include<map>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

int tree_id[1005];
vector<pair<int, pair<int,int> > > g;
vector < pair<int,int> > ans;

int main()
{
	int n, m, mx = -1;
	scanf("%d %d", &n, &m);
		
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		g.pb(make_pair(c, make_pair(a, b)));			
	}

	sort(g.begin(), g.end());
	
	for(int i = 1; i <= n; i++)
		tree_id[i] = i;
		
	for (int i = 0; i < m; i++)
	{
		int a = g[i].s.f,  b = g[i].s.s,  len = g[i].f;
		
		if(tree_id[a] != tree_id[b])
		{
			
			mx = max(len, mx);
			ans.pb(make_pair(a, b));
			
			int old_id = tree_id[b],  new_id = tree_id[a];
			
			for(int j = 1; j <= n; j++)
				if(tree_id[j] == old_id)
					tree_id[j] = new_id;
		}
	}
	
	cout << mx << endl << ans.size() << endl;
	
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].f << " "<< ans[i].s << endl;
	
   	return 0;		
}

