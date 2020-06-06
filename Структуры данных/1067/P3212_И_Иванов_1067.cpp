#include<bits/stdc++.h>
#include<string>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

struct Dir {
	map<string, Dir*> dirs;
};

Dir roots[50004];
int cnt = 1;
vector<string> paths[505];

Dir* new_dir(Dir* parent, string child)
{
	auto& in = parent->dirs[child];
	
	if (!in) 
		in = &roots[cnt++];
	cout << cnt << endl;
	return in;
}

void show_tree(Dir* roots, string dist = "")
{
	for (auto root_dir : roots->dirs)
	{
		cout << dist << root_dir.first << endl;
		show_tree(root_dir.s, dist + " ");
	}
}

void split(string path, int num)
{
	string st = "";
		
	for(int j = 0; j < path.size(); j++)
	{
		if(path[j] == '\\')
		{
			paths[num].pb(st);
			st = "";
		}
		else
			st += path[j];
	}
		
	paths[num].pb(st);
}

int main()
{
	int n;
	string str;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> str;
		split(str, i);
	}
	
	for(int i = 0; i < n; i++)
	{
		Dir* dir = &roots[0];
		
		for(int j = 0; j < paths[i].size(); j++)
			dir = new_dir(dir, paths[i][j]);
	}
	
	show_tree(&roots[0]);
	
	return 0;
}
