#include<bits/stdc++.h>
#include<string>
#include<map>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

//c - city, m - money, d - day, n - name, cnt - count;
map<string, ll> cm;
map<string, ll> nm;
map<string, string> nc;
map<string, int> ccnt;
map<ll, set<string>> mc;

map<ll, set<string>>::reverse_iterator it;
map<string, int> :: iterator it2;

int main()
{
	int n;
	ll money;
	string name, city;
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> name >> city >> money;
		nm[name] = money;
		nc[name] = city;
		
		if(cm.find(city) != cm.end())
		{
			mc[cm[city]].erase(city);
			
			if(mc[cm[city]].size() == 0)
				mc.erase(cm[city]);	
		}
		
		cm[city] += money;
		mc[cm[city]].insert(city);
	}

	int m, k, day, prev, curr = 0;
	
	cin >> m >> k;
	
	for(int i = 0; i <= k; i++)
	{
		
		prev = curr;
		
		if(i == k)
			day = m;
		else
			cin >> day >> name >> city;
		
		
		curr = day;
		
		it = mc.rbegin();
		
		if(curr != prev && it->s.size() == 1)
			ccnt[*(it->s.begin())] += curr - prev;
		
		if(i < k)
		{
			//вылет из старого города
			ll oldMoney = cm[nc[name]];
			mc[oldMoney].erase(nc[name]);
			
			if(mc[oldMoney].size() == 0)
				mc.erase(oldMoney);
			
			cm[nc[name]] -= nm[name];
			mc[cm[nc[name]]].insert(nc[name]);		
			
			//посадка в новый город
			ll newMoney = cm[city];
			mc[newMoney].erase(city);
			
			if(mc[newMoney].size() == 0)
				mc.erase(newMoney);
				
			cm[city] += nm[name];
			mc[cm[city]].insert(city);
			
			nc[name] = city;
		}
			
	
	}
	
	for (it2 = ccnt.begin(); it2 != ccnt.end(); it2++) 
		cout << it2->f << " "<< it2->s << endl; 
	
   	return 0;		
}

