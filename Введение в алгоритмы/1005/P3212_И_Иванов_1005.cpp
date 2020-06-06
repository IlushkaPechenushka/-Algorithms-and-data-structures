#include<bits/stdc++.h>
#include<string>

using namespace std;

const double PI = 3.14159265358979323846;
int mn = 1e9;

int bf(int mass[], int size, int i = 0, int s1 = 0, int s2 = 0) 
{

    if (i == size) 
		mn = min(mn, abs(s1 - s2));
    else {
    	
    	//cout << "first: i = "<< i <<";   s1 = "<< s1 <<";   s2 = "<< s2 <<";" << endl;
        bf(mass, size, i + 1, s1 + mass[i], s2);
        //cout << "second: i = "<< i <<";   s1 = "<< s1 <<";   s2 = "<< s2 <<";" << endl;
		bf(mass, size, i + 1, s1, s2 + mass[i]);
		
    }
    
    return mn;
}

int a[25];

int main()
{
	int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) 
		cin >> a[i];
    
	cout << bf(a, n);


   	return 0;		
}

