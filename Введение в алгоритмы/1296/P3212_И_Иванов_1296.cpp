#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
	int n, count = 0, ans = 0, input;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> input;
		
		count += input;
		
		if(count < 0)
			count = 0;
		else
			ans = max(ans, count);
			
	}

	cout << ans; 
	
   	return 0;		
}

