#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;

int ans[10];

int main()
{
	int test, n, k, i = 0;
	cin >> test;
	
	while(test > 0)
	{
		cin >> n >> k;
		
		int div = n / k, big = n % k, small = k - big;
		
		
		ans[i] = div * div * (small - 1) * small / 2 + (div + 1) * div * big * small + (div + 1) * (div + 1) * (big - 1) * big / 2;
		
		i++;
		test--;
	}
	
	for(int j = 0; j < i; j++)
		cout << ans[j] << endl;
	
   	return 0;		
}

