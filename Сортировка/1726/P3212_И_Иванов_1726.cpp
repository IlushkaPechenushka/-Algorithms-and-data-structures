#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;

int x[100005], y[100005];

void qsort(int current[], int l1, int r1) 
{
	
    int mid = current[(l1 + r1) / 2];
    int l = l1, r = r1;
    
    while(l <= r) 
	{
        while (current[l] < mid) 
			l++;
			
        while (current[r] > mid) 
			r--;
			
		if (l > r) break;
		
		swap(current[l++], current[r--]);
    }
    
    if (l1 < r) 
		qsort(current, l1, r);
		
    if (l < r1) 
		qsort(current, l, r1);
}

int main() {
	
	long long n, sum = 0;
    
	cin >> n;
    
    for (long long i = 0; i < n; i++)
		cin >> x[i] >> y[i];
		
    qsort(x, 0, n - 1);
    qsort(y, 0, n - 1);
    
    for (long long i = 1; i < n; i++)
		sum += ((x[i] - x[i - 1]) + (y[i] - y[i - 1])) * i * (n - i) * 2;
		
    cout << sum / (n * (n - 1))<< endl;
    
    return 0;
}
