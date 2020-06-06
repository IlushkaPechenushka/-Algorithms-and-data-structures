#include<bits/stdc++.h>
#include<string>
//#include<Windows.h>

using namespace std;

const double PI = 3.14159265358979323846;

pair<char, int> a[100002];

void ans(int size, int num)
{
	if(size == 0)
		return;
	
	cout << a[num].first;
	ans(size - 1, a[num].second);	
}

int main()
{
	string s;
	int x, size = 0;
	
	cin >> x >> s;
	
	for(int i = 0; i < s.size(); i++)
	{
		a[i].first = s[i];
		a[i].second = i;
	}
	
	sort(a, a + s.size());
	
//	for(int i = 0; i < s.size(); i++)
//	{
//		cout <<i << " "<< a[i].first <<" "<< a[i].second << endl;
//		
//	}
	
	ans(s.size(), x - 1);
	
	
   	return 0;		
}

