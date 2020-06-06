#include<bits/stdc++.h>
#include<string>
#include<map>

#define f first 
#define s second
#define pb push_back
#define ll long long

using namespace std;

stack<int> pool;

int main()
{	
	int n, ball, cnt = 1;
	cin >> n;
	pool.push(0);
	
	for(int i = 0; i < n; i++)
	{
		cin >> ball;
		
		while(pool.top() != ball && cnt <= ball)
		{
			pool.push(cnt);
			cnt++;				
		}
		
		if(pool.top() == ball)
			pool.pop();	
		else
		{
			cout << "Cheater";
			return 0;
		}
	}	
	
	cout << "Not a proof";
	
   	return 0;		
}

