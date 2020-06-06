#include<bits/stdc++.h>
#include<string>
#include<map>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

vector<vector<int> > cntry(100);
bool status;
bool check[100];
int color[100];
int dist[100];
bool ans[100];

void checkLoop(int s, int cnt)
{
	check[s] = true;
	color[s] = 1;
	dist[s] = cnt;
	cnt++;
	
	if(dist[s] % 2 == 1) ans[s] = true;
	
	for(int i = 0; i < cntry[s].size(); i++)
	{
		int v = cntry[s][i];
		
		if(color[v] == 0)	
			checkLoop(cntry[s][i], cnt);
			
		if(color[v] == 1 && dist[s] - dist[v] != 1)
			if((cnt - dist[v]) % 2 == 1) status = true;	
	}	
	
	color[s] = 2;
}

int main()
{
	int n, k, color = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		do{
			cin >> k;
			
			if(k == 0) break;
				
			cntry[i].pb(k);
			cntry[k].pb(i);
	
		}while(true);
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < cntry[i].size(); j++)
			if(!check[i])
				checkLoop(i, 0);
	}
	
	if(status)
	{
		cout << -1;
		return 0;
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i];
		
	return 0;	
}
